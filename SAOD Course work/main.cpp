#include "headers/read.hpp"
#include "headers/display.hpp"
#include "headers/sort.hpp"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// 141 variant

int ShowBinarySearch(People** index, int programStatus, int currentPage)
{
	std::string findYear{};
	MyQueue result{};

	std::cout << std::endl << "Enter year: ";
	std::cin >> findYear;

	result = BinarySearch(index, findYear);
	if (result.empty())
	{
		system("cls");
		std::cout << std::endl << "\t\t\t\t\t\tNo one record!";
		Sleep(2000);
		return 1;
	}
	else
	{
		while (programStatus == RUN_PROGRAM)
		{
			system("cls");
			printQueue(result, currentPage);
			programStatus = GetKeyCommand(currentPage);
			if (currentPage < 0)
			{
				currentPage++;
			}
		}
	}

	return 0;
}

int main(int *argc, char **argv) 
{
	system("color 1f");										// Set color of console
	int currentPage = 0;
	int programStatus = 1;
	int arrsize = 4000;
	

	People* peoplelist = new People[arrsize];
	People** index = new People*[arrsize];

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
			programStatus = RUN_PROGRAM;
			ShowBinarySearch(index, programStatus, currentPage);
			break;
		default:
			break;
		}
		system("CLS");
	}

	return 0;
}