#include <stdio.h>

/* Function to sort an array using insertion sort */
void insert(int a[], int n) {
    int i, j, temp;

    // Iterate over the array starting from the second element
    for (i = 1; i < n; i++) {
        temp = a[i]; // Store the current element in temp
        j = i - 1;

        /* Move elements of a[0..i-1], that are greater than temp, to one position ahead
           of their current position */
        while (j >= 0 && temp < a[j]) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp; // Insert temp in its correct position
    }
}

/* Function to print the array */
void printArr(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = { 12, 31, 25, 8, 32, 17 };
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting, array elements are:\n");
    printArr(a, n);

    insert(a, n);

    printf("After sorting, array elements are:\n");
    printArr(a, n);

    return 0;
}