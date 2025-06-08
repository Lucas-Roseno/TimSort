#include "TimSort.h"
#include "Timestamp.h"
#include <algorithm>
#include <vector>

template<typename T>
void TimSort<T>::insertionSort(IDataStructure<T>* arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        T temp = arr->get(i);
        int j = i - 1;
        while (j >= left && arr->get(j) > temp) {
            arr->set(j + 1, arr->get(j));
            j--;
        }
        arr->set(j + 1, temp);
    }
}

template<typename T>
void TimSort<T>::merge(IDataStructure<T>* arr, int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    std::vector<T> left(len1), right(len2);

    for (int i = 0; i < len1; i++)
        left[i] = arr->get(l + i);
    for (int i = 0; i < len2; i++)
        right[i] = arr->get(m + 1 + i);

    int i = 0, j = 0, k = l;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr->set(k++, left[i++]);
        } else {
            arr->set(k++, right[j++]);
        }
    }

    while (i < len1) {
        arr->set(k++, left[i++]);
    }

    while (j < len2) {
        arr->set(k++, right[j++]);
    }
}

template<typename T>
void TimSort<T>::sort(IDataStructure<T>* arr) {
    int n = arr->size();
    if (n <= 1) return;

    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, std::min((i + RUN - 1), (n - 1)));

    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (n - 1));

            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

template class TimSort<Timestamp>;