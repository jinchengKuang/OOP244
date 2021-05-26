/* Citation and Sources...
Final Project Milestone 3
Module:   Patient
Filename: Patient.h
Version   1.0
Author	  Jincheng Kuang
Revision History
-----------------------------------------------------------
Date       Reason
2020/3/26  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_

#include <iostream>
#include "Ticket.h"

namespace sdds
{
	class Patient : public IOAble
	{
		char* m_patientName;
		int m_OHIPNumber;
		Ticket* m_ticket;
		bool m_fileIOFlag;
	public:
		Patient(int ticketNumber = 0, bool fileIOFlag = false);
		~Patient();
		Patient(const Patient& p) = delete;
		Patient& operator=(const Patient& p) = delete;
		virtual char type() const = 0;
		bool fileIO() const;
		void fileIO(bool fileIOFlag);
		bool operator==(char src) const;
		bool operator==(const Patient& p) const;
		void setArrivalTime();
		operator Time() const;
		int number() const;
		ostream& csvWrite(ostream& ostr) const;
		istream& csvRead(istream& istr);
		ostream& write(ostream& ostr) const;
		istream& read(istream& istr);
	};
}

#endif