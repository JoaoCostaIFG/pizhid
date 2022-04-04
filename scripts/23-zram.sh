#!/bin/sh
### Activate zram.

cd ~/pizhid_src/zram-swap-config/ || exit 1
chmod +x install.sh
sudo ./install.sh

sudo cp ~/pizhid_src/pi_files/etc/zram-swap-config.conf /etc/zram-swap-config.conf
