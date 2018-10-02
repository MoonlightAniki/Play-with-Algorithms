//
// Created by guoliang on 2018/10/2.
//

#ifndef INC_04_HEAP_HEAPSORT_H
#define INC_04_HEAP_HEAPSORT_H

#include <iostream>
#include "MaxHeap.h"

using namespace std;
namespace HeapSort {
    template<typename T>
    void heapSort(T *arr, int n) {
        MaxHeap<T> mh = MaxHeap<T>(n);
        for (int i = 0; i < n; ++i) {
            mh.insert(arr[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            arr[i] = mh.extractMax();
        }
    }

    template<typename T>
    void heapSort2(T *arr, int n) {
        MaxHeap<int> mh = MaxHeap<int>(arr, n);
        for (int i = n - 1; i >= 0; --i) {
            arr[i] = mh.extractMax();
        }
    }

    template<typename T>
    void shiftDown(T *arr, int n, int k) {
        // 存在左孩子
        while (2 * k + 1 < n) {
            int j = 2 * k + 1;
            if (j + 1 < n && arr[j + 1] > arr[j]) {
                ++j;
            }
            if (arr[j] <= arr[k]) {
                break;
            }
            swap(arr[k], arr[j]);
            k = j;
        }
    }

    // 原地堆排序
    template<typename T>
    void heapSort3(T *arr, int n) {
        // heapify
        for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
            shiftDown(arr, n, i);
        }
        for (int i = n - 1; i >= 0; --i) {
            swap(arr[0], arr[i]);
            shiftDown(arr, i, 0);
        }
    }

    // 使用赋值代替swap
    template<typename T>
    void shiftDown2(T *arr, int n, int k) {
        T e = arr[k];
        while (2 * k + 1 < n) {
            int j = 2 * k + 1;
            if (j + 1 < n && arr[j + 1] > arr[j]) {
                ++j;
            }
            if (arr[j] <= e) {
                break;
            }
            arr[k] = arr[j];
            k = j;
        }
        arr[k] = e;
    }

    // 原地堆排序，shiftDown时使用赋值代替swap进行优化
    template<typename T>
    void heapSort4(T *arr, int n) {
        for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
            shiftDown2(arr, n, i);
        }
        for (int i = n - 1; i >= 0; --i) {
            swap(arr[0], arr[i]);
            shiftDown2(arr, i, 0);
        }
    }
}

#endif //INC_04_HEAP_HEAPSORT_H

// 推排序的优化思路：
// 1. Heapify
// 2. 原地排序
// 3. shiftDown操作时使用赋值代替swap，与插入排序的优化思路一致
