#pragma once
#include <conio.h>

constexpr auto EXIT_PROGRAM = 0;
constexpr auto RUN_PROGRAM = 1;
constexpr auto SORT_DATABASE = 2;
constexpr auto GET_DEFAULT = 3;
constexpr auto FIND_POS = 4;
constexpr auto BINARY_SEARCH = 5;

int GetKeyCommand(int &currentPage);

int GetPageByPos(int pos);