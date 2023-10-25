#pragma once
#include <iostream>
#include "read.hpp"
#include "Control.hpp"
#include "binarysearch.hpp"
#include "btree.hpp"

int displayTable(People* peoplelist, People** index, int &current_page, bool sorted);

int DisplayFind_border();

void printQueue(const MyQueue& result, int currentPage);

MyQueue ShowBinarySearch(People** index, int programStatus, int& currentPage);