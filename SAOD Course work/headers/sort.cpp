#include "sort.h"

bool IsEqual(People** index, int position, int largest, int data)
{
    if (index[position]->Date_of_settlement[data] == index[largest]->Date_of_settlement[data])
    {
        return true;
    }
    return false;
}

void heapify(People** index, int size, int i, int phase)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int fnum = 7, snum = 6;
    int fstep = 0, sstep = 8, tstep = 8, fostep = 8;

    switch (phase)
    {
    case 1:
        fnum = 7;
        snum = 6;
        fstep = 8;
        break;
    case 2:
        fnum = 4;
        snum = 3;
        fstep = 7;
        sstep = 6;
        break;
    case 3:
        fnum = 1;
        snum = 0;
        fstep = 4;
        sstep = 3;
        tstep = 7;
        fostep = 6;
        break;
    default:
        break;
    }

    for (int j = fnum; j >= snum; j--)
    {
        if (left < size && index[left]->Date_of_settlement[j] > index[largest]->Date_of_settlement[j]
            && IsEqual(index, left, largest, fstep)
            && IsEqual(index, left, largest, sstep)
            && IsEqual(index, left, largest, tstep)
            && IsEqual(index, left, largest, fostep))
        {
            largest = left;
        }

        if (right < size && index[right]->Date_of_settlement[j] > index[largest]->Date_of_settlement[j]
            && IsEqual(index, right, largest, fstep)
            && IsEqual(index, right, largest, sstep)
            && IsEqual(index, right, largest, tstep)
            && IsEqual(index, right, largest, fostep))
        {
            largest = right;
        }
    }

    if (largest != i)
    {
        std::swap(index[i], index[largest]);
        heapify(index, size, largest, phase);
    }
}

void HeapSort(People** index, int size, int phase)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(index, size, i, phase);

    for (int i = size - 1; i >= 0; i--) 
    {
        std::swap(index[0], index[i]);
        heapify(index, i, 0, phase);
    }
}

//----------------------------------------------------------------//

void heapifyAdress(People** index, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && strcmp(index[left]->Street, index[largest]->Street) > 0
        && strcmp(index[left]->Date_of_settlement, index[largest]->Date_of_settlement) == 0)
    {
        largest = left;
    }

    if (right < size && strcmp(index[right]->Street, index[largest]->Street) > 0
        && strcmp(index[right]->Date_of_settlement, index[largest]->Date_of_settlement) == 0)
    {
        largest = right;
    }

    if (largest != i)
    {
        std::swap(index[i], index[largest]);

        heapifyAdress(index, size, largest);
    }
}

void HeapSortAdress(People** index, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapifyAdress(index, size, i);

    for (int i = size - 1; i >= 0; i--)
    {
        std::swap(index[0], index[i]);
        heapifyAdress(index, i, 0);
    }
}

void GetIndexArr(People** index, People* list, int listsize)
{
    for (int i = 0; i < listsize; i++)
    {
        index[i] = &list[i];
    }
}

void Sort(People** index, int size)
{
    HeapSort(index, size, 1);
    HeapSort(index, size, 2);
    HeapSort(index, size, 3);
    HeapSortAdress(index, size);
}