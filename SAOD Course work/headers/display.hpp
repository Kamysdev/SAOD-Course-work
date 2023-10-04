#pragma once
#include <iostream>
#include "read.hpp"
#include "Control.hpp"
#include "binarysearch.hpp"

int displayTable(People* peoplelist, People** index, int &current_page);

int DisplayFind_border();

void printQueue(const MyQueue& result, int currentPage);

int ShowBinarySearch(People** index, int programStatus, int& currentPage);