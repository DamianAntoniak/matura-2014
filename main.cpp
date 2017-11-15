#include <iostream>
#include <fstream>

#include "class.h"

int main()
{
    zad4 JP_30;

    std::fstream file;
    std::ofstream outfile;

    outfile.open("zadanie4.txt");
    file.open("napisy.txt");

    for(int i = 0; i < 16; i++) JP_30.znakowe[i] = 0;

    while(std::getline(file, JP_30.wax))
    {
        if(!(JP_30.wax.size() % 2)) JP_30.parzyste++; 

        for(int i = 0; i < JP_30.wax.size(); i++)
        {
            if(JP_30.wax[i] == '0') JP_30.zero++;
            else if(JP_30.wax[i] == '1') JP_30.jeden++;
        }

        if(JP_30.zero == JP_30.jeden) JP_30.rowno++;

        if(JP_30.zero == JP_30.wax.size())  JP_30.zera++;
        if(JP_30.jeden == JP_30.wax.size())  JP_30.jedynki++;

        JP_30.znakowe[JP_30.wax.size() - 1] += 1;

        JP_30.zero = 0;
        JP_30.jeden = 0;
    }
    for(int i = 0; i < 16; i++) std::cout << "\nNapisow " << i << "-znakowych jest: " << JP_30.znakowe[i];
    outfile << "A) Napisow o parzystej dlugosci jest: " << JP_30.parzyste << "\nB) Napisow o rownej dlugosci jest: " << JP_30.rowno <<
    "\nC) Napisow z samych zer jest: " << JP_30.zera << " oraz napisow z samych jedynek jest: " << JP_30.jedynki << "\nD) ";
    return 0;
}
