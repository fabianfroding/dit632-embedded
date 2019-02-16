#include <stdio.h> 

void printBits(size_t const size, void const * const ptr) {
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;

    for (int i = size - 1; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
        printf(" ");
    }
    puts("");
}

void showbits(unsigned int x) {
    for(int i = (sizeof(int) * 8) - 1; i >= 0; i--) {
       (x & (1u << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
}


int main(void) {
    int i = 1;
    showbits(i);
    //printf("%d\n", i);;
    //printBits(sizeof(i), &i);
    /*i = i << 2;
    printf("%d << 2\n", i);
    printBits(sizeof(i), &i);
    i = i >> 2;
    printf("%d >> 2\n", i);
    printBits(sizeof(i), &i);*/
    int j = 2;
    showbits(j);
    //printBits(sizeof(j), &j);
    int n = ~j;
    showbits(n);
    //printBits(sizeof(n), &n);

    /*
    i = 2;
    //printBits(sizeof(i), &i);
    i = 3;
    //printBits(sizeof(i), &i);
	
    /*printf("----------------\n");
    for (int x = 0; x <= 15; x++) {
        printBits(sizeof(x), &x);
    }
    printf("----------------\n");
	
    for (int x = 1; x <= 256; x*=2) {
        printBits(sizeof(x), &x);
    }*/

    return 0;
}