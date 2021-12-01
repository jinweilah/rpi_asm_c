#include <stdio.h>
#include <wiringPi.h>
// Define circuit connected to GREEN LED as GPIO 2, Physical Pin 3
// Define circuit connected to RED LED as GPIO 17, Physical Pin 11
// Define circuit coming out of button as GPIO 18, Physical Pin 12
#define LED_GREEN 2
#define LED_RED 17
#define PIN_BUTTON 18
// Header for blinking function
void blinking(int);
int main()
{
        // Allow calling of programs to use GPIO Pin numbers with no remapping
        wiringPiSetupGpio();
        // Declare GPIO 2's pinmode as Output
        // Declare GPIO 17's pinmode as Output
        // Declare GPIO 18's pinmode as Input
        pinMode(LED_GREEN, OUTPUT);
        pinMode(LED_RED, OUTPUT);
        pinMode(PIN_BUTTON, INPUT);
        // Check if that Pin declarations have been done
        printf("LED and button pins have beens setup.\n");
        // Initialise freq as Integer
        int freq;
        // Loop while circuit is live
        while (1)
        {
                // Check if circuit is live
                printf("\nlive now.");
                // If button is pushed
                if (digitalRead(PIN_BUTTON) == 1)
                {
                        printf("\n\npushed switch button.");
                        // If GPIO 2 and 17, Circuits connected to GREEN and RED LED detected to be off
                        if(digitalRead(LED_RED) == 0 && digitalRead(LED_GREEN) == 0)
                        {
                                // Turn on GPIO 2, Turn on GREEN LED
                                // Turn on GPIO 17, Turn on RED LED
                                digitalWrite(LED_GREEN, 1);
                                digitalWrite(LED_RED, 1);
                                printf("\nGreen and Red LED on.\n");
                        }
                        // Else if GPIO 2 and 17, Circuits connected to GREEN and RED LED other than off
                        else
                        {
                                // Initialise cycle time of blinking mode to 200ms
                                freq = 200;
                                // Loop while blink is on and frequency equal or lesser than 600ms
                                while(freq <= 600)
                                {
                                        // Call function blinking, input frequency
                                        blinking(freq);
                                        // If button is pushed
                                        if(digitalRead(PIN_BUTTON)==1)
                                        {
                                                printf("\n\npushed switch button.");
                                                // Increment frequency by 200ms
                                                freq+=200;
                                                printf("\n\nLED blinking frequency decreases.");
                                        }
                                }
                                // Turn off GREEN and RED LED
                                digitalWrite(LED_GREEN, 0);
                                digitalWrite(LED_RED, 0);
                                printf("\nLED is off.\n");
                        }
                }
                // Iteration signal delay of 500ms
                delay(500);
        }
        return 0;
}
// Function blinking, takes in integer input
void blinking(int freq)
{
        // Check function is being executed
        printf("\nLED is blinking now...");
        // Turn on GREEN and RED LED for frequency amount of time interval
        digitalWrite(LED_GREEN,1);
        digitalWrite(LED_RED, 1);
        delay(freq);
        // Turn off GREEN and RED LED for frequency amount of time interval
        digitalWrite(LED_GREEN, 0);
        digitalWrite(LED_RED, 0);
        delay(freq);
}
