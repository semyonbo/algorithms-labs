#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <vector>

using namespace std;

class Sorters
{
public:
    string name;
    virtual void sort(vector<int> &data) = 0;
    virtual ~Sorters() = default;
    virtual string getName() const = 0;
};

class Quicksort : public Sorters
{
public:
    string name;
    Quicksort() : name("Quicksort") {}

    void sort(vector<int> &data) override
    {
        if (!data.empty())
        {
            quicksort(data, 0, data.size() - 1);
        }
    }
    string getName() const override
    {
        return name;
    }

private:
    void quicksort(vector<int> &data, int low, int high)
    {
        if (low < high)
        {
            int pivotIndex = partition(data, low, high);
            quicksort(data, low, pivotIndex - 1);
            quicksort(data, pivotIndex + 1, high);
        }
    }

    int partition(vector<int> &data, int low, int high)
    {
        int pivot = data[high];
        int i = low - 1;

        for (int j = low; j < high; ++j)
        {
            if (data[j] < pivot)
            {
                ++i;
                swap(data[i], data[j]);
            }
        }

        swap(data[i + 1], data[high]);
        return i + 1;
    }
};

class HeapSort : public Sorters
{
public:
    string name;

    HeapSort() : name("HeapSort") {}

    void sort(vector<int> &data) override
    {
        if (!data.empty())
        {
            heapsort(data);
        }
    }

    string getName() const override
    {
        return name;
    }

private:
    void heapsort(vector<int> &data)
    {
        int n = static_cast<int>(data.size());

        for (int i = n / 2 - 1; i >= 0; --i)
        {
            heapify(data, n, i);
        }

        for (int i = n - 1; i > 0; --i)
        {
            swap(data[0], data[i]);
            heapify(data, i, 0);
        }
    }

    void heapify(vector<int> &data, int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && data[left] > data[largest])
        {
            largest = left;
        }

        if (right < n && data[right] > data[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(data[i], data[largest]);
            heapify(data, n, largest);
        }
    }
};

class MergeSort : public Sorters
{
public:
    string name;

    MergeSort() : name("MergeSort") {}

    void sort(vector<int> &data) override
    {
        if (!data.empty())
        {
            mergeSort(data, 0, static_cast<int>(data.size()) - 1);
        }
    }

    string getName() const override
    {
        return name; 
    }

private:
    void mergeSort(vector<int> &data, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;

            mergeSort(data, left, mid);
            mergeSort(data, mid + 1, right);

            merge(data, left, mid, right);
        }
    }

    void merge(vector<int> &data, int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> leftArr(n1), rightArr(n2);

        for (int i = 0; i < n1; ++i)
            leftArr[i] = data[left + i];
        for (int i = 0; i < n2; ++i)
            rightArr[i] = data[mid + 1 + i];

        int i = 0, j = 0, k = left;


        while (i < n1 && j < n2)
        {
            if (leftArr[i] <= rightArr[j])
            {
                data[k++] = leftArr[i++];
            }
            else
            {
                data[k++] = rightArr[j++];
            }
        }

        while (i < n1)
            data[k++] = leftArr[i++];

        while (j < n2)
            data[k++] = rightArr[j++];
    }
};

// class MergeSort: public Sorters{
// public:
//     string name = "MergeSort";
//     void sort(vector<int>& data) override {
//         mergeSort(data, 0, data.size() - 1);
//     }

// private:
//     void mergeSort(vector<int>& data, int left, int right) {
//         if (left < right) {
//             int mid = left + (right - left) / 2;
//             mergeSort(data, left, mid);
//             mergeSort(data, mid + 1, right);
//             merge(data, left, mid, right);
//         }
//     }

//     void merge(vector<int>& data, int left, int mid, int right) {
//         int n1 = mid - left + 1;
//         int n2 = right - mid;

//         vector<int> leftArr(n1), rightArr(n2);

//         for (int i = 0; i < n1; ++i) leftArr[i] = data[left + i];
//         for (int i = 0; i < n2; ++i) rightArr[i] = data[mid + 1 + i];

//         int i = 0, j = 0, k = left;
//         while (i < n1 && j < n2) {
//             if (leftArr[i] <= rightArr[j]) {
//                 data[k++] = leftArr[i++];
//             } else {
//                 data[k++] = rightArr[j++];
//             }
//         }

//         while (i < n1) data[k++] = leftArr[i++];
//         while (j < n2) data[k++] = rightArr[j++];
//     }
// };

#endif