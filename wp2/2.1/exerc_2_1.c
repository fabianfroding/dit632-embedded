#include <stdio.h>
#include <string.h>

#define MAX 20
#define LOW 5

void copyString(char *str1, char *str2) {
    int i = 0;
    while (*str1 && i < MAX) {
        i++;
        *(str2++) = *(str1++);
    }
    *str2 = '\0';
}

int doesFileExist(const char *filename){
    FILE *file;
    if (file = fopen(filename, "r")) {
        fclose(file);
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        printf("Received: %s\n", argv[1]);
        char str1[MAX];
        char str2[MAX];

        if (doesFileExist(argv[1])) {
            FILE* fPointer = fopen(argv[1], "r"); // "r" for read

            // Ask TA: Read only first line or entire .txt file?
            fgets(str1, MAX + 1, fPointer); // +1. Even though MAX is set to 20, only counts 19 from .txt file.
            /*while (!feof(fPointer)) {
                fgets(str1, MAX, fPointer);
            }*/

            copyString(str1, str2);
            fclose(fPointer);
        } else {
            copyString(argv[1], str2);
        }
        printf("Copied string: %s", str2);
    }
    else {
        printf("Expected 1 argument, received: %d.\n", argc);
    }

    return 0;
}