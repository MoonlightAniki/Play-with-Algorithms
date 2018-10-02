cmake_minimum_required(VERSION 3.8)
project(04_Heap)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MaxHeap.h HeapSort.h SortTestHelper.h ShellSort.h MergeSort.h InsertionSort.h)
add_executable(04_Heap ${SOURCE_FILES})