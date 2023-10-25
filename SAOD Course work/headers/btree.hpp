#pragma once
#include "binarysearch.hpp"
#include <iostream>
#include <vector>

struct BTree {
    std::vector<MyQueue> data;
    int balance;
    BTree* left;
    BTree* right;

    BTree();
};

void InsertInBTree(MyQueue& data, BTree*& root, bool& VR, bool& HR);

void InOrderTraversal(BTree* root, int& counter);