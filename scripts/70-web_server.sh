#!/bin/sh
### Install and enable nginx, php-fpm, and pass to serve webapp.

# install
sudo apt-get install nginx php8.0 php8.0-fpm pass

# config
# nginx
sudo cp ~/pizhid_src/pi_files/etc/nginx/sites-available/default /etc/nginx/sites-available/default
sudo cp ~/pizhid_src/pi_files/etc/nginx/nginx.conf /etc/nginx/nginx.conf
# php
sudo cp ~/pizhid_src/pi_files/etc/php/8.0/fpm/pool.d/www.conf /etc/php/8.0/fpm/pool.d/www.conf

# services
sudo systemctl enable php8.0-fpm
sudo systemctl enable nginx
