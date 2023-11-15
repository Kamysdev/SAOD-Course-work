#include "headers/read.hpp"
#include "headers/display.hpp"
#include "headers/sort.hpp"
#include "headers/btree.hpp"
#include "headers/code.hpp"

// 141 variant

int main(int *argc, char **argv) 
{
	system("color 1f");										// Set color of console
	int currentPage = 0;
	int programStatus = 1;
	int arrsize = 4000;
	bool sorted = false;

	People* peoplelist = new People[arrsize];
	People** index = new People*[arrsize];

	MyQueue result{};

	GetData(peoplelist);									// Load DB
	GetIndexArr(index, peoplelist, arrsize);				// Get Index

	while (programStatus != EXIT_PROGRAM)					// Main body of program
	{
		displayTable(peoplelist, index, currentPage, sorted);
		programStatus = GetKeyCommand(currentPage);

		switch (programStatus)								// Switch 
		{
		case SORT_DATABASE:
			Sort(index, arrsize);
			sorted = true;
			break;
		case GET_DEFAULT:
			GetIndexArr(index, peoplelist, arrsize);
			sorted = false;
			break;
		case FIND_POS:
			currentPage = GetPageByPos(DisplayFind_border());
			break;
		case BINARY_SEARCH:
			programStatus = RUN_PROGRAM;
			result = ShowBinarySearch(index, programStatus, currentPage);
			break;
		case CODING:
			coding();
		default:
			break;
		}
		system("CLS");
	}

	return 0;
}