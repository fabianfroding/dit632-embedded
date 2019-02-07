//12890
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define MAXNUMBER 20

// ------ Function declaration ----------
// Comparison func for qsort
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Use pointer to fill the table
void create_random(int *tab)
{
    for (int i = 0; i < MAX; i++)
    {
        tab[i] = rand() % (MAXNUMBER + 1);
        //printf("%d\n", tab[i]); // Uncomment this to display the random values.
    }
}

// Use pointer
void count_frequency(int *tab, int *freq)
{
    for (int i = 0; i <= MAXNUMBER; i++)
    {
        int count = 0;
        for (int j = 0; j < MAX; j++)
        {
            if (i == tab[j])
            {
                count++;
            }
        }
        freq[i] = count;
    }
}

// Use pointer
void draw_histogram(int *freq)
{
    for (int i = 0; i <= MAXNUMBER; i++)
    {
        if (freq[i] != 0)
        {
            printf("\n%d ", i, freq[i]);
            for (int j = 0; j < freq[i]; j++)
            {
                printf("x", j);
            }
        }
    }
}

int main()
{
    int table[MAX], n;
    int frequency[MAXNUMBER + 1];
    srand(time(NULL)); // Give seed

    create_random(table);
    qsort(table, MAX, sizeof(int), compare);
    count_frequency(table, frequency);
    draw_histogram(frequency);

    return 0;
}