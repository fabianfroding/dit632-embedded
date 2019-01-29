#include <stdio.h>
#define MAX_INPUT 10

int main() {
    char input[MAX_INPUT];
    gets(input);
    char test = 'h';
    printf("%c\n", test + 13);
    
    for (int i = 0; i < MAX_INPUT; i++) {
        //if (input[i] == 'h')
            printf("%c", input[i] + 13);
        //printf("works");
        //printf("%c", input[i] + 13);
        
    }

    gets(input);
    return 0;
}