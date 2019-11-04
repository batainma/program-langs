#ifndef CITY_HPP
#define CITY_HPP

#include <string>
#include <iostream>
using namespace std;

class City
{

private:
	string city;
	int population;
	int infection;

public:
	bool operator< (const City& compare) const;
	City(string cityname, int population, int infection);

	int getPop();
	int getInf();
	string getCity();

	void raiseInf();
	
	void setPop(int population);
	void setCity(string cityname);

};
#endif
