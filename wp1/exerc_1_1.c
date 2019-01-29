#include <stdio.h>

int main() {
    int i;
    int b = 1;
    char sentence[5][100] = {
        {"Sentence 1"},
        {"Sentence 2"},
        {"Sentence 3"},
        {"Sentence 4"},
        {"Sentence 5"}
    };

    while (b == 1) {
        printf("Enter a number between 1 and 5:\n");
        scanf("%d", &i);
        if (i < 1 | i > 5)
            b = 0;
        else
            printf("%s\n", sentence[i - 1]);
    }

    return 0;
}