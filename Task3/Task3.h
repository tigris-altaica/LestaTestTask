#ifndef LESTATESTTASK_TASK3_H
#define LESTATESTTASK_TASK3_H

#include <span>

namespace Task3 {
    
    template <typename T>
    void merge(std::span<T> arr, size_t mid) {
        size_t i = 0, j = mid, k = 0;
        std::vector<T> temp(arr.size());

        while (i < mid && j < arr.size()) {
            if (arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
            }
        }

        while (i < mid) {
            temp[k++] = arr[i++];
        }

        while (j < arr.size()) {
            temp[k++] = arr[j++];
        }

        for (i = 0; i < arr.size(); i++) {
            arr[i] = temp[i];
        }
    }

    /*
     * Сортировка слиянием.
     * Имеет сложность O(n*log(n)) в худшем случае, что лучше, чем O(n^2) в худшем случае у быстрой сортировки.
     */
    template <typename T>
    void mergeSort(std::span<T> arr) {
        if (arr.size() < 2) {
            return;
        }

        size_t mid = arr.size() / 2;

        mergeSort(arr.subspan(0, mid));
        mergeSort(arr.subspan(mid, arr.size() - mid));

        merge(arr, mid);
    }
}

#endif //LESTATESTTASK_TASK3_H
