#include <stdio.h>
#include <string.h>

#define NUM_ARGS 2
#define MAX 100

int compareStrings(char *string1, char *string2) {
    if (sizeof(string1) != sizeof(string2)) {
        printf("sizes are not equal\n");
        return 0;
    }
    while (*string1 != '\0') {
        if (*string1 != *string2) {
            printf("s1[i] != s2[i]\n");
            return 0;
        }
        string1++;
        string2++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc == NUM_ARGS + 1) {
        char string1[MAX];
        char string2[MAX];
        int i = compareStrings(argv[1], argv[2]);
        if (i == 1) {
            printf("Arguments are identical.");
        } else {
            printf("Arguments are NOT identical");
        }
    } else {
        printf("%d arguments given. Expected %d.", (argc - 1), NUM_ARGS);
    }

    return 0;
}