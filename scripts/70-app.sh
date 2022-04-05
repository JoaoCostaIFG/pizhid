#!/bin/sh
### Copy web app files.

sudo rsync -r --delete ~/pizhid_src/web_app/ /var/www/html/
