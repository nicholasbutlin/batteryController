# connectbattery.local
getting started:

setup the board,

http://www.seeedstudio.com/wiki/Seeeduino_Cloud

https://www.arduino.cc/en/Guide/ArduinoYun

## Basic access
https://connectbattery.local (e.g. as named)

ssh root@connectbattery.local

make change to pin
curl https://connectbattery.local/arduino/digital/12


## Watchdog setup

make sure the wlan is up, if not, restart or reboot

on a fresh Yun / OpenWRT, first start cron, and enable on boot

```
/etc/init.d/cron start
/etc/init.d/cron enable
```

put watchdog in root
```
crontab -e
* * * * * /root/watchdog.sh
```

make executable
```
chmod +x watchdog.sh
```
