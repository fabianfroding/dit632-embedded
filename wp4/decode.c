#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//================================================== DEFINITIONS
#define NUM_ARGS 1
// Variable ranges.
#define ENGINE_ON_MAX 1
#define GEAR_POS_MAX 122
#define KEY_POS_MAX 2
#define BRAKE1_MAX 1
#define BRAKE2_MAX 1
#define PART_MIN 0

//================================================== FUNCTIONS
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

char* hexToBin(char hex) {
    switch(toupper(hex)) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
        default: return "0";
    }
}

// Validate hex. Returns 0 if any value is not of hex, 1 if all values are hex.
int validateHex(const char *hex, const int len) {
    for (int i = len - 1; i >= 0; i--) {
        int temp = hex[i];
        if ((temp < 48 || temp > 57) && (temp < 65 || temp > 70) && (temp < 97 || temp > 102)) {
            printf("Error: Input contains value at index[%d] that is not of type hexadecimal. Exiting...\n", i);
            return 0;
        }
    }
    return 1;
}

int binToDec(char* n) {
    char *num = n;
    int dec_value = 0;
    int base = 1;
    int len = strlen(num);
    for (int i=len-1;i>=0;i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
} 

//================================================== MAIN
int main(int argc, char *argv[]) {
    if (argc == 2) {
        char *hex = argv[1];
        char bin[8] = "";

        int engine_on, gear_pos, key_pos, brake1, brake2;
        char engine_on_c, brake1_c, brake2_c;
        char gear_pos_c[3];
        char key_pos_c[2];

        // Validate that input is hexadecimal value.
        if (validateHex(hex, strlen(hex)) == 0) return 0;

        for (int i = 0; hex[i] != '\0'; i++) {
            strcat(bin, hexToBin(hex[i]));
        }
        printf("Hex: %s\nBin: %s\n", hex, bin);

        engine_on_c = bin[0];
        engine_on = engine_on_c - '0';

        key_pos_c[0] = bin[4];
        key_pos_c[1] = bin[5];
        key_pos_c[2] = '\0';
        key_pos = binToDec(key_pos_c);
        
        gear_pos_c[0] = bin[1];
        gear_pos_c[1] = bin[2];
        gear_pos_c[2] = bin[3];
        gear_pos_c[3] = '\0';
        gear_pos = binToDec(gear_pos_c);

        brake2_c = bin[7];
        brake2 = brake2_c - '0';
        brake1_c = bin[6];
        brake1 = brake1_c - '0';

        // Validate variable max range values etc.
        if (validateRanges(engine_on, gear_pos, key_pos, brake1, brake2) == 0) {
            printf("Error: Input value out of bounds for variable max ranges. Exiting...\n");
            return 0;
        }

        printf("engine_on: \t %d\n", engine_on);
        printf("key_pos: \t %d\n", key_pos);
        printf("gear_pos: \t %d\n", gear_pos);
        printf("brake1: \t %d\n", brake1);
        printf("brake2: \t %d\n", brake2);

    } else {
        printf("Received %d arguments. Expected: %d.\n", (argc - 1), NUM_ARGS);
    }
    return 0;
}