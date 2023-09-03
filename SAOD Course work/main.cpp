#include "headers/SAOD.h"

int main(int *argc, char **argv) 
{

	system("color 02");
	People* peoplelist = new People[4000];

	GetData(peoplelist);




	for (int i = 0; i < 4000; i++)
	{
		std::cout << peoplelist[i].FSname << "\t"
			<< peoplelist[i].Street << "\t"
			<< peoplelist[i].House_No << "\t"
			<< peoplelist[i].Flat_No << "\t"
			<< peoplelist[i].Date_of_settlement << std::endl;
	}
	

	return 0;
}