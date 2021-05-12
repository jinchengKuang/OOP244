/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 8 - LAB part
Submission Date: March 23, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RECTANGLE_H__
#define SDDS_RECTANGLE_H__

#include "LblShape.h"

namespace sdds
{
	class Rectangle :public LblShape
	{
		int m_width;
		int m_height;
		void setEmpty();
	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);
		void getSpecs(istream& istr);
		void draw(ostream& ostr) const;
	};
}

#endif