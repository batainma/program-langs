
#include "City.hpp"

//public:

	bool City::operator< (const City& compare) const
		{
			if(this->population == compare.population)
			{
				if(this->infection == compare.infection)
				{
					if(this->city.compare(compare.city) < 0)
					{
						return true;
					}
					else
						return false;
				}	
				else if(this->infection > compare.infection)
					return true;

				else
					return false;

			}	
			return   this->population > compare.population;
		}
	


	City::City(string cityname, int pop, int inf)
	{
		city = cityname;
		population = pop;
		infection = inf;
	}

	int City::getPop() 
	{return population;}
	
	int City::getInf() 
	{return infection;}
	
	string City::getCity() 
	{return city;}
 
	void City::raiseInf() 
	{infection++;}
	
	void City::setPop(int pop) 
	{population = pop;}

	void City::setCity(string cityname) 
	{city = cityname;}



