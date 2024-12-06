#ifndef SORTTESTER_H
#define SORTTESTER_H

#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

class SortTester {
public:
    static vector<int> generateData(size_t size, int max_value) {
        vector<int> data(size);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(0, max_value);

        for (size_t i = 0; i < size; ++i) {
            data[i] = dist(gen);
        }
        return data;
    }

    static void testSortingAlgorithms(vector<int> data, auto& sorter) {
        auto tempData = data;
        auto start = chrono::high_resolution_clock::now();
        sorter.sort(tempData);
        auto end = chrono::high_resolution_clock::now();
        cout << name << " sorted in " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms.\n";
    }
};


#endif 