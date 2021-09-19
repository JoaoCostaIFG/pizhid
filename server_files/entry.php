<?php
include_once 'includes/header.php';

if (!isset($_GET['entry']) || !isAuth())
  header('Location: /');

$info = getVaultEntry($_GET['entry']);
?>

<!-- pass container -->
<br>
<input type="text" value="<?= htmlspecialchars(trim($info[0]), ENT_COMPAT | ENT_HTML401, 'UTF-8') ?>" id="pass-container" readonly="readonly">
<br>

<!-- copy pass -->
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
let txtBox = document.getElementById("pass-container");
// start hidden if there's JS
txtBox.style.position = "absolute";
txtBox.style.left = "-99999px";

function togglepass() {
  let txtBox = document.getElementById("pass-container");
  let toggleBtn = document.getElementById("toggle-btn");
  if (toggleBtn.innerHTML == "Unhide") {
    toggleBtn.innerHTML = "Hide";
    txtBox.style.position = "initial";
  } else {
    toggleBtn.innerHTML = "Unhide";
    txtBox.style.position = "absolute";
  }
}
</script>
<button onclick="togglepass()" id="toggle-btn">Unhide</button>

<pre><?php
for ($i = 1; $i < count($info); $i++) {
  echo htmlspecialchars($info[$i], ENT_COMPAT | ENT_HTML401, 'UTF-8');
}
?></pre>

<?php
include_once 'includes/footer.php';
