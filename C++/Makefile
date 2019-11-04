execute: MedicalExecutive.o City.o main.o
	g++ main.o MedicalExecutive.o City.o -std=c++11

MedicalExecutive.o: MedicalExecutive.hpp City.hpp
	g++ -c MedicalExecutive.cpp -std=c++11

City.o: City.hpp
	g++ -c City.cpp -std=c++11

clean:
	rm *.o 
