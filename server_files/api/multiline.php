<?php

require_once '../includes/pass.php';

if ($_SERVER['REQUEST_METHOD'] == 'GET') {
  if (!isset($_GET['entry']) || !isAuth()) {
    die();
  }
  $info = getVaultEntry($_GET['entry']);


  for ($i = 1; $i < count($info); $i++) {
    echo $info[$i];
  }
}
