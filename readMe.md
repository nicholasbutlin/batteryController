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

Aim: Measure voltage of 20 - 30v approx

### Accuracy
ADC specification ref AtMega32u4[ http://www.atmel.com/devices/ATMEGA2560.aspx?tab=documents ] data sheet.

http://www.atmel.com/Images/doc4278.pdf

Voltage Divider circuit:
to measure 24v +- 5v
R1:R2 :: 4:20
such that 1/R1 + 1/R2 = 10k

```
10-bits  (0 - 1023 decimal)
Integral Non-linearity ± 1 LSB
Absolute Accuracy  ± 2 LSB
Conversion Time 13 - 260 µs
Rain = 100M
Rref = 32k
output impedance optimised at 10k
```
Voltage accuracy of  ± 2 LSB
--> 4 / 1024 i.e. 0.25%.

LM4040DIZ-4.1/NOPB voltage reference diode, 100 uA  > I <15mA 4.096V ± 0.2%.
Calcs for accuracy using USB power supply
Rref current = 4.096V / 32k =  0.128mA
Diode current = 0.4mA
Min current = 0.4 + 0.128 = 0.528mA.
Max current: 5.25  - 4.096 / 0.560k = 2.16 mA
(R = 4.40 - 4.096 / 0.528 = 560 ohms.)

calibration:
connect circuit to 0v --> the zeroreading is the analogpin() : zr

connect circuit to 4.096 --> the calibrated reading : cr
maxvolts = 4.096 * 1023 / (cr - zr)
```
int zeroreading = zr;
float maxvolts = maxvolts as calculated;
// read the input on analog pin 0:
int sensorValue = analogRead(A0);
//correct the zero offset
sensorValue= sensorValue - zeroreading;
// Convert the analog reading to voltage
float voltage = sensorValue * (maxvolts / 1023.0);
```
and the result is a reading that is correct to 0.25%
