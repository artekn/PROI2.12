#ifndef DATABASE_H
#define DATABASE_H
#include "airport.h"
#include "myMap.h"

class Database
{
    public:
        int addAirport(int key, std::string name, std::string Country, int terminalNum, int runwayNum);
        int editAirport(int key, std::string newName="", std::string newCountry="", int newTerNum=0, int newRunNum=0);
        int deleteAirport(int key);
        node<int, Airport>* findAirportN(int key);
        Airport* findAirport(int key);
        node<int, Airport>* getRoot(){return myDatabase.getRoot();}
        bool databaseKey(int key);
        Database();
        ~Database();
    private:
        myMap<int, Airport> myDatabase;
};

#endif // DATABASE_H
