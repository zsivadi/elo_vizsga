#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 100
#define MAX 1000

int beolvas();
void feltolt(int*, int);
int compare(const void* a, const void* b);

int main()
{
    srand(time(0));
    int tomb[10];
    int length = sizeof(tomb)/sizeof(tomb[0]);
    
    int n = beolvas();
    printf("%d\n", n);
    
    feltolt(tomb, length);
    qsort(tomb, length, sizeof(int), compare);
    for (int i = 0; i < length; i++) {
        printf("A tomb %d. eleme: %d\n", i+1, tomb[i]);
    }
    
    float rnd = MIN + ((float)rand() / RAND_MAX) * (MAX - MIN);
    printf("Lebegopontos random: %lf", rnd);
    
    return 0;
}

// Beolvasás

int beolvas() {
    int x, ok;
    char ch;
    do {
        ok = 1;
        printf("Adjon meg egy erteket %d és %d kozott: ", MIN, MAX);
        if (scanf("%d", &x) != 1 || (x < MIN) || (x > MAX)) {
            printf("Hibás input\n");
            ok = 0;
            while ((ch=getchar())!='\n');
        }
    } while (!ok);
    return x;
}

// Két szám beolvasása - mainbe

void ell_beolvasas() {
    int x, y, ok;
    char ch;
    do {
        ok = 1;
        printf("Adjon meg egy erteket %d és %d kozott: ", MIN, MAX);
        if (scanf("%d, %d", &x, &y) != 2 || (x < MIN) || (x > MAX) || (x > y)) {
            printf("Hibás input\n");
            ok = 0;
            while ((ch=getchar())!='\n');
        }
    } while (!ok);
}

// Tömb feltöltés

void feltolt(int* array, int length) {
    if (length > 0) {
        for (int i = 0; i < length; i++) {
            int r = (rand() % (MAX - MIN - 1)) + MIN + 1;
            array[i] = r;
        }
    }
}

// Összehasonlító tömb sorthoz

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b); // Növekvő sorrend
}
