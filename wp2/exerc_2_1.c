#include <stdio.h>
#include <string.h>

#define MAX 20

void copyString(char *str1, char *str2) {
    int i = 0;
    while (*str1 && i < MAX) {
        i++;
        *(str2++) = *(str1++);
    }
    *str2 = '\0';
}

int main(int argc, char *argv[]) {
    char input[MAX];
    char copiedString[MAX];
    if (argc == 1) {
        fgets(input, MAX, stdin);
        printf("Input: %s", input);
        copyString(input, copiedString);
    }
    else if (argc == 2) {
        printf("Input: %s\n", argv[1]);
        copyString(argv[1], copiedString);
    }
    else {
        printf("Expected 1 or 2 arguments, received: %d.\n", argc);
    }
    printf("Copied string: %s", copiedString);

    return 0;
}