
#include <stdio.h>
#include <wiringPi.h>
// Define circuit connected to GREEN LED as GPIO 02, Physical Pin 03
// Define circuit connected to RED LED as GPIO 17, Physical Pin 11
#define LED_GREEN 2
#define LED_RED 17
int main()
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
