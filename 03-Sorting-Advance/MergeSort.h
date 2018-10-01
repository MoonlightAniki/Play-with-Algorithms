//
// Created by guoliang on 2018/10/1.
//

#ifndef INC_03_SORTING_ADVANCE_MERGESORT_H
#define INC_03_SORTING_ADVANCE_MERGESORT_H

#include <iostream>
#include "InsertionSort.h"

using namespace std;
namespace MergeSort {

    // 对arr[l...mid]和arr[mid+1...r]两部分进行归并
    template<typename T>
    void __merge(T *arr, int l, int mid, int r) {
        int *aux = new T[r - l + 1];//辅助数组
        for (int i = l; i <= r; ++i) {
            aux[i - l] = arr[i];//注意aux的偏移量
        }
        int i = l;
        int j = mid + 1;
        for (int k = l; k <= r; ++k) {
            if (i > mid) {
                arr[k] = aux[j - l];
                ++j;
            } else if (j > r) {
                arr[k] = aux[i - l];
                ++i;
            } else if (aux[i - l] < aux[j - l]) {
                arr[k] = aux[i - l];
                ++i;
            } else {
                arr[k] = aux[j - l];
                ++j;
            }
        }
        delete[] aux;
    }


    // 对arr[l...r]范围内的元素进行归并排序
    template<typename T>
    void __mergeSort(T *arr, int l, int r) {
//        if (l >= r) {
//            return;
//        }
        // 元素较少时，使用插入排序效率更高
        if (r - l <= 15) {//16个元素
            InsertionSort::__insertionSort(arr, l, r);
            return;
        }

        int mid = l + (r - l) / 2;
        __mergeSort(arr, l, mid);
        __mergeSort(arr, mid + 1, r);
        if (arr[mid] > arr[mid + 1]) {
            __merge(arr, l, mid, r);
        }
    }


    // 自顶向下的归并排序
    template<typename T>
    void mergeSort(T *arr, int n) {
        int l = 0, r = n - 1;
        __mergeSort(arr, l, r);
    }

    // 自底向上的归并排序
    template<typename T>
    void mergeSortBU(T *arr, int n) {
        for (int sz = 1; sz < n; sz += sz) {
            // 每次对2*sz个元素进行归并
            // arr[i...i+sz-1] 和 arr[i+sz...i+2*sz-1]
            // 为了保证第二部分存在 需要满足 i+sz<n
            // 为了防止第二部分右边界i+2*sz-1越界，有边界取min(i+2*sz-1, n-1)
            for (int i = 0; i + sz < n; i += 2 * sz) {
                if (arr[i + sz - 1] > arr[i + sz]) {
                    __merge(arr, i, i + sz - 1, min(i + 2 * sz - 1, n - 1));
                }
            }
        }
    }


    // 对自底向上的归并排序使用插入排序进行优化
    template<typename T>
    void mergeSortBU2(T *arr, int n) {
        for (int i = 0; i < n; i += 16) {
            InsertionSort::__insertionSort(arr, i, min(i + 15, n - 1));
        }
        for (int sz = 16; sz < n; sz += sz) {
            for (int i = 0; i + sz < n; i += 2 * sz) {
                if (arr[i + sz - 1] > arr[i + sz]) {
                    __merge(arr, i, i + sz - 1, min(i + 2 * sz - 1, n - 1));
                }
            }
        }
    }

    template<typename T>
    void __merge2(T *arr, T *aux, int l, int mid, int r) {
        for (int i = l; i <= r; ++i) {
            aux[i] = arr[i];
        }
        int i = l;
        int j = mid + 1;
        for (int k = l; k <= r; ++k) {
            if (i > mid) {
                arr[k] = aux[j];
                ++j;
            } else if (j > r) {
                arr[k] = aux[i];
                ++i;
            } else if (aux[i] < aux[j]) {
                arr[k] = aux[i];
                ++i;
            } else {
                arr[k] = aux[j];
                ++j;
            }
        }
    }

    template<typename T>
    void __mergeSort2(T *arr, T *aux, int l, int r) {
//        if (l >= r) {
//            return;
//        }
        if (r - l <= 15) {
            InsertionSort::__insertionSort(arr, l, r);
            return;
        }
        int mid = l + (r - l) / 2;
        __mergeSort2(arr, aux, l, mid);
        __mergeSort2(arr, aux, mid + 1, r);
        if (arr[mid] > arr[mid + 1]) {
            __merge2(arr, aux, l, mid, r);
        }
    }


    // 只创建一个辅助数组进行自顶向下的归并排序
    template<typename T>
    void mergeSort2(T *arr, int n) {
        T *aux = new T[n];
        __mergeSort2(arr, aux, 0, n - 1);
        delete[] aux;
    }

    // 只创建一个辅助数组进行自底向上的归并排序
    template<typename T>
    void mergeSortBU3(T *arr, int n) {
        for (int i = 0; i < n; i += 16) {
            InsertionSort::__insertionSort(arr, i, min(i + 15, n - 1));
        }
        T *aux = new T[n];
        for (int sz = 16; sz < n; sz += sz) {
            for (int i = 0; i + sz < n; i += 2 * sz) {
                if (arr[i + sz - 1] > arr[i + sz]) {
                    __merge2(arr, aux, i, i + sz - 1, min(i + 2 * sz - 1, n - 1));
                }
            }
        }
        delete[] aux;
    }
}

#endif //INC_03_SORTING_ADVANCE_MERGESORT_H
// 归并排序的优化方案：
// 1. 进行归并之前先检查第一部分的最大元素是否大于第二部分的最小元素，如果是才进行归并
// 2. 元素较少时使用插入排序
// 3. 只创建一个辅助数组，减少数组创建和销毁的额外时间


// 自底向上的归并排序比自顶向下的归并排序更快，因为没有使用递归