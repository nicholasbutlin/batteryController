# connectbattery.local
getting started: 
http://www.seeedstudio.com/wiki/Seeeduino_Cloud
https://www.arduino.cc/en/Guide/ArduinoYun

## from ssh
curl localhost/arduino/digital/12


## watchdog setup

make sure the wlan is up, if not, restart or reboot

on a fresh Yun / OpenWRT, first start cron, and enable on boot

```
/etc/init.d/cron start
/etc/init.d/cron enable
```

put watchdog in root
```
crontab -e
chmod +x watchdog.sh
* * * * * /root/watchdog.sh
```
