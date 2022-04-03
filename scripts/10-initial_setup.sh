#!/bin/sh
### Update and upgrade (apt-get). Setup hostname and stuff.

sudo apt-get update
sudo apt-get upgrade

rsync -r . pizhid:/home/pizhid/pizhid_src/
