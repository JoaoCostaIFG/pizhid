<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <title>PizHid</title>
</head>

<body>
  <h1><a href="/">PizHid</a></h1>
  <?php
  require_once 'pass.php';

  if (isAuth()) {
    echo 'Logout';
  } else {
    echo 'Login';
  }
  ?>
