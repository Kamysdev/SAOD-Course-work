#pragma once
#include "Control.hpp"
#include <iostream>

int GetKeyCommand(int &currentPage)
{
    int key = _getch();

	switch (key)
	{
	case 77:
		currentPage++;
		break;
	case 75:
		currentPage--;
		break;
	case 27:
		return EXIT_PROGRAM;
	case 115:
		return SORT_DATABASE;
	case 97:
		return GET_DEFAULT;
	case 112:
		return FIND_POS;
	case 102:
		return BINARY_SEARCH;
	case 116:
		return BTREE;
	case 99:
		return CODING;
	default:
		break;
	}

	if (currentPage < 0)
	{
		currentPage = 199;
	}
	if (currentPage > 199)
	{
		currentPage = 0;
	}

    return RUN_PROGRAM;
}

int GetPageByPos(int pos)
{
	int page = (int)((pos) / 20);

	return page;
}