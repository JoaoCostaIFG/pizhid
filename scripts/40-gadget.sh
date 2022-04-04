#!/bin/sh
### Setup USB gadget.

sudo cp ~/pizhid_src/pi_files/etc/systemd/system/pizhid-gadget.service /etc/systemd/system/pizhid-gadget.service
sudo systemctl daemon-reload
sudo systemctl enable pizhid-gadget.service
