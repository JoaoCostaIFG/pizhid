<?php

require_once '../includes/pass.php';

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
  if (!isset($_POST['password'])) {
    die('failure');
  }
  $pass = $_POST['password'];

  if (login($pass)) die('authenticated');
  else die('failure');
} else if ($_SERVER['REQUEST_METHOD'] == 'GET') {
  if (isAuth()) die('authenticated');
  else die('failure');
}
