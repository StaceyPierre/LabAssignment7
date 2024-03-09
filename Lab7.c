//Stacey Pierre
//COP3502
//Lab Assignment 7 
// March 8, 2024

#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp;
    int totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps[arr[j+1]]++;
                totalSwaps++;
            }
        }
    }
    swaps[0] = totalSwaps;
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, minIndex, temp;
    int totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps[arr[i]]++;
            totalSwaps++;
        }
    }
    swaps[0] = totalSwaps;
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int swaps1[101] = {0}; // Assuming the values range from 1 to 100
    int swaps2[101] = {0}; // Assuming the values range from 1 to 100
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int i;

    bubbleSort(array1, n1, swaps1);
    bubbleSort(array2, n2, swaps2);

    printf("array1 bubble sort:\n");
    for (i = 0; i < n1; i++) {
        printf("%d: %d\n", array1[i], swaps1[array1[i]]);
    }
    printf("Total number of swaps: %d\n\n", swaps1[0]);

    printf("array2 bubble sort:\n");
    for (i = 0; i < n2; i++) {
        printf("%d: %d\n", array2[i], swaps2[array2[i]]);
    }
    printf("Total number of swaps: %d\n\n", swaps2[0]);

    // Reset array
    int array3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int swaps3[101] = {0}; // Assuming the values range from 1 to 100
    int swaps4[101] = {0}; // Assuming the values range from 1 to 100

    selectionSort(array3, n1, swaps3);
    selectionSort(array4, n2, swaps4);

    printf("array1 selection sort:\n");
    for (i = 0; i < n1; i++) {
        printf("%d: %d\n", array3[i], swaps3[array3[i]]);
    }
    printf("Total number of swaps: %d\n\n", swaps3[0]);

    printf("array2 selection sort:\n");
    for (i = 0; i < n2; i++) {
        printf("%d: %d\n", array4[i], swaps4[array4[i]]);
    }
    printf("Total number of swaps: %d\n", swaps4[0]);

    return 0;
}
