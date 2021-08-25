<?php
include_once 'includes/header.php';
?>

<?php if (isAuth()) { ?>
<ul>
  <?php foreach (vaultList() as $entry) { ?>
    <li><a href="/entry.php?entry=<?= $entry ?>"><?= $entry ?></li>
  <?php } ?>
</ul>
<?php } else { ?>
<p>Log in needed</p>
<?php } ?>

<?php
include_once 'includes/footer.php';
