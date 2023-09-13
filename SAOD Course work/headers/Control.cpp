#include "Control.h"

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
