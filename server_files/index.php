<?php
include_once 'includes/header.php';
?>

<?php if (isAuth()) { ?>
  <br><br>
  <label for="search">Search: </label>
  <input type="text" id="search" name="search">
  <ul>
    <?php foreach (vaultList() as $entry) { ?>
      <li class="entry"><a href="/entry.php?entry=<?= $entry ?>"><?= $entry ?></li>
    <?php } ?>
  </ul>

  <script>
    // Fuzzy finder. source: https://stackoverflow.com/a/15252131
    String.prototype.fuzzy = function(s) {
      let hay = this.toLowerCase(),
        i = 0,
        n = -1,
        l;
      s = s.toLowerCase();
      for (; l = s[i++];) {
        if (!~(n = hay.indexOf(l, n + 1)))
          return false;
      }
      return true;
    };

    let search_bar = document.getElementById("search");
    search_bar.value = ""; // clear bar content
    let entries = document.getElementsByClassName("entry"); // get all entries
    search_bar.addEventListener("input", function(e) {
      // show entries matching the fuzzy engine
      for (entry of entries) {
        if (entry.innerText.fuzzy(search_bar.value)) {
          entry.style.removeProperty("display");
        } else {
          entry.style.display = "none";
        }
      }
    });
  </script>
<?php } else { ?>
  <form method="POST" action="/actions/login.php">
    <label for="password">Password:</label><br>
    <input type="password" id="password" name="password"><br><br>
    <input type="submit" value="Login">
  </form>
<?php } ?>

<?php
include_once 'includes/footer.php';
