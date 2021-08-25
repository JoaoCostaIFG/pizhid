<?php

require_once '../includes/pass.php';

if ($_SERVER['REQUEST_METHOD'] == 'GET') {
  if (!isAuth()) die();

  foreach (vaultList() as $entry) {
    echo $entry;
  }
}
