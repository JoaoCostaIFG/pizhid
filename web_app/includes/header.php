<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <title>PizHid</title>
  <link rel="icon" href="/favicon.ico">
</head>

<body>
  <h1><a href="/">PizHid</a></h1>
  <?php require_once 'pass.php';
  if (isAuth()) { ?>
    <a href="/actions/logout.php">Logout</a>
  <?php } ?>
