//
// Created by guoliang on 2018/9/29.
//

#ifndef INC_02_SORTING_BASIC_SHELLSORT_H
#define INC_02_SORTING_BASIC_SHELLSORT_H

#include <iostream>

using namespace std;

namespace ShellSort {
    template<typename T>
    void shellSort1(T *arr, int n) {
        int h = n / 2;
        while (h > 0) {
            for (int i = 1; i < n; ++i) {
                T e = arr[i];
                int j;
                for (j = i; j - h >= 0 && arr[j - h] > e; j -= h) {
                    arr[j] = arr[j - h];
                }
                arr[j] = e;
            }
            h /= 2;
        }
    }

    template<typename T>
    void shellSort2(T *arr, int n) {
        int h = 1;
        while (h < n / 3) {
            h = 3 * h + 1;
        }

        while (h > 0) {
            for (int i = 1; i < n; ++i) {
                T e = arr[i];
                int j;
                for (j = i; j - h >= 0 && arr[j - h] > e ; j -= h) {
                    arr[j] = arr[j - h];
                }
                arr[j] = e;
            }
            h /= 3;
        }
    }
}

#endif //INC_02_SORTING_BASIC_SHELLSORT_H
