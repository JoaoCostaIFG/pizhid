# PizHid

This is the code used on my personal _secrets manager_. As it basically was the
platform where I started learning concepts about Raspberry pi's (and friends),
it has had several iterations. Nowadays, it uses
[VaultWarden](https://github.com/dani-garcia/vaultwarden), a lighter-weight
[BitWarden](https://bitwarden.com) implementation, so it can be interacted with
using the many BitWarden clients/frontends.

Previously, it was based on [pass](https://www.passwordstore.org). It had a
minimal web interface (mainly for use with Windows devices) and an API (which
powered a small Linux application). To see more about this older version,
checkout the `pass` git tag/release.

![PizHid](./icon.png)

## Usage and functionality details

It runs [VaultWarden](https://github.com/dani-garcia/vaultwarden). The device
offers both wired (USB ethernet) and wireless (access point) connection to
access the web interface.

A connection is automatically established when connecting the device to another
device and an IP is leased. On Linux, the IP of PizHid is `10.77.77.77`, on
Windows it is `10.77.78.77`, and on the Access Point it is `10.77.79.77`. If the
client OS support AVAHI, the PizHid can be reached at `pizhid.local`.

### Physical buttons

There are 2 physical buttons present on the device. One powers the device
on/off, and the other toggles the access point.

## Initial setup

- Set hostname to `pizhid`;
- Enable SSH;
- Enable SSH public-key authentication;
- Change default user to `pizhid`
- Enable network;
- Set locale to `Europe/Lisbon`/`pt`;
- _Skip first-run wizard_.

## Network

The web server is available in 3 interfaces: `usb0` (Linux wired), `usb1`
(Windows wired), `uap0` (Wireless). IPs are automatically attributed to clients
via a DHCP server.

- `usb0` - _pizhid_ resides at 10.77.77.77/24 and serves IPs in the range
  [10.77.77.80, 10.77.77.99];
- `usb1` - _pizhid_ resides at 10.77.78.77/24 and serves IPs in the range
  [10.77.78.80, 10.77.78.99].
- `uap0` - _pizhid_ resides at 10.77.79.77/24 and serves IPs in the range
  [10.77.79.80, 10.77.79.99].

**Note:** _pizhid_ is also available as `pizhid.local` with
[AVAHI](https://avahi.org).

### Access Point

The Access Point uses [hostapd](https://w1.fi/hostapd/). The device only has 1
wlan interface. As such, it creates a virtual interface for the Access Point
added to the `wlan0` physical device (see
[RasAP Docs AP-STA mode](https://docs.raspap.com/ap-sta/)).

These 2 are bridged, so clients connected to the Access Point can access the
Internet through IPv4 forwarding by PizHid. Clients can only access the Internet
through PizHid when connected to the Access Point, because usually devices can
only connected to 1 wireless device at a time, so it is not
necessary/deterimental for wired connections.

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

### _More_ memory with zram

Just read this post (it is great):
[How to Squeeze 50% More Memory Out of Your Raspberry Pi with zram](https://ikarus.sg/using-zram-to-get-more-out-of-your-raspberry-pi/).

## Web server

The server runs nginx to serve the SSL certificate and reverse proxy to
VaultWarden. The certificate resides in the `/etc/ssl/certs` directory and the
key on the `/etc/ssl/private` directory. Set these according to your needs.

## Important notes on using this

- There is Ansible notebook, but it **shouldn't be used**:
  - I didn't test it
  - I didn't build it in a way that could be used more than once on the same
    device (idempotency)
  - It is just a way for me to organize the steps
- BitWarden clients need HTTPS, so you need SSL certificates:
  - These can be self-signed, but they are harder to use in some clients
- The hostapd config contains the Access Point's password in plaintext
  - Just set a password for your device
- The `boot/cmdline.txt` file contains a partition UUID and stuff like that
  needs to be changed when applied to other devices
- There are probably better/lighter-weight alternatives to nginx for this use
  case
- VaultWarden needs an admin token:
  - Generate it using `openssl rand -base64 48`
  - Don't forget to pass it when starting the docker container
- VaultWarden data is stored using a bind-mount at `/bw-data`

## Thanks

### Cool software

Software that made this possible.

- [Log2Ram](https://github.com/azlux/log2ram) - `/var/log` in a **tmpfs**
- [Zram-swap config](https://github.com/StuartIanNaylor/zram-swap-config)
- [DHCPCD5](https://roy.marples.name/projects/dhcpcd)
- [ISC DHCP](https://www.isc.org/dhcp)
- [hostapd](https://w1.fi/hostapd)
- [Nginx](https://nginx.org/en)
- [VaultWarden](https://github.com/dani-garcia/vaultwarden)

### Cool websites and posts

- [Composite USB Gadgets on the Raspberry Pi Zero](https://www.isticktoit.net/?p=1383)
- [Arch wiki tmpfs](https://wiki.archlinux.org/title/Tmpfs)
- [Linux USB gadget configured through configfs](https://www.kernel.org/doc/Documentation/usb/gadget_configfs.txt)
- [Dynamic MOTD on Debian/Ubuntu](https://ownyourbits.com/2017/04/05/customize-your-motd-login-message-in-debian-and-ubuntu/)
- [Raspberry Pi Docs](https://www.raspberrypi.org/documentation/computers/configuration.html)
- [Building a WiFi Enabled USB Rubber Ducky with a Raspberry Pi 0 w](https://www.aidanwoods.com/blog/building-a-wifi-enabled-usb-rubber-ducky/)
- [Extend The Lifespan of Your Raspberry Pi's SD Card with log2ram](https://ikarus.sg/extend-sd-card-lifespan-with-log2ram/)
- [How to Squeeze 50% More Memory Out of Your Raspberry Pi with zram](https://ikarus.sg/using-zram-to-get-more-out-of-your-raspberry-pi/)
- [Libcomposite USB gadget example](https://github.com/ev3dev/ev3-systemd/blob/ev3dev-jessie/scripts/ev3-usb.sh)
- [Post-Config of a RaspberryPi Zero W as an OTG-USB Gadget for off-device computing](https://jon.sprig.gs/blog/post/2243)
- [RasAP Docs AP-STA mode](https://docs.raspap.com/ap-sta/)
- [Creating Wireless Router using Raspberry Pi Zero W](https://scribles.net/creating-wireless-router-using-raspberry-pi-zero-w/)
- [Hostapd config file](https://w1.fi/cgit/hostap/plain/hostapd/hostapd.conf)
- [BYOPM – Bring Your Own Password Manager](https://novamostra.com/2022/10/23/byopm/)

## License

I don't know. I don't care. I'm not responsible for anything.
