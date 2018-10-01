//
// Created by guoliang on 2018/10/1.
//

#ifndef INC_03_SORTING_ADVANCE_QUICKSORT_H
#define INC_03_SORTING_ADVANCE_QUICKSORT_H

#include <iostream>
#include <ctime>

using namespace std;
namespace QuickSort {
    template<typename T>
    int __partition(T *arr, int l, int r) {
        T v = arr[l];

        int i = l + 1;//当前正在被考察的元素
        int p = l;//arr[l+1...p]<v, arr[p+1...i)>=v
        for (; i <= r; ++i) {
            if (arr[i] < v) {
                swap(arr[p + 1], arr[i]);
                ++p;
            }
        }
        swap(arr[l], arr[p]);
        return p;
    }


    template<typename T>
    void __quickSort(T *arr, int l, int r) {
        if (l >= r) {
            return;
        }

        int p = __partition(arr, l, r);
        __quickSort(arr, l, p - 1);
        __quickSort(arr, p + 1, r);
    }


    template<typename T>
    void quickSort(T *arr, int n) {
        __quickSort(arr, 0, n - 1);
    }


    template<typename T>
    int __partition2(T *arr, int l, int r) {
        swap(arr[l], arr[rand() % (r - l + 1) + l]);
        T v = arr[l];
        int p = l;
        for (int i = l + 1; i <= r; ++i) {
            if (arr[i] < v) {
                swap(arr[p + 1], arr[i]);
                ++p;
            }
        }
        swap(arr[l], arr[p]);
        return p;
    }

    template<typename T>
    void __quickSort2(T *arr, int l, int r) {
        if (l >= r) {
            return;
        }
        int p = __partition2(arr, l, r);
        __quickSort2(arr, l, p - 1);
        __quickSort2(arr, p + 1, r);
    }


    template<typename T>
    void quickSort2(T *arr, int n) {
        srand(time(NULL));
        __quickSort2(arr, 0, n - 1);
    }


    template<typename T>
    int __partition3(T *arr, int l, int r) {
        swap(arr[l], arr[rand() % (r - l + 1) + l]);
        T v = arr[l];
        int i = l + 1;//arr[l+1...i)<v
        int j = r;//arr(j...r]>v
        while (true) {
            while (i <= r && arr[i] < v) ++i;
            while (j >= l + 1 && arr[j] > v) --j;
            if (i >= j) break;
            swap(arr[i], arr[j]);
            ++i;
            --j;
        }
        swap(arr[l], arr[j]);
        return j;
    }

    template<typename T>
    void __quickSort2Ways(T *arr, int l, int r) {
        if (l >= r) {
            return;
        }

        int p = __partition3(arr, l, r);
        __quickSort2Ways(arr, l, p - 1);
        __quickSort2Ways(arr, p + 1, r);
    }


    template<typename T>
    void quickSort2Ways(T *arr, int n) {
        srand(time(NULL));
        __quickSort2Ways(arr, 0, n - 1);
    }


    template<typename T>
    void __partition4(T *arr, int l, int r, int &lt, int &gt) {
        swap(arr[l], arr[rand() % (r - l + 1) + l]);
        T v = arr[l];
        lt = l;//arr[l+1...lt]<v
        gt = r + 1;//arr[gt...r]>v
        int i = l + 1;//arr[lt+1...i)==v
        while (i < gt) {
            if (arr[i] < v) {
                swap(arr[lt + 1], arr[i]);
                ++lt;
                ++i;
            } else if (arr[i] > v) {
                swap(arr[i], arr[gt - 1]);
                --gt;
            } else {//arr[i]==v
                ++i;
            }
        }
        swap(arr[l], arr[lt]);
        --lt;
    }


    template<typename T>
    void __quickSort3Ways(T *arr, int l, int r) {
        if (l >= r) {
            return;
        }
        int lt;
        int gt;
        __partition4(arr, l, r, lt, gt);
        __quickSort3Ways(arr, l, lt);
        __quickSort3Ways(arr, gt, r);
    }

    template<typename T>
    void quickSort3Ways(T *arr, int n) {
        srand(time(NULL));
        __quickSort3Ways(arr, 0, n - 1);
    }
}
#endif //INC_03_SORTING_ADVANCE_QUICKSORT_H
