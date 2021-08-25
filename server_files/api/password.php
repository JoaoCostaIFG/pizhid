<?php

if ($_SERVER['REQUEST_METHOD'] == 'GET') {
  if (!isset($_GET['entry']) || !isAuth()) {
    die();
  }
  $info = getVaultEntry($_GET['entry']);

  if (isset($_GET['clip'])) {
    # print password raw
    echo $info[0];
  } else {
    $handle = popen('/bin/sudo /bin/pizhid-keyboard 1', "w") or die();
    fwrite($handle, $info[0]);
    pclose($handle);
    echo $info[1];
  }
}
