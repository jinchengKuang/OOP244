/* Citation and Sources...
Final Project Milestone 4
Module:   CovidPatient
Filename: CovidPatient.h
Version   1.0
Author	  Jincheng Kuang
Revision History
-----------------------------------------------------------
Date       Reason
2020/3/29  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_

#include "Patient.h"

namespace sdds
{
	class CovidPatient : public Patient
	{
	public:
		CovidPatient();
		char type() const;
		istream& csvRead(istream& istr);
		ostream& write(ostream& ostr) const;
		istream& read(istream& istr);
	};
}
#endif // !SDDS_COVIDPATIENT_H_
