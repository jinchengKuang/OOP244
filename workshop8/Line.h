/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 8 - LAB part
Submission Date: March 23, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_LINE_H__
#define SDDS_LINE_H__

#include "LblShape.h"

namespace sdds
{
	class Line :public LblShape
	{
		int m_length;
	public:
		Line();
		Line(const char* label, int length);
		void getSpecs(istream& istr);
		void draw(ostream& ostr) const;
	};
}

#endif