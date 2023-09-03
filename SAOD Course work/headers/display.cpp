#include "display.h"

int display_delimiter()
{
	std::cout << "========"
		<< "++" << "======================================"
		<< "++" << "======================"
		<< "++" << "======"
		<< "++" << "======"
		<< "++==========++\n";

	return 0;
}

int Display_table(People* peoplelist, int &current_page)
{

    std::cout << "City" << "\t" 
        << "||" << "\t\tFull name\t\t" 
        << "||" << "\tStreet\t\t" 
        << "||" << " House" 
        << "||" << " Flat " 
        << "||    DOS   ||\n";

	for (int i = current_page * 20; i < current_page * 20 + 20; i++)
	{
		display_delimiter();
		std::cout << i + 1 << "\t|| " << peoplelist[i].FSname << "\t|| "
			<< peoplelist[i].Street << "\t|| "
			<< peoplelist[i].House_No << "\t|| "
			<< peoplelist[i].Flat_No << "\t|| "
			<< peoplelist[i].Date_of_settlement << "||" << std::endl;
	}

	display_delimiter();
	std::cout << "\t\t\t<- Previous \t\t Next ->\t\t ESC Exit";


	int button = _getch();

	if (button == 77)
	{
		current_page++;
	}
	if (button == 75)
	{
		current_page--;
	}
	if (button == 27)
	{
		return 0;
	}


	if (current_page < 0)
	{
		current_page = 199;
	}
	else if (current_page > 199)
	{
		current_page = 0;
	}

	system("CLS");

    return 1;
}
