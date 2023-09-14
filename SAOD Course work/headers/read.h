#pragma once
#include <iostream>
#include <fstream>
#include <cstring>



struct People
{
    char FSname[32];
    char Street[18];
    short int House_No;
    short int Flat_No;
    char Date_of_settlement[10];

    People() = default;

    int SetData(People templist);
};

int GetData(People *GetDataBack);
