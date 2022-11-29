#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bubbleSort(int array[], int n) {
    int i, j;
    int permutations = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                permutations++;
                swap(array[j], array[j + 1]);
            }
        }
    }
    return permutations;
}

int insertionSort(int array[], int n) {
    int i, j, key;
    int permutations = 0;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
            permutations++;
        }
        array[j + 1] = key;
    }
    return permutations;
}

int selectionSort(int array[], int size) {
    int permutations = 0;
    for (int step = 0; step < size; step++) {
        int min_index = step;
        for (int i = step + 1; i < size; i++) {
            if (array[i] < array[min_index]) {
                min_index = i;
            }
        }
        permutations++;
        swap(&array[min_index], &array[step]);
    }
    return permutations;
}




void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}

int main() {
    int arr[] = {45, 51, -4, 18, -67, 99, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    //printArray(arr, n);
    int o = selectionSort(arr, n);
    cout << o;
}
