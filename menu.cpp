#include "menu.h"

Menu::Menu()
{
    //ctor
}
void Menu::displayMenu(Database newDatabase)
{
    int option;
    std::cout<<"Welcome to airport database"<<std::endl;
    while (true)
    {
        std::cout<<"MAIN MENU"<<std::endl;
        std::cout<<"---------"<<std::endl;
        std::cout<<"1. Add airport"<<std::endl;
        std::cout<<"2. Delete airport"<<std::endl;
        std::cout<<"3. Edit airport"<<std::endl;
        std::cout<<"4. Display airport"<<std::endl;
        std::cout<<"5. Display all airports"<<std::endl;
        std::cout<<"6. Export database to a file"<<std::endl;
        std::cout<<"7. Exit"<<std::endl;
        std::cout<<"What do you want to do? Enter correct number"<<std::endl;
        std::cin>>option;
        if (std::cin.fail())
        {
            std::cout<<"Bad input"<<std::endl;
            system("clear");
            return;
        }
        switch(option)
        {
            case 1:
            {
                system("clear");
                int k;
                std::cout<<"Type the key: ";
                std::cin>>k;
                std::string x;
                std::cout<<"Type the name of the airport: ";
                std::cin>>x;
                std::cin.ignore(100,'\n');
                std::string y;
                std::cout<<"Type the country of the airport: ";
                std::cin>>y;
                std::cin.ignore(100,'\n');
                int a;
                std::cout<<"Type the number of terminals: ";
                std::cin>>a;
                int b;
                std::cout<<"Type the number of runways: ";
                std::cin>>b;
                newDatabase.addAirport(k, x, y, a, b);
            }
            break;

            case 2:
            {
                system("clear");
                int k;
                if (newDatabase.getRoot()==NULL)
                {
                    std::cout<<"No airports in database"<<std::endl;
                    getchar();
                    break;
                }
                std::cout<<"Type the key: ";
                std::cin>>k;
                if (newDatabase.findAirportN(k)==NULL)
                {
                    std::cout<<"No airport with key <"<<k<<">."<<std::endl;
                    getchar();
                    break;
                }
                newDatabase.deleteAirport(k);
                std::cout<<"Airport code <"<<k<<"> has been deleted"<<std::endl;
                getchar();
            }
            break;

            case 3:
            {
                system("clear");
                int k;
                if (newDatabase.getRoot()==NULL)
                {
                    std::cout<<"No airports in database"<<std::endl;
                    getchar();
                    break;
                }
                std::cout<<"Type the key: ";
                std::cin>>k;
                if (newDatabase.findAirportN(k)==NULL)
                {
                    std::cout<<"No airport with key <"<<k<<">."<<std::endl;
                    getchar();
                    break;
                }
                printAirport(newDatabase.findAirportN(k));
                std::string x;
                std::cout<<"Type new name of the airport: ";
                std::cin>>x;
                std::cin.ignore(100,'\n');
                std::string y;
                std::cout<<"Type new country of the airport: ";
                std::cin>>y;
                std::cin.ignore(100,'\n');
                int a;
                std::cout<<"Type new number of terminals: ";
                std::cin>>a;
                int b;
                std::cout<<"Type new number of runways: ";
                std::cin>>b;
                newDatabase.editAirport(k, x, y, a, b);
                printAirport(newDatabase.findAirportN(k));
                getchar();
            }
            break;

            case 4:
            {
                system("clear");
                int k;
                if (newDatabase.getRoot()==NULL)
                {
                    std::cout<<"No airports in database"<<std::endl;
                    getchar();
                    break;
                }
                std::cout<<"Type the key: ";
                std::cin>>k;
                if (newDatabase.findAirportN(k)==NULL)
                {
                    std::cout<<"No airport with key <"<<k<<">."<<std::endl;
                    getchar();
                    break;
                }
                printAirport(newDatabase.findAirportN(k));
                getchar();
            }

            case 5:
            {
                system("clear");
                if (newDatabase.getRoot()==NULL)
                {
                    std::cout<<"No airports in database"<<std::endl;
                    getchar();
                    break;
                }
                printAllAirports(newDatabase.getRoot());
                getchar();
            }
            break;

            case 6:
            {
                system("clear");
                if (newDatabase.getRoot()==NULL)
                {
                    std::cout<<"No airports in database"<<std::endl;
                    getchar();
                    break;
                }
                exportDatabase(newDatabase);
                getchar();
            }
            break;

            case 7:
            {
                system("clear");
                std::cout<<"Goodbye";
                exit(0);
            }

            default:
            std::cout<<"There is no such an option"<<std::endl;
            getchar();
        }

        std::cout<<"For next activity click press enter";
        getchar();
        system("clear");
    }
}

void Menu::printAirport(node<int, Airport>* toPrint)
{
    std::cout<<toPrint->key<<" "<<toPrint->val->getName()<<" "<<toPrint->val->getCountry()<<" "<<
    toPrint->val->getTerNum()<<" "<<toPrint->val->getRunNum()<<std::endl;
}
void Menu::printAllAirports(node<int, Airport>* toPrint)
{
    if (toPrint==NULL) return;
    if (toPrint->l_son!=NULL)
    {
        printAllAirports(toPrint->l_son);
    }
    printAirport(toPrint);
    if (toPrint->r_son!=NULL)
    {
        printAllAirports(toPrint->r_son);
    }
}
int Menu::exportDatabase(Database toExport)
{
    std::string fileName;
    std::cout<<"Type name of the file: ";
    std::cin>>fileName;
    std::cin.ignore(1000,'\n');
    std::ofstream exported;
    std::ofstream* pointEx;
    exported.open(fileName.c_str(), std::ios::out);
    if(exported.good()==false) return;
    pointEx=&exported;
    exported<<"Exported database:\n"<<std::endl;
    printAllAirportsInDb(toExport.getRoot(), pointEx);
    exported.close();
    std::cout<<"SUCCESS"<<std::endl;
    return 1;
}
void Menu::printAllAirportsInDb(node<int, Airport>* toPrint, std::ofstream* file)
{
    if (toPrint==NULL) return;
    if (toPrint->l_son!=NULL)
    {
        printAirportInDb(toPrint->l_son, file);
    }
    printAirportInDb(toPrint, file);
    if (toPrint->r_son!=NULL)
    {
        printAirportInDb(toPrint->r_son, file);
    }
}
void Menu::printAirportInDb(node<int, Airport>* toPrint, std::ofstream* file)
{
    *file<<toPrint->key<<" "<<toPrint->val->getName()<<" "<<toPrint->val->getCountry()<<" "<<
    toPrint->val->getTerNum()<<" "<<toPrint->val->getRunNum()<<std::endl;
}

Menu::~Menu()
{
    //dtor
}
