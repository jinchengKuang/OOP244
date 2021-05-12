/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 7 - LAB part
Submission Date: March 17, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__

#include <iostream>
#include "MotorVehicle.h"
using namespace std;
namespace sdds
{
	class Truck :public MotorVehicle
	{
		double m_capacity;
		double m_cargo;
	public:
		Truck(const char* licensePlate, unsigned int year, double capacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr, const Truck& t);
	std::istream& operator>>(std::istream& istr, Truck& t);
}
#endif