#pragma once
#include "read.hpp"

struct node 
{
    People* data;
    node* next;
};

struct MyQueue
{
    node* head;
    node* tail;

    MyQueue() : head(nullptr), tail(nullptr) {}

    void push(People* data);

    bool empty() const;

    People* front() const;

    void pop();

    int size() const;
};

std::string GetDate(People** indexArr, int pos);

MyQueue BinarySearch(People** indexArr, const std::string& targetKey);