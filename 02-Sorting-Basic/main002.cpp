//
// Created by guoliang on 2018/9/29.
//
#include <iostream>
#include "Student.h"

using namespace std;

template<typename T>
void selectionSort(T *arr, int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[minIndex], arr[i]);
        }
    }
}

int main002() {
    Student s[4] = {
            {"A", 100},
            {"B", 90},
            {"C", 90},
            {"D", 80}
    };
    selectionSort(s, 4);
    for (int i = 0; i < 4; ++i) {
        cout << s[i] << endl;
    }
    return 0;
}

