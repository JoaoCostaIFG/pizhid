#!/bin/sh
### Setup physical device buttons.

sudo cp ~/pizhid_src/pi_files/etc/systemd/system/pizhid-button.service /etc/systemd/system/pizhid-button.service

sudo systemctl daemon-reload
sudo systemctl enable pizhid-button.service
