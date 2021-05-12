/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 7 - LAB part
Submission Date: March 17, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS

#include "cstring.h"
#include "MotorVehicle.h"

using namespace std;

namespace sdds
{
	MotorVehicle::MotorVehicle()
	{
		m_licensePlate[0] = '\0';
		m_address[0] = '\0';
		m_year = 0;
	}

	MotorVehicle::MotorVehicle(const char* licensePlate, unsigned int year, const char* address)
	{
		strCpy(m_licensePlate, licensePlate);
		m_year = year;
		strCpy(m_address, address);
	}

	void MotorVehicle::moveTo(const char* address)
	{
		if (strCmp(m_address, address))
		{
			cout << "|";
			cout.setf(ios::right);
			cout.width(8);
			cout << m_licensePlate << "| |";
			cout.width(20);
			cout << m_address;
			strCpy(m_address, address);
			cout << " ---> ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(20);
			cout << m_address << "|" << endl;
			cout.unsetf(ios::left);
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os) const
	{
		return os << "| " << m_year << " | " << m_licensePlate << " | " << m_address;
	}

	std::istream& MotorVehicle::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> m_year;
		cout << "License plate: ";
		in >> m_licensePlate;
		cout << "Current location: ";
		in >> m_address;
		return in;
	}

	unsigned int MotorVehicle::getYear() const
	{
		return m_year;
	}

	const char* MotorVehicle::getPlate() const
	{
		return m_licensePlate;
	}

	const char* MotorVehicle::getAddress() const
	{
		return m_address;
	}

	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& m)
	{
		return m.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, MotorVehicle& m)
	{
		return m.read(istr);
	}
}