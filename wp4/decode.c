#include <stdio.h>
#include <ctype.h>
#include <string.h>

//================================================== DEFINITIONS
#define NUM_ARGS 1

//================================================== FUNCTIONS
int getInt(char c) {
    // If char is letter, subtract with A and add 10.
    if (isalpha(c)) {
        return toupper(c) - 'A' + 10;
    }
    // If char is digit, substract with '0'.
    return c - '0';
}

int hexToInt(const char *hex) {
    const int LEN = strlen(hex) - 1;
    int pow = 1;
    int dec = 0;
    for (int i = LEN; i >= 0; i--) {
        dec += getInt(hex[i]) * pow;
        pow *= 16;
    }
    return dec;
}

//================================================== MAIN
int main(int argc, char *argv[]) {
    if (argc == 2) {
        char *hex = argv[1];
        const int LEN = strlen(hex) - 1;

        for (int i = LEN; i >= 0; i--) {
            int temp = hex[i];
            if ((temp < 48 || temp > 57) && (temp < 65 || temp > 70) && (temp < 97 || temp > 102)) {
                printf("Error: Input contains value at index[%d] that is not of type hexadecimal. Exiting...\n", i);
                return 0;
            }
        }
        printf("Hex: %s -----> Decimal: %d\n", hex, hexToInt(hex));

    } else {
        printf("Received %d arguments. Expected: %d.\n", (argc - 1), NUM_ARGS);
    }
    return 0;
}