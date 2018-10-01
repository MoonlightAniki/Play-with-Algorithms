//
// Created by guoliang on 2018/10/1.
//

#ifndef INC_03_SORTING_ADVANCE_INSERTIONSORT_H
#define INC_03_SORTING_ADVANCE_INSERTIONSORT_H

#include <iostream>

using namespace std;

namespace InsertionSort {
    template<typename T>
    void insertionSort(T *arr, int n) {
        for (int i = 1; i < n; ++i) {
            T e = arr[i];
            int j;
            for (j = i; j - 1 >= 0 && arr[j - 1] > e; --j) {
                arr[j] = arr[j - 1];
            }
            arr[j] = e;
        }
    }

    // 对arr[l...r]进行插入排序
    template<typename T>
    void __insertionSort(T *arr, int l, int r) {
        for (int i = l + 1; i <= r; ++i) {
            T e = arr[i];
            int j;
            for (j = i; j - 1 >= l && arr[j - 1] > e; --j) {
                arr[j] = arr[j - 1];
            }
            arr[j] = e;
        }
    }
}

#endif //INC_03_SORTING_ADVANCE_INSERTIONSORT_H
