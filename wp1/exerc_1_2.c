#include <stdio.h>

#define MAX 50

int CountWords(const char *pStr) {
    int numWords = 0;
    int len = 0;

    //printf("value of pStr: %s", pStr);
    if (pStr == NULL)
        return 0;

    while (*pStr) {
        printf("len: %d\n", len);
        if (*pStr == ' ') {
            //printf("*pStr == ' ', len: %d\n", len);
            len = 0;
        } else if (++len == 1) {
            //printf("++len == 1, len: %d\n", len);
            numWords++;
        }
        pStr++;
    }

    return numWords;
}

int main() {
    char sentence[MAX];

    printf("Write a sentence (with MAX %d characters): \n", MAX);
    gets(sentence);
    printf("Number of words: %d\n", CountWords(sentence));

    gets(sentence); // To prevent cmd from closing.
    return 0;
}