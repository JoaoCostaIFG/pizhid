<?php

require_once '../includes/pass.php';

function goHome()
{
  header('Location: /');
  die();
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
  if (!isset($_POST['password'])) goHome();
  $pass = $_POST['password'];
  login($pass);
  goHome();
} else {
  goHome();
}
