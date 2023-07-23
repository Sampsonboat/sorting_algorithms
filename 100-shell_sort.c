#include <stdio.h>

void shell_sort(int *array, size_t size) {
    // Calculate the Knuth sequence gap
    size_t gap = 1;
    while (gap < size) {
        gap = gap * 3 + 1;
    }
    gap = (gap - 1) / 3;

    while (gap > 0) {
        // Perform insertion sort on elements separated by the gap
        for (size_t i = gap; i < size; ++i) {
            int temp = array[i];
            size_t j = i;
            while (j >= gap && array[j - gap] > temp) {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }

        // Print the array after each gap reduction
        printf("Array at gap %zu: ", gap);
        for (size_t i = 0; i < size; ++i) {
            printf("%d ", array[i]);
        }
        printf("\n");

        // Reduce the gap using the Knuth sequence
        gap = (gap - 1) / 3;
    }
}

int main() {
    int array[] = {9, 3, 7, 5, 1, 8, 2, 6, 4};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    shell_sort(array, size);

    printf("Sorted array: ");
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

