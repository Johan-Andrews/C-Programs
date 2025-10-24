//merge sort, quick sort and insertion sort with comparison count

#include <stdio.h>

long insertionCount = 0, quickCount = 0, mergeCount = 0;

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            insertionCount++;
            arr[j + 1] = arr[j];
            j--;
        }
        if (j >= 0) insertionCount++;
        arr[j + 1] = key;
    }
}

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        quickCount++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        mergeCount++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n], temp1[n], temp2[n], temp3[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    copyArray(arr, temp1, n);
    copyArray(arr, temp2, n);
    copyArray(arr, temp3, n);

    insertionSort(temp1, n);
    quickSort(temp2, 0, n - 1);
    mergeSort(temp3, 0, n - 1);

    printf("\n--- Sorted Arrays ---\n");

    printf("Insertion Sort: ");
    printArray(temp1, n);
    printf("Quick Sort:     ");
    printArray(temp2, n);
    printf("Merge Sort:     ");
    printArray(temp3, n);

    printf("\n--- Comparison Counts ---\n");

    printf("Insertion Sort Comparisons: %ld\n", insertionCount);
    printf("Quick Sort Comparisons:     %ld\n", quickCount);
    printf("Merge Sort Comparisons:     %ld\n", mergeCount);
    return 0;
}



