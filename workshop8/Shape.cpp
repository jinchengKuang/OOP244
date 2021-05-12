/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 8 - LAB part
Submission Date: March 23, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Shape.h"

namespace sdds
{
	ostream& operator<<(ostream& ostr, const Shape& shape)
	{
		shape.draw(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, Shape& shape)
	{
		shape.getSpecs(istr);
		return istr;
	}
}