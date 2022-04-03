#!/bin/sh

sudo touch /var/lib/dhcp/dhcpd@usb0.leases
sudo touch /var/lib/dhcp/dhcpd@usb1.leases

sudo systemctl enable dhcpd4@usb0.service
sudo systemctl enable dhcpd4@usb1.service
