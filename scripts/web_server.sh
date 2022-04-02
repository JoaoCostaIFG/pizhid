#!/bin/sh
### Install and enable nginx, php-fpm, and pass to serve webapp.

sudo apt-get install nginx php8.0 php8.0-fpm pass
sudo systemctl enable --now php8.0-fpm
