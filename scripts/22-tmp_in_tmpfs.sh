#!/bin/sh
### Add entry to fstab to mount /tmp in a tmpfs.

echo "tmpfs  /tmp  tmpfs  rw,nodev,nosuid,size=40M  0  0" | sudo tee -a /etc/fstab
