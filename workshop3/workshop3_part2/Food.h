/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 3 - DIY part
Submission Date: Feb 5, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SUBJECT_H
#define SDDS_SUBJECT_H

const int FOODNAMELEN = 30;

namespace sdds
{
	class Food
	{
		char m_foodName[FOODNAMELEN + 1];
		int m_calories;
		int m_time;
		void setName(const char* name);
		bool isTimeValid() const;
	public:
		void setEmpty();
		void set(const char* name, int cals, int time);
		void display()const;
		bool isValid()const;
		int calories()const;
	};
}

#endif // !SDDS_SUBJECT_H
