#include "sorting.h"

static void merge(int [], int, int, int);
static int split(int [], int, int);
static void swap(int *, int *);

/******************************************************************************
 * Bubble Sort: O(n^2) complexity.                                            *
 ******************************************************************************/ 
void bubbleSort(int a[], int n) {
    int i, j, swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
                swapped++;
            }
        }
        if (swapped == 0) break;
    }
}

/******************************************************************************
 * Selection Sort: O(n^2) complexity.                                         *
 ******************************************************************************/
void selectionSort(int a[], int n) {
    int i, j, min_ind, temp;

    for (i = 0; i < n - 1; i++) {
        min_ind = i;     
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min_ind]) {
                min_ind = j;
            }
        }
        swap(&a[i], &a[min_ind]);
    }
}

/******************************************************************************
 * Insertion Sort: O(n^2) complexity.                                         *
 ******************************************************************************/
void insertionSort(int a[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

/******************************************************************************
 * Merge Sort: O(nlog(n)) complexity.                                         *
 ******************************************************************************/
void mergeSort(int a[], int left, int right) {
    if (left >= right) return; 

    int middle = left + (right - left) / 2;
    mergeSort(a, left, middle);
    mergeSort(a, middle + 1, right);

    merge(a, left, middle, right);
}

static void merge(int a[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int l[n1];
    for (i = 0; i < n1; i++) {
        l[i] = a[left + i];
    }
    int r[n2];
    for (j = 0; j < n2; j++) {
        r[j] = a[middle + 1 + j];
    }

    i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            a[k] = l[i++];
        } else {
            a[k] = r[j++];
        }
        k++;
    }

    while (i < n1) {
        a[k++] = l[i++];
    }
    while (j < n2) {
        a[k++] = r[j++];
    }
}

/******************************************************************************
 * Quick Sort: O(nlog(n)) complexity.                                         *
 ******************************************************************************/
void quickSort(int a[], int left, int right) {
    if (left >= right) return;

    int middle = split(a, left, right);

    quickSort(a, left, middle - 1);
    quickSort(a, middle + 1, right);
}

static int split(int a[], int left, int right) {
    int pivot = a[left];

    for (;;) {
        while (left < right && pivot <= a[right]) {
            right--;
        }
        if (left >= right) break;
        a[left++] = a[right];

        while (left < right && a[left] <= pivot) {
            left++;
        }
        if (left >= right) break;
        a[right--] = a[left];
    }

    a[right] = pivot;
    return right;
}

/******************************************************************************
 * Swap utility.                                                              *
 ******************************************************************************/
static void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}