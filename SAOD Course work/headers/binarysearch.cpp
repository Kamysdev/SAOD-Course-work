#include "binarysearch.hpp"

const char& GetDate(People** indexArr, int pos)
{
    std::string currentDate{};
    currentDate.push_back(indexArr[pos]->Date_of_settlement[6]);
    currentDate.push_back(indexArr[pos]->Date_of_settlement[7]);

    char date[1]{};
    strcpy(date, currentDate.c_str());

    return *date;
}

MyQueue BinarySearch(People** indexArr, const std::string& targetKey)
{
    MyQueue result;

    int arrSize = 4000;
    int left = 0;
    int right = arrSize - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        std::string key{};
        key.push_back(indexArr[mid]->Date_of_settlement[6]);
        key.push_back(indexArr[mid]->Date_of_settlement[7]);

        if (key == targetKey)
        {
            result.push(indexArr[mid]);

            int leftIndex = mid - 1;
            while (leftIndex >= 0 && strcmp(&GetDate(indexArr, leftIndex), targetKey.c_str()) == 0)
            {
                result.push(indexArr[leftIndex]);
                leftIndex--;
            }

            int rightIndex = mid + 1;
            while (rightIndex < arrSize && strcmp(&GetDate(indexArr, rightIndex), targetKey.c_str()) == 0)
            {
                result.push(indexArr[rightIndex]);
                rightIndex++;
            }

            return result;
        }
        else if (key < targetKey)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return result;
}

void MyQueue::push(People* data)
{
    node* newNode = new node;
    newNode->data = data;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

bool MyQueue::empty() const
{
    return !head;
}

People* MyQueue::front() const
{
    if (head) 
    {
        return head->data;
    }
    throw std::runtime_error("Queue is empty");
}

void MyQueue::pop()
{
    if (head) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

int MyQueue::size() const
{
    int count = 0;
    node* current = head;
    while (current) 
    {
        count++;
        current = current->next;
    }
    return count;
}
