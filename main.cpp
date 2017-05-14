#include <iostream>
#include <iomanip>
#include <string.h>
#include "menu.h"

int main()
{
    Database myDatabase;
    Menu newMenu;
    newMenu.displayMenu(myDatabase);
    return 0;
}
