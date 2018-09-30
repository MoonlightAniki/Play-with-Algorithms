//
// Created by guoliang on 2018/9/29.
//

#ifndef INC_02_SORTING_BASIC_BUBBLESORT_H
#define INC_02_SORTING_BASIC_BUBBLESORT_H

#include <iostream>

using namespace std;
namespace BubbleSort {
    // V1
    template<typename T>
    void bubbleSort1(T *arr, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j + 1 < n - i; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    //V2
    template<typename T>
    void bubbleSort2(T *arr, int n) {
        while (n > 1) {
            for (int i = 0; i + 1 < n; ++i) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                }
            }
            --n;
        }
    }

    // V3
    template<typename T>
    void bubbleSort3(T *arr, int n) {
        bool swaped;
        do {
            swaped = false;
            for (int i = 0; i + 1 < n; ++i) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                    swaped = true;
                }
            }
            --n;
        } while (swaped);
    }
}

#endif //INC_02_SORTING_BASIC_BUBBLESORT_H
