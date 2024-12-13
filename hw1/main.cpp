#include "SortTester.h"
#include <iostream>
#include <vector>
#include <chrono>
#include "algorithms.h"

using namespace std;    
using namespace chrono;

int main() {
    Quicksort quiqsort;
    HeapSort heapsort;
    MergeSort mergesort;

    vector<int> data = SortTester::generateData(100000, 100000);
    vector<int> test_data = data;
    
    SortTester::testSortingAlgorithms(data, quiqsort);
    SortTester::testSortingAlgorithms(data, heapsort);
    SortTester::testSortingAlgorithms(data, mergesort);

    // auto start = high_resolution_clock::now();


    // mergesort.sort(data);

    // auto end = high_resolution_clock::now();

    // auto duration = duration_cast<microseconds>(end - start);

    // cout << "Время выполнения: " << duration.count() << " микросекунд" << endl;



    // for (size_t i = 0; i < 10; i++) {
    //     cout << data[i] <<" | " << test_data[i] << endl;

    // }
    


    return 0;
}
