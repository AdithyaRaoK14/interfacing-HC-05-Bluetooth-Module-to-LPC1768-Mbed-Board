#include "mbed.h"
#include "Serial.h"
 
Serial bluetooth(p9, p10); // TX, RX
 
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);
 
int main()
{
    while (1) {
        if (bluetooth.readable()) {
            char command[5];
            bluetooth.read(command, sizeof(command)); // read up to 5 bytes
            int led = command[3] - '0'; // extract the LED number from the command
            if (command[0] == 'O' && command[1] == 'N' && led >= 1 && led <= 4) {
                switch (led) {
                    case 1:
                        led1 = 1;
                        break;
                    case 2:
                        led2 = 1;
                        break;
                    case 3:
                        led3 = 1;
                        break;
                    case 4:
                        led4 = 1;
                        break;
                }
            } else if (command[0] == 'O' && command[1] == 'F' && command[2] == 'F' && led >= 1 && led <= 4) {
                switch (led) {
                    case 1:
                        led1 = 0;
                        break;
                    case 2:
                        led2 = 0;
                        break;
                    case 3:
                        led3 = 0;
                        break;
                    case 4:
                        led4 = 0;
                        break;
                }
            }
        }
    }
}
