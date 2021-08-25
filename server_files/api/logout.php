<?php

if ($_SERVER['REQUEST_METHOD'] == 'GET') {
  unlink("/pizhid-login/pass");
}
