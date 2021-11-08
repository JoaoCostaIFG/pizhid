<?php

$auth_file = '/tmp/pizhid.lock';

function vaultList()
{
  $handle = popen("/bin/pizhid-pass nottree", "r");

  if ($handle === false) return array();

  $ret = array();
  while (($buffer = fgets($handle, 4096)) !== false) {
    array_push($ret, $buffer);
  }

  pclose($handle);
  return $ret;
}

function getVaultEntry($entry)
{
  $e = escapeshellarg($entry);
  $handle = popen('/bin/pizhid-pass ' . $e, "r");
  if ($handle === false) return array();

  $ret = array();
  while (($buffer = fgets($handle)) !== false) {
    array_push($ret, $buffer);
  }

  pclose($handle);
  return $ret;
}

function getKeyId()
{
  $id_handle = popen('/bin/pizhid-pass getkeyid', 'r') or die();
  $id = trim(fgets($id_handle, 4096));
  pclose($id_handle);
  return $id;
}

function getKeyGrip()
{
  $grip_handle = popen('/bin/pizhid-pass getkeygrip', 'r') or die();
  $grip = trim(fgets($grip_handle, 4096));
  pclose($grip_handle);
  return $grip;
}

function login($password)
{
  if (checkPassword($password)) { // correct password
    // cache password in agent
    $handle = popen('/usr/lib/gnupg2/gpg-preset-passphrase --preset ' . getKeyGrip(), 'w') or die("gpg-preset-passphrase");
    fwrite($handle, $password);
    pclose($handle);

    // create a lock file
    global $auth_file;
    touch($auth_file);
    chmod($auth_file, 0600);

    return true;
  } else {
    return false;
  }
}

function logout()
{
  // remove lock
  global $auth_file;
  unlink($auth_file);
  // forget key
  $handle = popen('/usr/lib/gnupg2/gpg-preset-passphrase --forget ' . getKeyGrip(), 'r') or die("logout");
  pclose($handle);
}

function checkPassword($password)
{
  $handle = popen('gpg --batch --passphrase-fd 0 --pinentry-mode loopback -o /dev/null --local-user ' . getKeyId() . ' -as -', 'w') or die("auth check");
  fwrite($handle, $password);
  $exit_code = pclose($handle);
  if ($exit_code === 0) return true;
  else return false;
}

function isAuth()
{
  global $auth_file;
  $owner = fileowner($auth_file);
  if ($owner === posix_getpwnam(get_current_user())['uid']) return true;
  else return false;
}
