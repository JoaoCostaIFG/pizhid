<?php
include_once 'includes/header.php';

if (!isset($_GET['entry']) || !isAuth())
  header('Location: /');

$info = getVaultEntry($_GET['entry']);
?>

<br>
<!-- pass -->
<input type="text" value="<?= $info[0] ?>" id="pass-container" readonly="readonly">

<script>
function copypass() {
  // insert pass into clipboard
  let txtBox = document.getElementById("pass-container");
  txtBox.focus();
  txtBox.select();
  let succ = document.execCommand('copy');
} 
</script>
<button onclick="copypass()">Copy pass</button>

<script>

</script>

<pre><?php
for ($i = 1; $i < count($info); $i++) {
  echo $info[$i];
}
?></pre>

<?php
include_once 'includes/footer.php';
