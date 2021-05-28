/* Citation and Sources...
Final Project Milestone 4
Module:   CovidPatient
Filename: CovidPatient.cpp
Version   1.0
Author	  Jincheng Kuang
Revision History
-----------------------------------------------------------
Date       Reason
2020/3/29  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <cstring>
#include "CovidPatient.h"

namespace sdds
{
	int nextCovidTicket = 1;

	CovidPatient::CovidPatient() :Patient(nextCovidTicket)
	{
		nextCovidTicket++;
	}

	char CovidPatient::type() const
	{
		return 'C';
	}

	istream& CovidPatient::csvRead(istream& istr)
	{
		Patient::csvRead(istr);
		nextCovidTicket = Patient::number() + 1;
		istr.ignore();
		return istr;
	}

	ostream& CovidPatient::write(ostream& ostr) const
	{
		if (Patient::fileIO())
		{
			csvWrite(ostr);
		}
		else
		{
			ostr << "COVID TEST" << endl;
			Patient::write(ostr);
			ostr << endl;
		}
		return ostr;
	}

	istream& CovidPatient::read(istream& istr)
	{
		if (Patient::fileIO())
		{
			csvRead(istr);
		}
		else
		{
			Patient::read(istr);
		}
		return istr;
	}
}