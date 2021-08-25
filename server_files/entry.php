<?php
include_once 'includes/header.php';

if (!isset($_GET['entry']) || !isAuth())
  header('Location: /');

$info = getVaultEntry($_GET['entry']);
?>

<pre><?php
foreach ($info as $i) {
  echo $i;
}
?></pre>

<?php
include_once 'includes/footer.php';
