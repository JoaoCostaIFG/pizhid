#!/bin/sh

sudo cp ~/pizhid_src/pi_files/etc/dhcpcd.conf /etc/dhcpcd.conf

sudo cp ~/pizhid_src/pi_files/etc/systemd/system/dhcpcd.service.d/no-wait.conf /etc/systemd/system/dhcpcd.service.d/
