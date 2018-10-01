//
// Created by guoliang on 2018/10/1.
//

#ifndef INC_03_SORTING_ADVANCE_SORTTESTHELPER_H
#define INC_03_SORTING_ADVANCE_SORTTESTHELPER_H

#include <iostream>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

namespace SortTestHelper {

    // 生成随机int数组，数组元素的取值范围[rangeL,rangeR]
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        srand(time(NULL));//生成随机种子
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    // 生成近乎有序的int数组
    int *generateNearlyRandomArray(int n, int swapTimes) {
        srand(time(NULL));//生成随机种子
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }
        for (int i = 0; i < swapTimes; ++i) {
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
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

    // 判断数组是否有序
    template<typename T>
    bool isSorted(T *arr, int n) {
        for (int i = 0; i + 1 < n; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    // 测试排序算法性能
    template<typename T>
    void testSort(const string &sortName, void (*sort)(T *, int), T *arr, int n) {
        time_t startTime = clock();
        sort(arr, n);
        time_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s." << endl;
    }
}

#endif //INC_03_SORTING_ADVANCE_SORTTESTHELPER_H
