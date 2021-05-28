/* Citation and Sources...
Final Project Milestone 4
Module:   TriagePatient
Filename: TriagePatient.cpp
Version   1.0
Author	  Jincheng Kuang
Revision History
-----------------------------------------------------------
Date       Reason
2020/3/29  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "TriagePatient.h"

namespace sdds
{
	int nextTriageTicket = 1;

	TriagePatient::TriagePatient() :Patient(nextTriageTicket)
	{
		m_sympton = nullptr;
		nextTriageTicket++;
	}

	char TriagePatient::type() const
	{
		return 'T';
	}

	ostream& TriagePatient::csvWrite(ostream& ostr) const
	{
		Patient::csvWrite(ostr);
		ostr << ',' << m_sympton;
		return ostr;
	}

	istream& TriagePatient::csvRead(istream& istr)
	{
		delete[] m_sympton;
		Patient::csvRead(istr);
		istr.ignore();

		char temp[10000] = { '\0' };
		istr.getline(temp, 10000, '\n');
		m_sympton = new char[strlen(temp) + 1];
		strcpy(m_sympton, temp);

		nextTriageTicket = Patient::number() + 1;

		return istr;
	}

	ostream& TriagePatient::write(ostream& ostr) const
	{
		if (Patient::fileIO())
		{
			csvWrite(ostr);
		}
		else
		{
			ostr << "TRIAGE" << endl;
			Patient::write(ostr);
			ostr << endl;
			ostr << "Symptoms: " << m_sympton << endl;
		}
		return ostr;
	}

	istream& TriagePatient::read(istream& istr)
	{
		if (Patient::fileIO())
		{
			csvRead(istr);
		}
		else
		{
			delete[] m_sympton;
			Patient::read(istr);

			cout << "Symptoms: ";
			char temp[10000] = { '\0' };
			istr.getline(temp, 10000, '\n');
			m_sympton = new char[strlen(temp) + 1];
			strcpy(m_sympton, temp);
		}
		return istr;
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_sympton;
		m_sympton = nullptr;
	}
}