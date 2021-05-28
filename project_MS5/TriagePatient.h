/* Citation and Sources...
Final Project Milestone 4
Module:   TriagePatient
Filename: TriagePatient.h
Version   1.0
Author	  Jincheng Kuang
Revision History
-----------------------------------------------------------
Date       Reason
2020/3/29  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Patient.h"

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
namespace sdds
{
	class TriagePatient :public Patient
	{
		char* m_sympton;
	public:
		TriagePatient();
		char type() const;
		ostream& csvWrite(ostream& ostr) const;
		istream& csvRead(istream& istr);
		ostream& write(ostream& ostr) const;
		istream& read(istream& istr);
		~TriagePatient();
	};
}
#endif // !SDDS_TRIAGEPATIENT_H
