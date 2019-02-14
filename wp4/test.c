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


int main(void) {
    int i = 1;
    printf("%u", i);
    //printBits(sizeof(i), &i);
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