#!/bin/sh

# install
sudo apt-get install isc-dhcp-server

# config
sudo cp ~/pizhid_src/pi_files/etc/dhcp/dhcpd.conf /etc/dhcp/dhcpd.conf

sudo touch /var/lib/dhcp/dhcpd.leases

# service
sudo cp ~/pizhid_src/pi_files/etc/systemd/system/dhcpd4.service /etc/systemd/system/dhcpd4.service
sudo systemctl daemon-reload
sudo systemctl enable dhcpd4.service
