/* ==================================== 
File name: exerc_6_3.c
Date: 2019-03-12
Group Number:02
Members that contributed:
Fabian
Oliver
Demonstration code: [14546] 
====================================== */
#include <stdio.h>
#define ML13_Status 0x0B00
#define ML13_Control 0x0B00

#define REG8(x) *((unsigned char *)(x)) // A macro to use for IO R/W

#define sensorsActivated 0x03
#define open_door 0x01
#define close_door 0x02
#define wide_open 0x4B
#define closing 0x80
#define thirtySeconds 30000

int main()
{
    while (1)
    {
        if (REG8(ML13_Status) | sensorsActivated)
        { //if any of the sensors are triggered
            REG8(ML13_Control) = open_door;
            while (REG8(ML13_Status) & wide_open)
            {
                //wait until door is widely open
            }
            delay(thirtySeconds);
            REG8(ML13_Control) = close_door;
            while (REG8(ML13_Status) & closing)
            {
                if (REG8(ML13_Status) | sensorsActivated)
                {
                    break; //break out of loop and reitterate the main loop, hence openning the door
                }
            }
        }
    }
}