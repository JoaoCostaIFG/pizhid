#!/bin/sh

sudo cp ~/pizhid_src/pi_files/etc/dhcpcd.conf /etc/dhcpcd.conf

sudo rsync ~/pizhid_src/pi_files/etc/systemd/system/dhcpcd.service.d/ /etc/systemd/system/dhcpcd.service.d/
