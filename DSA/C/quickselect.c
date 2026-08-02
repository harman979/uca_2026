#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

void quickSelect(int arr[], int low, int high, int k) {
    if (low < high) {
        int pi = partition(arr, low, high);

        if (pi == k)
            return;
        else if (pi > k)
            quickSelect(arr, low, pi - 1, k);
        else
            quickSelect(arr, pi + 1, high, k);
    }
}

int main() {
    int arr[] = {12, 3, 5, 7, 19, 1, 9, 4, 15, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    quickSelect(arr, 0, n - 1, k - 1);

    printf("Smallest %d elements:\n", k);
    for (int i = 0; i < k; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}