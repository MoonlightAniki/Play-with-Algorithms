//
// Created by guoliang on 2018/10/1.
//

#ifndef INC_03_SORTING_ADVANCE_SHELLSORT_H
#define INC_03_SORTING_ADVANCE_SHELLSORT_H

#include <iostream>

using namespace std;
namespace ShellSort {
    template<typename T>
    void shellSort(T *arr, int n) {
        int h = 1;
        while (h < n / 3) {
            h = 3 * h + 1;
        }
        while (h > 0) {
            for (int i = h; i < n; ++i) {
                T e = arr[i];
                int j;
                for (j = i; j - h >= 0 && arr[j - h] > e; j -= h) {
                    arr[j] = arr[j - h];
                }
                arr[j] = e;
            }
            h /= 3;
        }
    }
}
#endif //INC_03_SORTING_ADVANCE_SHELLSORT_H
