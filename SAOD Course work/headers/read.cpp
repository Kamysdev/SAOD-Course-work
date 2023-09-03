#include "read.h"

int People::SetData(People templist)
{
    strcpy_s(FSname, templist.FSname);
    strcpy_s(Street, templist.Street);
    House_No = templist.House_No;
    Flat_No = templist.Flat_No;
    strcpy_s(Date_of_settlement, templist.Date_of_settlement);

    return 0;
}

int GetData(People* GetDataBack)
{
    std::ifstream input("./testBase4.dat", std::ios::binary);
    People list{};
    for (int i = 0; !input.read((char*)&list, sizeof(People)).eof(); i++)
    {

        GetDataBack[i].SetData(list);
    }

    return 0;
}