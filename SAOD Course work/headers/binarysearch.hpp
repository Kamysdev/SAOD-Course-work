#pragma once
#include "read.hpp"
#include "Control.hpp"

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

MyQueue BinarySearch(People** indexArr, const std::string& targetKey);