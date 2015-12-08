# connectbattery.local
getting started:

http://www.seeedstudio.com/wiki/Seeeduino_Cloud

https://www.arduino.cc/en/Guide/ArduinoYun

## Basic pin controls
curl localhost/arduino/digital/12


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
