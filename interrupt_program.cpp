/*
This program will illustrate a simple interrupt program
*/

#include "mbed.h"

// Global Variable
unsigned short counter =0;  // set global variable counter to 0

Ticker colour_change;
DigitalOut red(LED1);       // red is set to red led
DigitalOut green(LED2);     // green is green led
DigitalOut blue(LED3);      // blue is set to blue led
DigitalIn RIGHT(SW2);       // right pushbutton

void countmein(void)        // interrupt service routine
{
    counter++;              // add 1 to counter variable
}

int main (void)
{ 
   colour_change.attach(&countmein,2);
   for(;;)
   {
        if(RIGHT==0)
        {
            red=green=blue=1;       // turn off all colours
            wait_ms(3000);          // wait longer than ticker value
            counter=4;              // set counter value outside range
            colour_change.detach(); // detach function from ticker
        }
        if(counter ==0)     // if counter variable is 0 then turn red on
        {
            green=blue=1;       // shut off green and blue leds
            red=0;              // turn on red led
        }
        else
          if(counter==1)    // if counter variable is 1 turn green led on
          {
              red=blue=1;       // turn off red and blue leds
              green=0;          // turn on green led
          }
          else
             if(counter==2) // if counter variable is 2 then turn on blue led
             {
                green=red=1;    // turn off green and red led
                blue=0;         // turn on blue led
           } 
           else 
           if(counter==3)   // if counter variable is 3
           {
              blue=1;           // turn off blue
              counter=0;        // reset counter to 0
           }
           else            // if outside range 0,1,2 do nothing
           {}
   }
 }
 