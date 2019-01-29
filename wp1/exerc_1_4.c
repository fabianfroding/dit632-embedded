#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 5

int random;
int nGuesses = 0;

int AskToExit() {
    printf("Enter y to start new round or any other to finish.\n", random);
    char c;
    scanf("%s", &c);
    if (c == 'y') {
        nGuesses = 0;
        return 0;
    }
    return 1;
}

int main() {
    int guess;
    int b = 1;
    while (b == 1) {
        random = rand() % 101;
        printf("Guess a number between 1 and 100: (It's %d)\n", random);
        scanf("%d", &guess);
        nGuesses++;
        if (nGuesses > MAX_NUMBER) {
            printf("Out of guesses.");
            if (AskToExit() == 1)
                b = 0;
        } else if (guess == random) {
            printf("You have guessed %d times and your guess is correct.\n", nGuesses);
            if (AskToExit() == 1)
                b = 0;
        }
    }

    return 0;
}