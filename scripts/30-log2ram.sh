#!/bin/sh
### Install and enable log2ram.

echo "deb [signed-by=/usr/share/keyrings/azlux-archive-keyring.gpg] http://packages.azlux.fr/debian/ bullseye main" | sudo tee /etc/apt/sources.list.d/azlux.list
sudo wget -O /usr/share/keyrings/azlux-archive-keyring.gpg  https://azlux.fr/repo.gpg
sudo apt-get update
sudo apt-get -y install log2ram

# service
sudo cp ~/pizhid_src/pi_files/etc/log2ram.conf /etc/log2ram.conf
sudo systemctl enable log2ram