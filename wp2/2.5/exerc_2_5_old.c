#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5
#define MAXNUMBER 20

#define ARRAY_SIZE 5
#define NUM_INTERVAL 20

// ------ Function declaration ----------

// Use pointer to fill the table
void create_random(int *tab) {
    for (int i = 0; i < sizeof(tab); i++) {
        tab[i] = rand() % MAXNUMBER;
        printf("%d\n", tab[i]);
    }
}

// Use pointer
void count_frequency(int *tab, int *freq) {
    for (int i = 0; i < MAXNUMBER; i++) {
        freq[i] = 0;
        int count = 0;
        for (int j = 0; j < MAXNUMBER; j++) {
            if (freq[j] == tab[i]) {
                count++;
                printf("freq[%d]: . tab[%d]: .\n", freq[j], tab[i]);
            }
        }
        freq[i] = count;
        printf("%d: %d\n", i, count);
    }
}

// Use pointer
void draw_histogram(int *freq) {

}

int main () {
    int table[ARRAY_SIZE], n;
    int frequency[NUM_INTERVAL];
    srand(time(NULL));
    create_random(table);
    //count_frequency(table, frequency);

    printf("sizeof table: %d", sizeof(table));

    for (int i = 0; i < sizeof(table); i++) {
        int count = 0;
        for (int j = 0; j < sizeof(table); j++) {
            if (table[i] == table[j]) {
                printf("table[%d](%d) == table[%d](%d)\n", i, table[i], j, table[j]);
                count++;
            }
        }
        frequency[i] = count;
    }

    for (int i = 0; i < sizeof(table); i++) {
        printf("%d: %d\n", i, frequency[i]);
    }


    return 0;
}