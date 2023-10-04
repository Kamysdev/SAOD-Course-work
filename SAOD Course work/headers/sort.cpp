#include "sort.hpp"

std::string GetStringData(People* index)
{
    std::string data;
    data.push_back(index->Date_of_settlement[6]);
    data.push_back(index->Date_of_settlement[7]);
    data.push_back(index->Date_of_settlement[3]);
    data.push_back(index->Date_of_settlement[4]);
    data.push_back(index->Date_of_settlement[0]);
    data.push_back(index->Date_of_settlement[1]);

    return data;
}

////----------------------------------------------------------------//

void heapify(People** index, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size 
        && (std::stoi(GetStringData(index[left])) > std::stoi(GetStringData(index[largest])) 
        || (std::stoi(GetStringData(index[left])) == std::stoi(GetStringData(index[largest])) 
        && strcmp(index[left]->Street, index[largest]->Street) > 0)))
    {
        largest = left;
    }

    if (right < size 
        && (std::stoi(GetStringData(index[right])) > std::stoi(GetStringData(index[largest])) 
        || (std::stoi(GetStringData(index[right])) == std::stoi(GetStringData(index[largest]))
        && strcmp(index[right]->Street, index[largest]->Street) > 0)))
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

//----------------------------------------------------------------//

void GetIndexArr(People** index, People* list, int listsize)
{
    for (int i = 0; i < listsize; i++)
    {
        index[i] = &list[i];
    }
}

void Sort(People** index, int size)
{
    HeapSort(index, size);
}