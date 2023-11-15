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
	std::cout << "Pos" << "\t"
		<< "||" << "\t\tFull name\t\t"
		<< "||" << "\tStreet\t\t"
		<< "||" << " House"
		<< "||" << " Flat "
		<< "||    DOS   ||\n";
	displayDelimiter();
}

void displayControl(int status)
{
	displayDelimiter();
	if (status == 0) {
		std::cout << "\t\t\t<- Previous \t\t Next ->\t\tESC: Exit"
			<< "\n\tS: Sort database\t\tC: build code\t\tP: find position";
	}
	if (status == 1) {
		std::cout << "\t\t\t<- Previous \t\t Next ->\t\tESC: Exit"
			<< "\n\tS: Sort database\tA: Get standart database\tF: find position by year"
			<< "\n\tP: find position";
	}
	if (status == 2) {
		std::cout << "\t\t\t<- Previous \t\t Next ->\t\tESC: Exit"
			<< "\n\tS: Sort database\tA: Get standart database\tF: find position by year"
			<< "\n\tT: Build B-Tree";
	}

	std::cout << std::endl << "===================="
		<< "========================================="
		<< "=========================================";
}

int displayTable(People* peoplelist, People** index, int &currentPage, bool sorted)
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

	if (sorted) {
		displayControl(1);
	}
	else {
		displayControl(0);
	}

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
	displayControl(2);
}

MyQueue ShowBinarySearch(People** index, int programStatus, int& currentPage)
{
	std::string findYear{};
	MyQueue result{};

	BTree* root{};
	bool VR = false;
	bool HR = false;

	std::cout << std::endl << "Enter year: ";
	std::cin >> findYear;

	result = BinarySearch(index, findYear);
	if (result.empty())
	{
		system("cls");
		std::cout << std::endl << "\t\t\t\t\t\tNo one record!";
		Sleep(2000);
		return MyQueue();
	}
	else
	{
		while (programStatus == RUN_PROGRAM)
		{
			system("cls");
			printQueue(result, currentPage);
			programStatus = GetKeyCommand(currentPage);
		}
	}

	if (programStatus == BTREE)
	{
		int counter = 0;
		short int num = 0;
		root = nullptr;
		while (!(result.head == nullptr)) {
			InsertInBTree(result, root, VR, HR);
			result.head = result.head->next;
		}
		system("cls");
		displayHead();
		InOrderTraversal(root, counter);
		displayDelimiter();
		std::cout << "\n\t\tF: Find or press any key to exit...\n\n";
		displayDelimiter();
		int kkey = _getch();
		if (kkey == 102) {
			system("cls");
			std::cout << "\t\t\tEnter number of flat:\n";
			std::cin >> num;
			PrintFinderTree(root, num);
			system("pause");
		}
	}

	return result;
}
