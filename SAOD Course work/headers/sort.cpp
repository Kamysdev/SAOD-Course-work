#include "sort.h"

void heapify(People** index, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && strcmp(index[left]->Street, index[largest]->Street) > 0)
    {
        largest = left;
    }

    if (right < size && strcmp(index[right]->Street, index[largest]->Street) > 0)
    {
        largest = right;
    }

    if (largest != i)
    {
        std::swap(index[i], index[largest]);

        heapify(index, size, largest);
    }
}

void HeapSort(People** index, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(index, size, i);

    for (int i = size - 1; i >= 0; i--) 
    {
        std::swap(index[0], index[i]);
        heapify(index, i, 0);
    }
}

void GetIndexArr(People** index, People* list, int listsize)
{
    for (int i = 0; i < listsize; i++)
    {
        index[i] = &list[i];
    }
}