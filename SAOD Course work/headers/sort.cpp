#include "sort.h"

void heapify(People* arr, int* index, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && strcmp(arr[index[left]].Street, arr[index[largest]].Street) > 0)
    {
        largest = left;
    }

    if (right < size && strcmp(arr[index[right]].Street, arr[index[largest]].Street) > 0)
    {
        largest = right;
    }

    if (largest != i)
    {
        std::swap(index[i], index[largest]);

        heapify(arr, index, size, largest);
    }
}

void heapSort(People* arr, int* index, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, index, size, i);

    for (int i = size - 1; i >= 0; i--) 
    {
        std::swap(index[0], index[i]);
        heapify(arr, index, i, 0);
    }
}
