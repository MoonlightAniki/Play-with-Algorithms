//
// Created by guoliang on 2018/10/2.
//

#ifndef INC_04_HEAP_SORTTESTHELPER_H
#define INC_04_HEAP_SORTTESTHELPER_H

#include <iostream>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

namespace SortTestHelper {
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        srand(time(NULL));
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    int *generateNearlyOrderedArray(int n, int swapTimes) {
        srand(time(NULL));
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }
        for (int i = 0; i < swapTimes; ++i) {
            int x = rand() % n;
            int y = rand() % n;
            swap(arr[x], arr[y]);
        }
        return arr;
    }

    int *copyIntArray(int *a, int n) {
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = a[i];
        }
        return arr;
    }

    template<typename T>
    bool isSorted(T *arr, int n) {
        for (int i = 0; i + 1 < n; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    template<typename T>
    void testSort(const string &sortName, void (*sort)(T *, int), T *arr, int n) {
        time_t startTime = clock();
        sort(arr, n);
        time_t endTime = clock();

        assert(isSorted(arr, n));
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s." << endl;
    }
}

#endif //INC_04_HEAP_SORTTESTHELPER_H
