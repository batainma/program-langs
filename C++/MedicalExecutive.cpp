#include "MedicalExecutive.hpp"


	//This adds all the cities into the cities list
	void MedicalExecutive::addCities(string tokens)
	{
		vector<string> cityInfo;
		stringstream stream(tokens);
		while(stream.good())
		{
			string tokenHold;
			getline(stream, tokenHold, ',');
			cityInfo.push_back(tokenHold);
		}	
		City newCity(cityInfo[0], stoi(cityInfo[1]), stoi(cityInfo[2])); //string to integer conversions
		cities.push_back(newCity);
	}


	//raise all of the cities infection levels by one	
	void MedicalExecutive::infectionRaiseAll()
	{
		cout << "\nThe infection level for all cities has been increased.\n";
		for(itr = cities.begin(); itr != cities.end(); itr++)
		{
			(*itr).raiseInf();
			infectLevelConsequences(&(*itr), &itr);
			
		}
	}
	
	//Raise the infection level of a single family
	void MedicalExecutive::infectionRaiseOne()
	{
		string specificCity;
		cout << "\nWhich city do you want to infect?: ";
		getline(cin >> std::ws,  specificCity);		//std::ws makes sure it accepts whitespace
		itr = cities.begin();
		while(itr != cities.end())
		{
			if((*itr).getCity() == specificCity)
			{
				cout << "Infection level for " << specificCity << " increased by 1\n";
				(*itr).raiseInf();
				infectLevelConsequences(&(*itr), &itr);
				return;
			}
		itr++;
		} 
		cout << "\nSorry, " << specificCity << " is not a city in the list.\n";
	}	
		

	//Whenever a city's infection level changes, it calls this for the consequences
	void MedicalExecutive::infectLevelConsequences(City *city, list<City> :: iterator *itr)
	{
		int inf = (*city).getInf();
		int pop = (*city).getPop();
		string cityName = (*city).getCity();
		if(inf == 1)
		{
			pop = pop * .9;
			(*city).setPop(pop);
		}
		if(inf == 2)
		{
			pop = pop * .8;
			(*city).setPop(pop);
		}
		if(inf == 3)
		{
			int newPop = pop * .25;
			pop = pop - newPop;
			(*city).setPop(pop);
			
			string newCityName = "New " + cityName;
			City newCity(newCityName, newPop, 0);
			cities.push_back(newCity);
			cout << newCityName << " has been made.\n";
		}
		if(inf == 4)
		{
			quarantine.push_back(*city);
			cities.erase(*itr);
			cout << cityName << " has been placed in quarantine.\n";
			(*itr)--;
			quarantine.sort();
			
		}
		cities.sort();
			
		

	}

	//Print all the info about a single city
	void MedicalExecutive::printCityStatus()
	{
		cout << "\nWhich city do you want the status of?: ";
		string specificCity;
		getline(cin >> std::ws, specificCity);
		itr = cities.begin();
		while(itr != cities.end())
		{
			if((*itr).getCity() == specificCity)
			{
				cout << "Status: " << specificCity << ", " << (*itr).getPop() << ", " << (*itr).getInf() << endl;
				return;
			}
		itr++;
		}
		cout << "Sorry, " << specificCity << " is not a city in the list.\n";
		

	}
	
	//Create the quarantine log if there are quarantined cities already
	void MedicalExecutive::createLog()
	{

		if(quarantine.empty())
		{
			cout << "\nNo cities in quarantine yet.\n";
			return;
		}

		cout << "\nWhat do you want to name the log?: ";
		string logName;
		getline(cin >> std::ws, logName);
		
		ofstream logFile;
		logFile.open(logName);
		for(itr = quarantine.begin(); itr != quarantine.end(); itr++)
			{
			logFile << (*itr).getCity() << ", " << (*itr).getPop() << ", " << (*itr).getInf() << endl;
			}
		logFile.close();
	}

	//Printing infections levels
	void MedicalExecutive::printInfLevel()
	{
		cout << "\nCities above what level?: ";
		int infLevel;
		cin >> infLevel;
		
		cout << "Cities aboce level " << infLevel << ":\n";
		for(itr = cities.begin(); itr != cities.end(); itr++)
		{
			if((*itr).getInf() >= infLevel) 
			{
				cout << (*itr).getCity() << ", " << (*itr).getPop() << ", " << (*itr).getInf() << endl; 
			}
		}
	}	


	//This is used when a city gets too infected and non-infected survivors make a new city
	void MedicalExecutive::makeNewCity(string city, int pop, int inf)
	{
		cities.push_back(City(city, pop, inf));
		cout << city << " has been made.\n";
	}

	//Public method to use private helper addCities
	void MedicalExecutive::createList(char* fileName)
	{
		ifstream listfile;
		listfile.open(fileName);
		string tokens;
		while(getline(listfile, tokens))
		{
			//cout << tokens  << endl;
			addCities(tokens);
		}
		cities.sort();
	}

	//Useful for testing -- not used in the interface	
	void MedicalExecutive::printList()
	{
		//list<City> :: iterator itr;
		cout << "\n\nPRINTING LIST: \n";
		for(itr = cities.begin(); itr != cities.end(); itr++)
		{
			cout << (*itr).getCity() << " " << (*itr).getPop() << " " << (*itr).getInf() << endl;
		}
	}

