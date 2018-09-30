cmake_minimum_required(VERSION 3.8)
project(02_Sorting_Basic)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main001.cpp main002.cpp Student.h SortTestHelper.h main003.cpp SelectionSort.h InsertionSort.h BubbleSort.h ShellSort.h)
add_executable(02_Sorting_Basic ${SOURCE_FILES})