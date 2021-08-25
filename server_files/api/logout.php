<?php

require_once 'pass.php';

if ($_SERVER['REQUEST_METHOD'] == 'GET') {
  logout();
}
