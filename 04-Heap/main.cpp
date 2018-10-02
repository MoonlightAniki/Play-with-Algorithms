#include <iostream>
#include "HeapSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "SortTestHelper.h"

using namespace std;

int main() {
//    MaxHeap<int> maxHeap = MaxHeap<int>(100);
//    srand(time(NULL));
//    for (int i = 0; i < 10; ++i) {
//        maxHeap.insert(rand() % 100);
//    }
//    while (!maxHeap.isEmpty()) {
//        int max = maxHeap.extractMax();
//        cout << max << " ";
//    }
//    cout << endl;


    int n = 10000000;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);
    int *arr5 = SortTestHelper::copyIntArray(arr1, n);
    int *arr6 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Shell Sort", ShellSort::shellSort, arr1, n);
    SortTestHelper::testSort("Heap Sort", HeapSort::heapSort, arr2, n);
    SortTestHelper::testSort("Heap Sort 2", HeapSort::heapSort2, arr3, n);
    SortTestHelper::testSort("Heap Sort 3", HeapSort::heapSort3, arr4, n);
    SortTestHelper::testSort("Heap Sort 4", HeapSort::heapSort4, arr5, n);
    SortTestHelper::testSort("Merge Sort", MergeSort::mergeSortBU3, arr6, n);//最快的归并排序


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    return 0;
}