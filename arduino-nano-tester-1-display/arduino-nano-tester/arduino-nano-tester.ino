// Source code is from: http://embedded-lab.com/blog/introducing-a-new-serial-spi-8-digit-seven-segment-led-display-module-using-max7219/

#include "LedControl.h"
// Arduino Pin 7 to DIN, 6 to Clk, 5 to LOAD, no.of devices is 1
LedControl lc=LedControl(7,6,5,1);
void setup()
{
 // Initialize the MAX7219 device
  lc.shutdown(0,false);   // Enable display
  lc.setIntensity(0,15);  // Set brightness level (0 is min, 15 is max)
  lc.clearDisplay(0);     // Clear display register
}
void loop()
{
  for(int i=0; i < 8; i++){
   lc.setDigit(0,i,i+1,false); // Decimal point disabled
  }  
  delay(3000);
}
