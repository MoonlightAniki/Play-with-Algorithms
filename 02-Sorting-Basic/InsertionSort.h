//
// Created by guoliang on 2018/9/29.
//

#ifndef INC_02_SORTING_BASIC_INSERTIONSORT_H
#define INC_02_SORTING_BASIC_INSERTIONSORT_H

#include <iostream>

using namespace std;

namespace InsertionSort {
    // V1
//    template<typename T>
//    void insertionSort(T *arr, int n) {
//        for (int i = 1; i < n; ++i) {
//            for (int j = i; j - 1 >= 0; --j) {
//                if (arr[j] < arr[j - 1]) {
//                    swap(arr[j], arr[j - 1]);
//                } else {
//                    break;
//                }
//            }
//        }
//    }

    // V2
//    template<typename T>
//    void insertionSort(T *arr, int n) {
//        for (int i = 1; i < n; ++i) {
//            for (int j = i; j - 1 >= 0 && arr[j] < arr[j - 1]; --j) {
//                swap(arr[j], arr[j - 1]);
//            }
//        }
//    }


    // V3
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
}

#endif //INC_02_SORTING_BASIC_INSERTIONSORT_H
