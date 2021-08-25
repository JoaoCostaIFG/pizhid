<?php

require_once '../includes/pass.php';

function goHome()
{
  header('Location: /');
  die();
}

if ($_SERVER['REQUEST_METHOD'] == 'GET') {
  logout();
  goHome();
} else {
  goHome();
}
