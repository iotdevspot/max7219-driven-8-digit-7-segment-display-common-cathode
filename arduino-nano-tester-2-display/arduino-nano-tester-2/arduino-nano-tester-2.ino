// Source code is from: http://embedded-lab.com/blog/introducing-a-new-serial-spi-8-digit-seven-segment-led-display-module-using-max7219/

#include "LedControl.h"
// Pin 7 to Data In, 6 to Clk, 5 to LOAD, number of devices is 3
LedControl lc=LedControl(7,6,5,2);
void setup()
{
  // Initialize the 2 MAX7219 devices
  for(int k=0; k<2; k++){
    lc.shutdown(k,false);  // Enable display
    lc.setIntensity(k,15); // Set brightness level (0 is min, 15 is max)
    lc.clearDisplay(k);    // Clear display register
  }
}
void loop()
{
  int count = 0;
  for(int j=0; j<2; j++){
    for(int i=0; i<8; i++){
     lc.setDigit(j,i,count, false);  // Decimal point disabled
     count++;
     if(count == 16)
      count=0;
    }  
    delay(1000);
  }
}
