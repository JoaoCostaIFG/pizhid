<?php

$authfile = "/pizhid-login/pass";

function vaultList()
{
  $handle = popen("/bin/find ~/.password-store -type f ! -path ~/.password-store/.gpg-id -printf '%P\n' |
    cut -f 1 -d '.' | sort", "r");

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
  while (($buffer = fgets($handle, 4096)) !== false) {
    array_push($ret, $buffer);
  }

  pclose($handle);
  return $ret;
}

function login($password)
{
  global $authfile;

  if (password_verify($password, 'hash')) {
    $f = fopen($authfile, "w");
    fwrite($f, $password);
    fclose($f);
    chmod($authfile, 0600);
    return true;
  } else {
    return false;
  }
}

function logout()
{
  global $authfile;
  unlink($authfile);
}

function isAuth()
{
  global $authfile;
  return file_exists($authfile);
}
