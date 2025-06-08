#pragma once

#include <vector>
#include <algorithm>
#include "Constants.h"
#include "IDataStructure.h" 

template<typename T>
class TimSort {
public:
    void sort(IDataStructure<T>* arr);

private:
    void insertionSort(IDataStructure<T>* arr, int left, int right);
    void merge(IDataStructure<T>* arr, int l, int m, int r);
};