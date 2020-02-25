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

## Update

1. Soft unlock wifi

```sh
sudo rfkill unlock wifi
```

2. config network at: /etc/wpa_supplicant/wpa_supplicant.conf  
   e.g.:

```sh
country=pt
update_config=1
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev

network={
  scan_ssid=1
  ssid=""
  psk=""
}
```

3. connect raspberry pi to power (no data to prevent it prioritizing the usb network).

4. ssh through wifi and do stuff (can also connect ethernet).

5. (not tested) add the following to /etc/rc.local:

```sh
sudo apt-get update
sudo apt-get upgrade
sudo rfkill block all
```
