/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 8 - LAB part
Submission Date: March 23, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Line.h"

namespace sdds
{
	Line::Line()
	{
		m_length = 0;
	}

	Line::Line(const char* label, int length) :LblShape(label)
	{
		m_length = length > 0 ? length : 0;
	}

	void Line::getSpecs(istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore(1000, '\n');
	}
	void Line::draw(ostream& ostr) const
	{
		if (label() != nullptr && m_length > 0)
		{
			ostr << label() << endl;
			ostr.fill('=');
			ostr.width(m_length);
			ostr << '=';
		}
	}
}