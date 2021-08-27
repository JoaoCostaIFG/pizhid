<?php

require_once '../includes/pass.php';

if ($_SERVER['REQUEST_METHOD'] == 'GET') {
  logout();
}
