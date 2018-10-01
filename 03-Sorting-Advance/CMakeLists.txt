cmake_minimum_required(VERSION 3.8)
project(03_Sorting_Advance)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SortTestHelper.h InsertionSort.h ShellSort.h MergeSort.h QuickSort.h)
add_executable(03_Sorting_Advance ${SOURCE_FILES})