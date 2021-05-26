/* Citation and Sources...
Final Project Milestone 3
Module:   Patient
Filename: Patient.cpp
Version   1.0
Author	  Jincheng Kuang
Revision History
-----------------------------------------------------------
Date       Reason
2020/3/26  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"

using namespace std;

namespace sdds
{
	const int MAX_PATIENT_NAME_LEN = 100;
	Patient::Patient(int ticketNumber, bool fileIOFlag)
	{
		m_patientName = nullptr;
		m_OHIPNumber = 0;
		m_ticket = new Ticket(ticketNumber);
		m_fileIOFlag = fileIOFlag;
	}

	Patient::~Patient()
	{
		delete[] m_patientName;
		m_patientName = nullptr;
		delete m_ticket;
		m_ticket = nullptr;
	}

	bool Patient::fileIO() const
	{
		return m_fileIOFlag;
	}

	void Patient::fileIO(bool fileIOFlag)
	{
		m_fileIOFlag = fileIOFlag;
	}

	bool Patient::operator==(char src) const
	{
		return type() == src;
	}

	bool Patient::operator==(const Patient& p) const
	{
		return type() == p.type();
	}

	void Patient::setArrivalTime()
	{
		m_ticket->resetTime();
	}

	Patient::operator Time() const
	{
		return Time(*m_ticket);
	}

	int Patient::number() const
	{
		return m_ticket->number();
	}

	ostream& Patient::csvWrite(ostream& ostr) const
	{
		ostr << type() << ',' << m_patientName << ',' << m_OHIPNumber << ',';
		m_ticket->csvWrite(ostr);
		return ostr;
	}

	istream& Patient::csvRead(istream& istr)
	{
		char patientName[MAX_PATIENT_NAME_LEN] = { '\0' };
		istr.getline(patientName, MAX_PATIENT_NAME_LEN, ',');
		if (patientName != nullptr && patientName[0] != '\0')
		{
			delete[] m_patientName;
			m_patientName = new char[strlen(patientName) + 1];
			strcpy(m_patientName, patientName);

			istr >> m_OHIPNumber;
			istr.ignore();

			m_ticket->csvRead(istr);
		}

		return istr;
	}

	ostream& Patient::write(ostream& ostr) const
	{
		ostr << *m_ticket << endl;
		ostr.setf(ios::left);

		string patientName = m_patientName;
		patientName = patientName.substr(0, 25);
		ostr << patientName << ", OHIP: " << m_OHIPNumber;

		return ostr;
	}

	istream& Patient::read(istream& istr)
	{
		cout << "Name: ";

		char patientName[MAX_PATIENT_NAME_LEN] = { '\0' };
		istr.getline(patientName, MAX_PATIENT_NAME_LEN, '\n');
		delete[] m_patientName;
		m_patientName = new char[strlen(patientName) + 1];
		strcpy(m_patientName, patientName);

		cout << "OHIP:";
		m_OHIPNumber = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ");

		return istr;
	}
}