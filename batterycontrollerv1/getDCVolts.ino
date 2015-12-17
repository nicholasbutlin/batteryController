/*
Get DC voltage from a voltage divider circuit, using Aref @ 4.096V
*/
float getDCVolts(int pin)
{
	// Measure and set cr and zr as per calibration instructions.
  int zr = 0; //zero reading
  int cr = 0; //calibration reading
  //formula from readme
  return (4.096 * (analogRead(pin) - zr)/(cr - zr));
}
