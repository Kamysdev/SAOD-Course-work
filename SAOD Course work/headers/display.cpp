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

int Display_table(People* peoplelist, int* index, int &currentPage)
{
    std::cout << "City" << "\t" 
        << "||" << "\t\tFull name\t\t" 
        << "||" << "\tStreet\t\t" 
        << "||" << " House" 
        << "||" << " Flat " 
        << "||    DOS   ||\n";

	for (int i = currentPage * 20; i < currentPage * 20 + 20; i++)
	{
		display_delimiter();
		std::cout << i + 1 << "\t|| " << peoplelist[index[i]].FSname << "\t|| "
			<< peoplelist[index[i]].Street << "\t|| "
			<< peoplelist[index[i]].House_No << "\t|| "
			<< peoplelist[index[i]].Flat_No << "\t|| "
			<< peoplelist[index[i]].Date_of_settlement << "||" << std::endl;
	}

	display_delimiter();
	std::cout << "\t\t\t<- Previous \t\t Next ->\t\t ESC Exit";


	int button = _getch();

	if (button == 77)
	{
		currentPage++;
	}
	if (button == 75)
	{
		currentPage--;
	}
	if (button == 27)
	{
		return 0;
	}


	if (currentPage < 0)
	{
		currentPage = 199;
	}
	else if (currentPage > 199)
	{
		currentPage = 0;
	}

	system("CLS");

    return 1;
}
