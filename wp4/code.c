#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//================================================== DEFINED
#define NUM_ARGS 5
// Variable ranges.
#define ENGINE_ON_MAX 1
#define GEAR_POS_MAX 4
#define KEY_POS_MAX 2
#define BRAKE1_MAX 1
#define BRAKE2_MAX 1
#define PART_MIN 0

//================================================== FUNCTIONS
void printBits(unsigned int x) {
    for(int i = (sizeof(int) * 8) - 1; i >= 0; i--) {
       (x & (1u << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
}

// Returns 0 if ranges are out of bounds, and 1 if in bounds.
int validateRanges(int p1, int p2, int p3, int p4, int p5) {
    // Check max/min ranges.
    if (
        p1 < PART_MIN || p2 < PART_MIN || p3 < PART_MIN || p4 < PART_MIN || p5 < PART_MIN ||
        p1 > ENGINE_ON_MAX || p2 > GEAR_POS_MAX || p3 > KEY_POS_MAX || p4 > BRAKE1_MAX || p5 > BRAKE2_MAX
        ) 
        {
        return 0;
    }
    return 1;
}

void printParts(int p1, int p2, int p3, int p4, int p5) {
    printf("engine_on: %d\ngear_pos: %d\nkey_pos: %d\nbrake1: %d\nbrake2: %d\n", p1, p2, p3, p4, p5);
}

//================================================== MAIN
int main(int argc, char *argv[]) {
    if (argc == 6) {

        // Validate that arguments are of type int.
        for (int i = 1; i <= NUM_ARGS; i++) {
            if (!isdigit(*argv[i])) {
                printf("Error: Argument(s) is not of type int. Exiting...\n");
                return 0;
            }
        }

        int engine_on = strtol(argv[1], NULL, 10);
        int gear_pos = strtol(argv[2], NULL, 10);
        int key_pos = strtol(argv[3], NULL, 10);
        int brake1 = strtol(argv[4], NULL, 10);
        int brake2 = strtol(argv[5], NULL, 10);

        // Validate ranges of input values.
        if (validateRanges(engine_on, gear_pos, key_pos, brake1, brake2) == 0) {
            printf("Error: Argument values are out of bounds. Exiting...\n");
            return 0;
        }

        printParts(engine_on, gear_pos, key_pos, brake1, brake2);

        int packed = engine_on + gear_pos + key_pos + brake1 + brake2;
        unsigned char packedChar = (unsigned char)packed;
        printf("\nBits: ");
        printBits(packed);
        printf("Hex: %X", packedChar);

    } else {
        printf("Received %d arguments. Expected: %d.", (argc - 1), NUM_ARGS);
    }
    return 0;
}