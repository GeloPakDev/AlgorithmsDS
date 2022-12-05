#include <iostream>
#include<bits/stdc++.h>

using namespace std;

//Util Functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}

void printArrayString(string str[], int n) {
    for (int i = 0; i < n; i++)
        cout << str[i] << " ";
}

//Tasks
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

void stringBubbleSort(char array[][100], int n) {
    char temp[100];
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(array[j], array[j + 1]) > 0) {
                strcpy(temp, array[j]);
                strcpy(array[j], array[j + 1]);
                strcpy(array[j + 1], temp);
            }
        }
    }
}

void charBubbleSort(char array[], int n) {
    char temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            if (array[j] >= array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void stringInsertionSort(string s[], int n) {
    for (int i = 1; i < n; i++) {
        string temp = s[i];

        int j = i - 1;
        while (j >= 0 && temp.length() < s[j].length()) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = temp;
    }
}

void charInsertionSort(char array[], int n) {

}

void stringSelectionSort(char arr[][100], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    char minStr[100];
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        int min_idx = i;
        strcpy(minStr, arr[i]);
        for (j = i + 1; j < n; j++) {
            // If min is greater than arr[j]
            if (strcmp(minStr, arr[j]) > 0) {
                // Make arr[j] as minStr and update min_idx
                strcpy(minStr, arr[j]);
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i) {
            char temp[100];
            strcpy(temp, arr[i]); //swap item[pos] and item[i]
            strcpy(arr[i], arr[min_idx]);
            strcpy(arr[min_idx], temp);
        }
    }
}


//int main() {
//    char array[][100] = {"GeeksforGeeks", "Quiz", "Practice", "Gblogs", "Coding"};
//    int n = sizeof(array) / sizeof(array[0]);
//    for (int i = 0; i < n; i++)
//        printf("\n String %d is %s", i + 1, array[i]);
//    stringSelectionSort(array, n);
//
//    for (int i = 0; i < n; i++)
//        printf("\n String %d is %s", i + 1, array[i]);
//}