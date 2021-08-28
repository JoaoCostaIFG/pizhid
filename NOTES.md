# piz_hid NOTES

## Disabled bluetooth

```sh
sudo systemctl disable hciuart.service
```

## Disable swap

```sh
sudo dphys-swapfile swapoff
sudo dphys-swapfile uninstall
sudo update-rc.d dphys-swapfile remove
s`udo apt purge dphys-swapfile
```

## Timeout keyboard layout setup service

`systemctl edit keyboard-setup.service`  
[Service]  
TimeoutStartSec=1

## No need for normal login capacity

`sudo systemctl mask systemd-logind.service

## Disable HDMI on boot (/etc/rc.local)

/usr/bin/tvservice -o
