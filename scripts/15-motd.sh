#!/bin/sh
### Setup custom message of the day ("motd").

sudo cp ~/pizhid_src/pi_files/etc/motd /etc/motd

sudo rm ~/pizhid_src/pi_files/etc/update-motd.d/*
sudo cp -r ~/pizhid_src/pi_files/etc/update-motd.d/* /etc/update-motd.d/
