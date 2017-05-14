#include "airport.h"

Airport::Airport()
{
    //ctor
}
Airport::Airport(std::string sName, std::string sCountry, int sTerNum, int sRunNum)
{
    name=sName;
    country=sCountry;
    terminalNum=sTerNum;
    runwayNum=sRunNum;
    //ctor
}
int Airport::setName(std::string sName)
{
    this->name=sName;
    return 1;
}
int Airport::setCountry(std::string sCountry)
{
    this->country=sCountry;
    return 1;
}
int Airport::setTerNum(int sTerNum)
{
    if(sTerNum<0) return 0;
    this->terminalNum=sTerNum;
    return 1;
}
int Airport::setRunNum(int sRunNum)
{
    if(sRunNum<0) return 0;
    this->runwayNum=sRunNum;
    return 1;
}
Airport& Airport::operator=(const Airport &e)
{
    name=e.name;
    country=e.country;
    terminalNum=e.terminalNum;
    runwayNum=e.runwayNum;
    return *this;
}
Airport::~Airport()
{
    //dtor
}
