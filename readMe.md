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
## Temp Measurement
### Accuracy

## Voltage Measurement

### Voltage Divider circuit ~ 24v

Calcs for 4V required drop across analogpin, data sheet [AtMega32u4]( http://www.atmel.com/devices/ATMEGA2560.aspx?tab=documents):
```
Output impedance optimised at 10k  (as per datasheet)
1/R1 + 1/R2 ~= 10k
4 = 24 -20
R1:R2 :: 4:20 :: 10:50
R1 = 10k
R2 = 50k
1/(1/R1 + 1/R2) = 8.33k
```
### Calibration process
```
connect circuit to 0v, read analog pin --> zero reading: zr
connect circuit to 4.096, read analog pin -->  calibration reading: cr
maxvolts = 4.096 * 1023 / (cr - zr)
actual read = (Vread - zr) * maxvolts / 1023
--> actual read = 4.096 * (Vread - zr)/(cr - zr)

```
thanks to : http://www.skillbank.co.uk/arduino/calibrate.htm

see code for usage

### Accuracy Calculations
ADC Voltage accuracy of = 0.25%.

Calcs for ADC Accuracy, data sheet [AtMega32u4]( http://www.atmel.com/devices/ATMEGA2560.aspx?tab=documents):
```
10-bit ADC (0 - 1023 decimal), Conversion Time 13 - 260 µs
Integral Non-linearity ± 1 LSB
Absolute Accuracy  ± 2 LSB
± 2 LSB  == 4 / 1024 == 0.25%
```
Voltage reference diode, LM4040DIZ-4.1/NOPB: 4.096V ± 0.2%.

Calcs for Diode accuracy using USB power supply:
```
Current parameters: 100uA < I < 15mA
Aref R = 32k
Aref I = 4.096V / 32k =  0.128mA
Diode current = 0.4mA
Min current = 0.4 + 0.128 = 0.528mA.
USB Min Voltage = 4.40
R3 = 4.40 - 4.096 / 0.528 = 560 ohms
Max current: 5.25  - 4.096 / 0.560k = 2.16 mA
```
