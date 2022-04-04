#!/bin/sh
### Copy web app files.

sudo rsync -r --delete ~/pizhid_src/server_files/ /var/www/html/
