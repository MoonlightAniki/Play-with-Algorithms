//
// Created by guoliang on 2018/9/29.
//

#ifndef INC_02_SORTING_BASIC_SELECTIONSORT_H
#define INC_02_SORTING_BASIC_SELECTIONSORT_H

#include <iostream>

using namespace std;

namespace SelectionSort {
    template<typename T>
    void selectionSort(T *arr, int n) {
        for (int i = 0; i < n; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(arr[minIndex], arr[i]);
            }
        }
    }
}

#endif //INC_02_SORTING_BASIC_SELECTIONSORT_H
