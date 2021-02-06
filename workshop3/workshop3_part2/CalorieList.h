/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 3 - DIY part
Submission Date: Feb 5, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TRANSCRIPT_H
#define SDDS_TRANSCRIPT_H
#include "Food.h"
namespace sdds
{
	class CalorieList
	{
		Food* m_foods;
		int m_size;
		int m_foodsAdded;
		int totalCals()const;
		void Title()const;
		void footer()const;
		void setEmpty();
		bool isValid()const;
	public:
		void init(int size);
		bool add(const char* item_name, int calories, int when);
		void display()const;
		void deallocate();
	};
}
#endif // !SDDS_TRANSCRIPT_H
