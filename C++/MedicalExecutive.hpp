#ifndef MEDICALEXECUTIVE_HPP
#define MEDICALEXECUTIVE_HPP

#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>
#include <iterator>
#include <list>
#include "City.hpp"

class MedicalExecutive
{

private:
	list<City> cities;
	list<City> quarantine;
	list<City> :: iterator itr;
	
	void addCities(string tokens);
	
public:
	void infectionRaiseOne();
	void infectionRaiseAll();
	void infectLevelConsequences(City *city, list<City> :: iterator *itr);

	void printCityStatus();
	void printInfLevel();
	
	void createLog();
	void makeNewCity(string city, int population, int infection);
	void createList(char* fileName);
	
	void printList();

};

#endif
