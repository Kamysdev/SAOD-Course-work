#include "headers/read.h"
#include "headers/display.h"
#include "headers/sort.h"

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
		Display_table(peoplelist, index, currentPage);
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
		default:
			break;
		}
		system("CLS");
	}

	return 0;
}