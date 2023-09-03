#include "headers/read.h"
#include "headers/display.h"

int main(int *argc, char **argv) 
{
	system("color 1f");

	int current_page = 0;
	bool is_open = 1;
	People* peoplelist = new People[4000];

	GetData(peoplelist);

	while (is_open)
	{
		is_open = Display_table(peoplelist, current_page);
	}
	

	return 0;
}