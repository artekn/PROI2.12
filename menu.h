#ifndef MENU_H
#define MENU_H
#include "Database.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>

class Menu
{
    public:
        void displayMenu(Database database);
        void printAirport(node<int, Airport>* toPrint);
        void printAllAirports(node<int, Airport>* toPrint);
        int exportDatabase(Database toExport);
        void printAllAirportsInDb(node<int, Airport>* toPrint, std::ofstream* file);
        void printAirportInDb(node<int, Airport>* toPrint, std::ofstream* file);
        Menu();
        ~Menu();
    private:
};

#endif // MENU_H
