/* ==================================== 
File name: exerc_4_3.c
Date: 2019-03-01
Group Number:02
Members that contributed:
Oliver
Fabian
Demonstration code: [None] 
====================================== */
#include <util/delay.h>

#define REG8(x) *((unsigned char *)(x)) // A macro to use for IO R/W
#define OUT_PORTD 0x2B
#define IN_PORTB 0x23
#define DDR_D 0x2A
#define DDR_B 0x24
#define BLINK_DELAY_MS 800

int main(void)
{
    unsigned char code;
    unsigned char incode;

    // If use of simple pointer and not macro REG8
    //unsigned char *portd;
    //portd=(unsigned char *)0x002B;    // Must do as this
    //*portd=0; If use of pointer for IO R/W

    // set PORTD for output, set bit gives out
    REG8(DDR_D) = 0xff;
    // set PORTB for input, clr bit gives inbit
    REG8(DDR_B) = 0x00;

    unsigned char *portd = (unsigned char *)OUT_PORTD;
    *portd = 1;

    // unsigned char *portb = (unsigned char *)IN_PORTB;
    // *portb = 0;

    while (1)
    {
        _delay_ms(BLINK_DELAY_MS); // In util/delay.h

        if (REG8(IN_PORTB) == 0x01)
        {
            if (*portd == 128)
            {
                //if not at end
                *portd = 1;
            }
            else
            {
                *portd = *portd << 1;
            }
        }
    }
}
