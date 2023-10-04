#include "headers/read.hpp"
#include "headers/display.hpp"
#include "headers/sort.hpp"

#ifdef _WIN32
#include <Windows.h>
#endif

// 141 variant

int main(int *argc, char **argv) 
{
	system("color 1f");										// Set color of console
	int currentPage = 0;
	int programStatus = 1;
	int arrsize = 4000;
	std::string findYear{};
	People* peoplelist = new People[arrsize];
	People** index = new People*[arrsize];

	MyQueue result{};

	GetData(peoplelist);									// Load DB
	GetIndexArr(index, peoplelist, arrsize);				// Get Index

	while (programStatus != EXIT_PROGRAM)					// Main body of program
	{
		displayTable(peoplelist, index, currentPage);
		programStatus = GetKeyCommand(currentPage);

		switch (programStatus)								// Switch 
		{
		case SORT_DATABASE:
			Sort(index, arrsize);
			break;
		case GET_DEFAULT:
			GetIndexArr(index, peoplelist, arrsize);
			break;
		case FIND_POS:
			currentPage = GetPageByPos(DisplayFind_border());
			break;
		case BINARY_SEARCH:
			std::cout << std::endl << "Enter year: ";
			std::cin >> findYear;
			result = BinarySearch(index, findYear);
			if (result.empty())
			{
				std::cout << "No one record!";
				Sleep(500);
				break;
			}
			else
			{
				while (programStatus == RUN_PROGRAM || programStatus == BINARY_SEARCH)
				{
					system("cls");
					printQueue(result, currentPage);
					programStatus = GetKeyCommand(currentPage);
				}
			}
			break;
		default:
			break;
		}
		system("CLS");
	}

	return 0;
}