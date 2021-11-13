#include <stdio.h>
#include <wiringPi.h>
#include "wifi_led.h"

void controlstatus(status)
{
    if(status == 0)
    {
        // Allow calling of programs to use GPIO Pin numbers with no remapping
        wiringPiSetupGpio();
        // Declare GPIO 02's pinmode as Output
        // Declare GPIO 17's pinmode as Output
        pinMode(LED_GREEN, OUTPUT);
        pinMode(LED_RED, OUTPUT);
        // Check if that Pin declarations have been done
        printf("LED and button pins have beens setup.\n");
        // Turn off LED GREEN and RED Lights
        digitalWrite(LED_GREEN,0);
        digitalWrite(LED_RED,0);
    }
    else if (status == 1)
    {
        // Allow calling of programs to use GPIO Pin numbers with no remapping
        wiringPiSetupGpio();
        // Declare GPIO 02's pinmode as Output
        // Delare GPIO 17's pinmode as Output
        pinMode(LED_GREEN, OUTPUT);
        pinMode(LED_RED, OUTPUT);
        // Check if that Pin declarations have been done
        printf("LED and button pins have beens setup.\n");
        // Turn on GREEN and RED LED Light in static mode
        digitalWrite(LED_GREEN,1);
        digitalWrite(LED_RED,1);
    }
    else if(status == 2)
    {
        // Allow calling of programs to use GPIO Pin numbers with no remapping
        wiringPiSetupGpio();
        // Declare GPIO 02's pinmode as Output
        // Declare GPIO 17's pinmode as Output
        pinMode(LED_GREEN, OUTPUT);
        pinMode(LED_RED, OUTPUT);
        // Check if that Pin declarations have been done
        printf("LED and button pins have beens setup.\n");
        // Taking in user input for blinking time intervals
        float blinking_interval;
        printf("Enter in the blinking time intervals in seconds: ");
        scanf("%f",&blinking_interval);
        // Conversion to milliseconds
        blinking_interval*=1000;
        // Loop while circuit is live
        while(1)
        {
            // Check iteration of loop
            printf("\nLED is now blinking");
            // Turn on GREEN and RED LED for blinking interval
            digitalWrite(LED_GREEN,1);
            digitalWrite(LED_RED,1);
            delay(blinking_interval);
            // Turn off GREEN and RED LED for blinking interval
            digitalWrite(LED_GREEN,0);
            digitalWrite(LED_RED,0);
            delay(blinking_interval);
        }
    }
}