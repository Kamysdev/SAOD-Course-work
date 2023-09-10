#include "headers/read.h"
#include "headers/display.h"
#include "headers/sort.h"

int main(int *argc, char **argv) 
{
	system("color 1f");		//Set color of console

	int current_page = 0;
	bool is_open = 1;
	int arrsize = 4000;

	People* peoplelist = new People[arrsize];

	int* index = new int[arrsize];
	for (int i = 0; i < arrsize; i++)
	{
		index[i] = i;
	}


	GetData(peoplelist);	//Load DB
	heapSort(peoplelist, index, arrsize);


	while (is_open)
	{
		is_open = Display_table(peoplelist, index, current_page);
	}

	return 0;
}