# PizHid

This is the code used on my personal secrets manager based on
[pass](https://www.passwordstore.org/). It can be interacted with both from a
web interface and an API (which powers a small Linux application).

## Usage and functionality details

The web interface uses PHP to interact with the pass application (back-end).
This is all hosted on a raspberry pi zero which uses USB-OTG to function as a
web server, DHCP server, and keyboard. When using the API, passwords can be
typed automatically by the device.

A connection is automatically established when connecting the device to another
device and an IP is leased. On Linux, the IP of PizHid is `10.77.77.77` and on
Windows it is `10.77.78.77`. If the client OS support AVAHI, the PizHid can be
reached at `pizhid.local`.

On the web interface, users can use a text-box to fuzzy find what they're
looking for quickly (uses JavaScript so no submits/page reloads are needed).

The authentication is performed using a master password. The authentication is
global, as in, when authenticated from the web interface, API, or terminal
commands, the user stays authenticated until he powers off the device or
manually signs out.

All these functionalities are only available through the Ethernet connection
provided by the USB-OTG capabilities of the device.

### Physical buttons

There are 2 physical buttons present on the device. One powers the device
on/off, and the other toggles WiFi connectivity.

## Network

The web server is available in 2 interfaces: `usb0` and `usb1`. IPs are
automatically attributed to clients via a DHCP server (provided by
[Dnsmasq](https://dnsmasq.org/)).

- DHCPCD5 service used for internet access;

- Dnsmasq is the DHCP server used to serve IPs to the clients (host computer).
  To correct the systemd dnsmasq problem, see:
  [blog post](https://jon.sprig.gs/blog/post/2243) and
  [script](https://github.com/JonTheNiceGuy/rpirouter/blob/994891e4fa0fd228b2bada7d7c275ac4464040b5/roles/jontheniceguy.rpirouter/templates/package_postinstall.sh.j2).

[Dnsmasq](./scripts/dnsmasq.sh)

### Network details

- `usb0` - _pizhid_ resides at 10.77.77.77/24 and server IPs in the range
  [10.77.77.78, 10.77.77.99];
- `usb1` - _pizhid_ resides at 10.77.78.77/24 and server IPs in the range
  [10.77.78.78, 10.77.78.99].

**Note:** _pizhid_ is also available as `pizhid.local` with
[AVAHI](https://avahi.org).

## SD card wear

### Swap

- Swap is disabled for faster boot times and SD card preservation. There were no
  benefits since the device memory usage is extremely low:

[Disable swap](./scripts/disable_swap.sh)

### Log2Ram

- Logging to the sd card causes useless wear;
- [Log2Ram](https://github.com/azlux/log2ram) is used to reduce this wear;
- Install:

[Install log2ram](./scripts/install_log2ram.sh)

- Copy the config file at `/etc/log2ram.conf`.

### /tmp is a tmpfs

An entry in _fstab_ was added for `/tmp` to be a **tmpfs** (40MB).

[Tmp in tmpfs](./scripts/tmp_in_tmpfs.sh)

## Web server

- The server runs nginx and servers php pages (using php-fpm);
- Install:

[Web server](./scripts/web_server.sh)

- Copy the nginx and php config files;
- `pass` is needed for the password store at `/home/pizhid/.password-store`.

## Thanks

### Important packages (providing core functionality)

- [Log2Ram](https://github.com/azlux/log2ram) - `/var/log` in a **tmpfs**;
- [Dnsmasq](https://dnsmasq.org/) - DHCP server.
  [Arch linux wiki entry](https://wiki.archlinux.org/title/Dnsmasq);
- [Zram-swap config](https://github.com/StuartIanNaylor/zram-swap-config);
- Nginx - Web server.
- PHP - Web app back-end.
- PHP-fpm - Use PHP with Nginx.
- pass - App managing all the secrets.
- GnuPG - Cryptography utilities.

### Cool websites and posts

- [Composite USB Gadgets on the Raspberry Pi Zero](https://www.isticktoit.net/?p=1383)
- [Arch wiki tmpfs](https://wiki.archlinux.org/title/Tmpfs)
- [Linux USB gadget configured through configfs](https://www.kernel.org/doc/Documentation/usb/gadget_configfs.txt)
- [Dynamic MOTD on Debian/Ubuntu](https://ownyourbits.com/2017/04/05/customize-your-motd-login-message-in-debian-and-ubuntu/)
- [Raspberry Pi Docs](https://www.raspberrypi.org/documentation/computers/configuration.html)
- [Building a WiFi Enabled USB Rubber Ducky with a Raspberry Pi 0 w](https://www.aidanwoods.com/blog/building-a-wifi-enabled-usb-rubber-ducky/)
- [gpg-preset-passphrase man](https://docs.oracle.com/cd/E36784_01/html/E36870/gpg-preset-passphrase-1.html)

#### Best

- [Extend The Lifespan of Your Raspberry Pi's SD Card with log2ram](https://ikarus.sg/extend-sd-card-lifespan-with-log2ram/)
- [How to Squeeze 50% More Memory Out of Your Raspberry Pi with zram](https://ikarus.sg/using-zram-to-get-more-out-of-your-raspberry-pi/)
- [Libcomposite USB gadget example](https://github.com/ev3dev/ev3-systemd/blob/ev3dev-jessie/scripts/ev3-usb.sh)
- [Post-Config of a RaspberryPi Zero W as an OTG-USB Gadget for off-device computing](https://jon.sprig.gs/blog/post/2243)

## License

I don't know. I don't care. I'm not responsible for anything.
