#ifndef AIRPORT_H
#define AIRPORT_H
#include <string>


class Airport
{
    public:
        std::string getName(){return name;};
        std::string getCountry(){return country;};
        int getTerNum(){return terminalNum;};
        int getRunNum(){return runwayNum;};
        int setName(std::string sName);
        int setCountry(std::string sCountry);
        int setTerNum(int sTerNum);
        int setRunNum(int sRunNum);
        Airport();
        Airport(std::string sName, std::string sCountry, int sTerNum, int sRunNum);
        Airport &operator=(const Airport &e);
        ~Airport();
    private:
        std::string name;
        std::string country;
        int terminalNum;
        int runwayNum;
};

#endif // AIRPORT_H
