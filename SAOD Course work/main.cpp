#include "headers/read.h"
#include "headers/display.h"
#include "headers/sort.h"
#include <windows.h>

int main(int *argc, char **argv) 
{
	system("color 1f");										// Set color of console

	int current_page = 0;
	int programStatus = 1;
	int arrsize = 4000;
	People* peoplelist = new People[arrsize];
	People** index = new People*[arrsize];

	GetData(peoplelist);									// Load DB
	GetIndexArr(index, peoplelist, arrsize);				// Get Index

	while (programStatus != EXIT_PROGRAM)					// Main body of program
	{
		Display_table(peoplelist, index, current_page);
		programStatus = GetKeyCommand(current_page);
		system("CLS");

		switch (programStatus)
		{
		case SORT_DATABASE:
			Sort(index, arrsize);
			break;
		case GET_DEFAULT:
			GetIndexArr(index, peoplelist, arrsize);
			break;
		default:
			break;
		}


	}

	return 0;
}