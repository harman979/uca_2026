#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define START_SIZE 8000
#define STEP_SIZE 4000
#define ITERATIONS 8

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generateRandom(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

void generateAscending(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        arr[i] = i;
}

void generateDescending(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        arr[i] = n - i;
}

void copyArray(int src[], int dest[], int n)
{
    memcpy(dest, src, n * sizeof(int));
}

void bubbleSort(int arr[], int n)
{
    int i, j;

    for(i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if(swapped == 0)
            break;
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, minIndex;

    for(i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(&arr[i], &arr[minIndex]);
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
double measureTime(void (*sortFunc)(int[], int), int arr[], int n)
{
    clock_t start, end;

    start = clock();
    sortFunc(arr, n);
    end = clock();

    return ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
}
double measureQuick(int arr[], int n)
{
    clock_t start, end;

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    return ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
}
double measureMerge(int arr[], int n)
{
    clock_t start, end;

    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();

    return ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
}

int main()
{
    srand(time(NULL));

    int n;

    printf("Size,Type,Bubble,Insertion,Selection,Quick,Merge,Heap\n");

    for(n = START_SIZE; n < START_SIZE + ITERATIONS * STEP_SIZE; n += STEP_SIZE)
    {
        int *original = (int *)malloc(n * sizeof(int));
        int *temp = (int *)malloc(n * sizeof(int));

        char *types[] = {"Random", "Ascending", "Descending"};

        for(int t = 0; t < 3; t++)
        {
            if(t == 0)
                generateRandom(original, n);
            else if(t == 1)
                generateAscending(original, n);
            else
                generateDescending(original, n);

            double bubble, insertion, selection, quick, merge, heap;

            copyArray(original, temp, n);
            bubble = measureTime(bubbleSort, temp, n);

            copyArray(original, temp, n);
            insertion = measureTime(insertionSort, temp, n);

            copyArray(original, temp, n);
            selection = measureTime(selectionSort, temp, n);

            copyArray(original, temp, n);
            quick = measureQuick(temp, n);

            copyArray(original, temp, n);
            merge = measureMerge(temp, n);

            copyArray(original, temp, n);
            heap = measureTime(heapSort, temp, n);

            printf("%d,%s,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f\n",
                   n, types[t], bubble, insertion,
                   selection, quick, merge, heap);
        }

        free(original);
        free(temp);
    }

    return 0;
}