#include "MedicalExecutive.hpp"


/**
 * Doly Rakotomahenina and Mohammed Bataineh
 *
 * */

int main (int argc, char*argv[])
{
	MedicalExecutive executive;
	executive.createList(argv[1]);	
	//executive.printList();
	

	// This is the interface. Connects to the Medical Executive
	bool interface = true;
	int choice;
	while(interface)
	{
	
		cout << "\nMake a selection:\n";
		cout << "1) Increase infection level of all cities\n";
		cout << "2) Increase infection level of specific city\n";
		cout << "3) Print status of a specific city\n";
		cout << "4) Create quarantine log\n";
		cout << "5) Print all cities above an infection level\n";
		cout << "6) Exit\n";
		cout << "Choice: ";
		
		cin >> choice;
		
		if(choice == 1)
			executive.infectionRaiseAll();
		if(choice == 2)
			executive.infectionRaiseOne();
		if(choice == 3)
			executive.printCityStatus();
		if(choice == 4)
			executive.createLog();
		if(choice == 5)	
			executive.printInfLevel();	
		if(choice == 6)
		{
			cout << "\n\nGood bye.\n";
			interface = false;
		}
		else
			interface = true;
	}
		
		
		
		
		
	return 0;
}
