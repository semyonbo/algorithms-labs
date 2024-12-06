#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include <vector>

using namespace std;

class HeapSort {
public:
    string name = "HeapSort";
    static void sort(std::vector<int>& data) {
        int n = data.size();

        for (int i = n / 2 - 1; i >= 0; --i) {
            heapify(data, n, i);
        }

        for (int i = n - 1; i > 0; --i) {
            swap(data[0], data[i]); 
            heapify(data, i, 0); 
        }
    }

private:
    static void heapify(vector<int>& data, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && data[left] > data[largest]) largest = left;
        if (right < n && data[right] > data[largest]) largest = right;

        if (largest != i) {
            swap(data[i], data[largest]);
            heapify(data, n, largest);
        }
    }
};


#endif 