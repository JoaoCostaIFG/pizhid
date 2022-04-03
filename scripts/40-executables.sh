#!/bin/sh
### Scripts and binaries needed.

# scripts
chmod +x ~/pizhid_src/pi_files/usr/local/bin/*
sudo cp ~/pizhid_src/pi_files/usr/local/bin/* /usr/local/bin/

# keyboard
cd ~/pizhid_src/keyboard || exit 1
make
sudo mv ~/pizhid_src/keyboard/pizhid-keyboard /usr/local/bin/
