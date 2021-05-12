/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 7 - LAB part
Submission Date: March 17, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MOTORVEHICLE_H__
#define SDDS_MOTORVEHICLE_H__

#include <iostream>
namespace sdds
{
	const int LICENSEPLATE_LEN = 9;
	const int ADDRESS_LEN = 64;
	class MotorVehicle
	{
		char m_licensePlate[LICENSEPLATE_LEN];
		char m_address[ADDRESS_LEN];
		unsigned int m_year;
	public:
		MotorVehicle();
		MotorVehicle(const char* licensePlate, unsigned int year, const char* address = "Factory");
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);

		unsigned int getYear() const;
		const char* getPlate() const;
		const char* getAddress() const;
	};
	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& m);
	std::istream& operator>>(std::istream& istr, MotorVehicle& m);
}
#endif