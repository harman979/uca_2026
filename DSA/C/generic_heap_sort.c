#include <stdio.h>
#include <string.h>
#include <stddef.h>

typedef int (*CompareFunc)(const void *, const void *);

void swap(void *a, void *b, size_t size) {
    unsigned char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

void heapify(void *arr, size_t n, size_t i, size_t size, CompareFunc compare) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n &&
        compare((char *)arr + left * size,
                (char *)arr + largest * size) > 0) {
        largest = left;
    }

    if (right < n &&
        compare((char *)arr + right * size,
                (char *)arr + largest * size) > 0) {
        largest = right;
    }

    if (largest != i) {
        swap((char *)arr + i * size,
             (char *)arr + largest * size,
             size);

        heapify(arr, n, largest, size, compare);
    }
}

void heapSort(void *arr, size_t n, size_t size, CompareFunc compare) {
    for (size_t i = n / 2; i > 0; i--) {
        heapify(arr, n, i - 1, size, compare);
    }

    for (size_t i = n; i > 1; i--) {
        swap(arr, (char *)arr + (i - 1) * size, size);
        heapify(arr, i - 1, 0, size, compare);
    }
}

int compareInt(const void *a, const void *b) {
    int x, y;

    memcpy(&x, a, sizeof(int));
    memcpy(&y, b, sizeof(int));

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int compareDouble(const void *a, const void *b) {
    double x, y;

    memcpy(&x, a, sizeof(double));
    memcpy(&y, b, sizeof(double));

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int numbers[] = {5, 2, 8, 1, 9, 3};
    size_t n = sizeof(numbers) / sizeof(numbers[0]);

    heapSort(numbers, n, sizeof(int), compareInt);

    printf("Sorted integers: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    double values[] = {4.5, 1.2, 9.8, 2.3, 6.1};
    size_t m = sizeof(values) / sizeof(values[0]);

    heapSort(values, m, sizeof(double), compareDouble);

    printf("Sorted doubles: ");
    for (size_t i = 0; i < m; i++) {
        printf("%.1f ", values[i]);
    }

    printf("\n");

    return 0;
}
