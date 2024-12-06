#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <vector>

using namespace std;

class  Quicksort {
public:
    string name = "Quicksort";
    static void sort(vector<int>& data) {
        quicksort(data, 0, data.size() - 1);
    }

private:
    static void quicksort(vector<int>& data, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(data, low, high);
            quicksort(data, low, pivotIndex - 1);
            quicksort(data, pivotIndex + 1, high);
        }
    }

    static int partition(vector<int>& data, int low, int high) {
        int pivot = data[high]; 
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (data[j] < pivot) {
                ++i;
                swap(data[i], data[j]);
            }
        }
        swap(data[i + 1], data[high]);
        return i + 1;
    }
};



#endif 