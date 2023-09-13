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

int Display_table(People* peoplelist, People** index, int &currentPage)
{
	display_delimiter();
    std::cout << "City" << "\t" 
        << "||" << "\t\tFull name\t\t" 
        << "||" << "\tStreet\t\t" 
        << "||" << " House" 
        << "||" << " Flat " 
        << "||    DOS   ||\n";
	display_delimiter();

	for (int i = currentPage * 20; i < currentPage * 20 + 20; i++)
	{
		std::cout << i + 1 << "\t|| " << index[i]->FSname << "\t|| "
			<< index[i]->Street << "\t|| "
			<< index[i]->House_No << "\t|| "
			<< index[i]->Flat_No << "\t|| "
			<< index[i]->Date_of_settlement << "||" << std::endl;
	}
	display_delimiter();

	std::cout << "\t\t\t<- Previous \t\t Next ->\t\tESC: Exit"
		<< "\n\tS: Sort database\tA: Get standart database\tF: find position in database";

    return 1;
}
