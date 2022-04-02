#!/bin/sh
### Install and enable DNSMasq to serve ips on interfaces usb0 and usb1.

sudo apt-get install dnsmasq
sudo systemctl disable --now dnsmasq

sudo mv /etc/init.d/dnsmasq /etc/init.d/dnsmasq.initd
sudo sed /lib/systemd/system/dnsmasq.service -i -e "s/Requires=network.target/Requires=network.target sys-subsystem-net-devices-usb0.device{% if use_libComposite | default(true) | bool %} sys-subsystem-net-devices-usb1.device{% endif %}/" -e "s~/etc/init.d/dnsmasq ~/etc/init.d/dnsmasq.initd ~g"

sudo systemctl daemon-reload
sudo systemctl enable --now dnsmasq.service
