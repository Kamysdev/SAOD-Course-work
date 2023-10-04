#include "display.hpp"

void displayDelimiter()
{
	std::cout << "========"
		<< "++" << "======================================"
		<< "++" << "======================"
		<< "++" << "======"
		<< "++" << "======"
		<< "++==========++\n";
}

void displayHead()
{
	displayDelimiter();
	std::cout << "City" << "\t"
		<< "||" << "\t\tFull name\t\t"
		<< "||" << "\tStreet\t\t"
		<< "||" << " House"
		<< "||" << " Flat "
		<< "||    DOS   ||\n";
	displayDelimiter();
}

void displayControl(int state)
{
	displayDelimiter();
	std::cout << "\t\t\t<- Previous \t\t Next ->\t\tESC: Exit"
		<< "\n\tS: Sort database\tA: Get standart database\tF: find position in database";

	if (state == 1)
	{
		std::cout << std::endl << "\tB: back to index";
	}

	std::cout << std::endl << "===================="
		<< "========================================="
		<< "=========================================";
}

int displayTable(People* peoplelist, People** index, int &currentPage)
{
	displayHead();
	for (int i = currentPage * 20; i < currentPage * 20 + 20; i++)
	{
		std::cout << i + 1 << "\t|| " << index[i]->FSname << "\t|| "
			<< index[i]->Street << "\t|| "
			<< index[i]->House_No << "\t|| "
			<< index[i]->Flat_No << "\t|| "
			<< index[i]->Date_of_settlement << "||" << std::endl;
	}
	displayControl(0);

    return 0;
}

int DisplayFind_border()
{
	int pos = -1;

	std::cout << std::endl << "Enter position: ";

	while (pos < 0 || pos > 3999)
	{
		std::cin >> pos;
	}

	system("CLS");

	return pos - 1;
}

void printQueue(const MyQueue& result, int currentPage)
{
    node* currentNode = result.head;
    int counter = 0;
    int startIndex = currentPage * 20;

    while (counter < startIndex && currentNode) {
        currentNode = currentNode->next;
        counter++;
    }
	displayHead();
    while (currentNode && counter < startIndex + 20) {
        People* recordPtr = currentNode->data;
		
        std::cout << counter + 1 << "\t|| " << recordPtr->FSname << "\t|| "
            << recordPtr->Street << "\t|| "
            << recordPtr->House_No << "\t|| "
            << recordPtr->Flat_No << "\t|| "
            << recordPtr->Date_of_settlement << "||" << std::endl;

        currentNode = currentNode->next;
        counter++;
    }
	displayControl(1);
}
