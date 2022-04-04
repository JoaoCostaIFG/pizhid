#!/bin/sh
### Disable swap.

# disable
sudo dphys-swapfile swapoff
sudo dphys-swapfile uninstall
# uninstall
sudo update-rc.d dphys-swapfile remove
sudo apt-get -y purge dphys-swapfile
