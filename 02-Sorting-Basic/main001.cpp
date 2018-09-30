#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main001() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    selectionSort(arr, sizeof(arr) / sizeof(int));
    for (int i : arr) {
        cout << i << endl;
    }
    return 0;
}