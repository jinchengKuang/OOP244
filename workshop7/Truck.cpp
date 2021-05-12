/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 7 - LAB part
Submission Date: March 17, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Truck.h"

namespace sdds
{
	Truck::Truck(const char* licensePlate, unsigned int year, double capacity, const char* address) :MotorVehicle(licensePlate, year)
	{
		moveTo(address);
		m_capacity = capacity;
		m_cargo = 0;
	}

	bool Truck::addCargo(double cargo)
	{
		bool added = false;
		if (m_cargo != m_capacity)
		{
			if ((m_cargo + cargo) <= m_capacity)
			{
				m_cargo += cargo;
			}
			else
			{
				m_cargo = m_capacity;
			}
			added = true;
		}
		return added;
	}

	bool Truck::unloadCargo()
	{
		bool unloaded = false;
		if (m_cargo != 0)
		{
			m_cargo = 0;
			unloaded = true;
		}
		return unloaded;
	}

	std::ostream& Truck::write(ostream& os) const
	{
		os << "| " << getYear() << " | " << getPlate() << " | " << getAddress() << " | " << m_cargo << "/" << m_capacity;
		return os;
	}

	std::istream& Truck::read(istream& in)
	{
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_cargo;
		return in;
	}

	std::ostream& operator<<(std::ostream& ostr, const Truck& t)
	{
		return t.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Truck& t)
	{
		return t.read(istr);
	}
}