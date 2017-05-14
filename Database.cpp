#include "Database.h"

Database::Database()
{
    //ctor
}

int Database::addAirport(int key, std::string name, std::string country, int terminalNum, int runwayNum)
{
    if((databaseKey(key))==true) return 0;
    Airport *airport;
    airport = new Airport;
    if(name!="") airport->setName(name);
    if(country!="") airport->setCountry(country);
    if(terminalNum>=0) airport->setTerNum(terminalNum);
    if(runwayNum>=0) airport->setRunNum(runwayNum);
    myDatabase.addNode(key, airport, myDatabase.getRoot());
    return 1;
}

int Database::editAirport(int key, std::string newName, std::string newCountry, int newTerNum, int newRunNum)
{
    if(findAirportN(key)==NULL)return 0;
    if(newName!="") findAirportN(key)->val->setName(newName);
    if(newCountry!="") findAirportN(key)->val->setCountry(newCountry);
    if(newTerNum>=0) findAirportN(key)->val->setTerNum(newTerNum);
    if(newRunNum>=0) findAirportN(key)->val->setRunNum(newRunNum);
    return 1;
}

int Database::deleteAirport(int key)
{
    myDatabase.delNode(findAirportN(key));
    delete findAirportN(key);
    return 1;
}

node<int, Airport>* Database::findAirportN(int key)
{
    return myDatabase.lookForKey(myDatabase.getRoot(), key);
}

Airport* Database::findAirport(int key)
{
    Airport *tmp;
    if(findAirportN(key)==NULL)return tmp;
    return myDatabase.lookForKey(myDatabase.getRoot(), key)->val;
}

bool Database::databaseKey(int key)
{
    if(isKey(key, myDatabase->getRoot())==true) return true;
    else return false;
}
}

Database::~Database()
{
    //dtor
}
