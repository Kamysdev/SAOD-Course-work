#pragma once
#include <conio.h>

constexpr auto EXIT_PROGRAM = 0;
constexpr auto RUN_PROGRAM = 1;
constexpr auto SORT_DATABASE = 2;

int GetKeyCommand(int &currentPage);