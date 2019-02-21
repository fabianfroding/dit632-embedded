/* ==================================== 
File name: exerc_4_4.c
Date: 2019-03-01
Group Number:02
Members that contributed:
Oliver
Fabian
Demonstration code: [None] 
====================================== */
#include <time.h>
#include <stdio.h>

void f_delay(int);
unsigned char random_inport(void);
void printport(int);

int main()
{
    int nr;
    unsigned char port;
    srand(time(0));
    for (nr = 0; nr < 10; nr++)
    {
        port = random_inport();
        printport(port);
        f_delay(5);
        if (port >> 7 == 0)
        {
            unsigned char fourDigits = port & 15;
            printf("%x\n", fourDigits);
        }
    }
    return (0);
}

void f_delay(int tenth_sec)
{

    clock_t start_t, end_t;
    long int i;
    start_t = clock();
    do
    {
        for (i = 0; i < 10000000; i++)
            ;
        end_t = clock();
    } while ((end_t - start_t) < (tenth_sec * CLOCKS_PER_SEC) / 10);
    return;
}

unsigned char random_inport(void)
{
    unsigned char inport = 0;
    inport = rand() % 256;
    return (inport);
}

void printport(int portvalue)
{
    int binchar[8], rest, j, i = 0;
    rest = portvalue;
    while (rest != 0)
    {
        binchar[i++] = rest % 2;
        rest = rest / 2;
    }
    // Fill to 8 bits
    while (i < 8)
    {
        binchar[i++] = 0;
    }
    // Print bits and at the end corresponding decimal value
    for (j = i - 1; j > -1; j--)
        printf("  %d", binchar[j]);
    printf(" --------Porten value = %d  \n", portvalue);
    return;
}

/********************************
Program file : bit_manage_function.c
Peter Lundin / 2016-01-97
For test IO program function 

*********************************/