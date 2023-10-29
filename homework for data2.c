#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int numbers[100];
    int i;

    srand(time(0));

    for (i = 0; i < 100; i++) {
        numbers[i] = rand() % 1000 + 1;
    }

    bubbleSort(numbers, 100);

    printf("Sorted numbers in descending order:\n");
    for (i = 0; i < 100; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
