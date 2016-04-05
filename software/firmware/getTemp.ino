/*
TEMPERATURE SENSOR

  Use the "serial monitor" window to read a temperature sensor.

Hardware connections:

  TMP36
  Connect the 5V pin to 5 Volts (5V).
  Connect the SIGNAL pin to ANALOG pin 0.
  Connect the GND pin to ground (GND).

*/
float getTemp(int pin)
{
	//formula from TMP36 datasheet
  return ((analogRead(pin) * (5.0 / 1023.0)) - 0.5 * 100.0);
}
