//
// Created by guoliang on 2018/10/2.
//

#ifndef INC_04_HEAP_MAXHEAP_H
#define INC_04_HEAP_MAXHEAP_H

#include <cassert>
#include <iostream>

using namespace std;

template<typename Item>
class MaxHeap {
private:
    int count;
    int capacity;
    Item *data;
public:
    MaxHeap(int capacity) {
        data = new Item[1 + capacity];
        count = 0;
        this->capacity = capacity;
    }

    MaxHeap(Item *arr, int n) {
        data = new Item[1 + n];
        capacity = n;
        for (int i = 0; i < n; ++i) {
            data[i] = arr[i];
        }
        count = n;
        // Heapify
        for (int i = count / 2; i >= 1; --i) {
            shiftDown(i);
        }
    }

    // 析构函数
    virtual ~MaxHeap() {
        delete[] data;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Item item) {
        assert(count + 1 <= capacity);
        data[count + 1] = item;
        ++count;
        shiftUp(count);
    }

    Item extractMax() {
        assert(count >= 1);
        Item max = data[1];
        swap(data[1], data[count]);
        --count;
        shiftDown(1);
        return max;
    }

    Item getMax() {
        assert(count > 0);
        return data[1];
    }

private:
    void shiftUp(int k) {
        // 存在父节点并且父节点小于当前节点
        while (k / 2 >= 1 && data[k / 2] < data[k]) {
            swap(data[k / 2], data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k) {
        // 存在左孩子
        while (k * 2 <= count) {
            int j = 2 * k;
            // 存在右孩子并且右孩子比左孩子大
            if (j + 1 <= count && data[j + 1] > data[j]) {
                ++j;
            }
            if (data[j] <= data[k]) {
                break;
            }
            swap(data[k], data[j]);
            k = j;
        }
    }
};

#endif //INC_04_HEAP_MAXHEAP_H
