//
// Created by guoliang on 2018/9/29.
//

#ifndef INC_02_SORTING_BASIC_SORTTESTHELPER_H
#define INC_02_SORTING_BASIC_SORTTESTHELPER_H

#include <iostream>
#include <cassert>
#include <ctime>

using namespace std;

namespace SortTestHelper {
    // generate a randon array, [rangeL, rangeR]
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    int *copyIntArray(int *arr, int n) {
        int *copyArr = new int[n];
        for (int i = 0; i < n; ++i) {
            copyArr[i] = arr[i];
        }
        return copyArr;
    }

    int *generateNearlyOrderedArray(int n, int swapTimes) {
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }
        srand(time(NULL));
        for (int i = 0; i < swapTimes; ++i) {
            int x = rand() % n;
            int y = rand() % n;
            swap(arr[x], arr[y]);
        }
        return arr;
    }

    template<typename T>
    void printArr(T *arr, int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template<typename T>
    bool isSorted(T *arr, int n) {
        for (int i = 0; i + 1 < n; ++i) {
            if (arr[i + 1] < arr[i]) {
                return false;
            }
        }
        return true;
    }

    template<typename T>
    void testSort(const string &sortName, void (*sort)(T *, int), T *arr, int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        assert(isSorted(arr, n));
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        return;
    }
}

#endif //INC_02_SORTING_BASIC_SORTTESTHELPER_H
