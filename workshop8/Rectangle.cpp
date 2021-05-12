/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 8 - LAB part
Submission Date: March 23, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <cstring>
#include "Rectangle.h"

namespace sdds
{
	void Rectangle::setEmpty()
	{
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle()
	{
		setEmpty();
	}

	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label)
	{
		m_width = width;
		m_height = height;
		if (m_height < 3 || unsigned(m_width) < (strlen(label) + 2))
		{
			setEmpty();
		}
	}

	void Rectangle::getSpecs(istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore();
		istr >> m_height;
		istr.ignore(1000, '\n');
	}
	void Rectangle::draw(ostream& ostr) const
	{
		if (m_width != 0 && m_height != 0)
		{
			ostr << '+';
			ostr.fill('-');
			ostr.width(m_width - 2);
			ostr << '-' << '+' << endl;

			ostr << '|';
			ostr.fill(' ');
			ostr.setf(ios::left);
			ostr.width(m_width - 2);
			ostr << label() << '|' << endl;

			for (int i = 0; i < m_height - 3; i++)
			{
				ostr << '|';
				ostr.width(m_width - 2);
				ostr << ' ' << '|' << endl;
			}

			ostr << '+';
			ostr.fill('-');
			ostr.width(m_width - 2);
			ostr << '-' << '+';
		}
	}
}