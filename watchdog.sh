#!/bin/sh

ping -c5 www.google.com

if [ $? -eq 0 ]; then
    echo "ok"
else
    #TODO: softer
    #ifdown wlan0; ifup wlan0
    reboot
fi
