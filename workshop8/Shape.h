/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 8 - LAB part
Submission Date: March 23, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SHAPE_H__
#define SDDS_SHAPE_H__

#include <iostream>

using namespace std;

namespace sdds
{
	class Shape
	{
	public:
		virtual void draw(ostream& ostr) const = 0;
		virtual void getSpecs(istream& istr) = 0;
		virtual ~Shape()
		{
		};
	};
	ostream& operator<<(ostream& ostr, const Shape& shape);
	istream& operator>>(istream& istr, Shape& shape);
}

#endif