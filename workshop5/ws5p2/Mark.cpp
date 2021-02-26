/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 4 - DIY part
Submission Date: Feb 20, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Mark.h"

using namespace std;

namespace sdds
{
	void Mark::setStateEmpty()
	{
		m_state = true;
		m_mark = 0;
		setScaleAndGrade(m_mark);
	}

	void Mark::setStateInvalid()
	{
		m_state = false;
		m_mark = 0;
		setScaleAndGrade(m_mark);
	}

	void Mark::setStateValid(int mark)
	{
		m_state = true;
		m_mark = mark;
		setScaleAndGrade(mark);
	}

	bool Mark::isMarkValid(int mark) const
	{
		return mark >= 0 && mark <= 100;
	}

	void Mark::setScaleAndGrade(int mark)
	{
		if (m_state)
		{
			if (mark >= 0 && mark < 50)
			{
				m_scale = 0.0;
				m_grade = 'F';
			}
			else if (mark >= 50 && mark < 60)
			{
				m_scale = 1.0;
				m_grade = 'D';
			}
			else if (mark >= 60 && mark < 70)
			{
				m_scale = 2.0;
				m_grade = 'C';
			}
			else if (mark >= 70 && mark < 80)
			{
				m_scale = 3.0;
				m_grade = 'B';
			}
			else if (mark >= 80 && mark <= 100)
			{
				m_scale = 4.0;
				m_grade = 'A';
			}
			else
			{
				m_scale = 0.0;
				m_grade = 'X';
			}
		}
		else
		{
			m_scale = 0.0;
			m_grade = 'X';
		}
	}

	Mark::Mark()
	{
		setStateEmpty();
	}

	Mark::Mark(int mark)
	{
		setStateEmpty();
		if (isMarkValid(mark))
		{
			setStateValid(mark);
		}
		else
		{
			setStateInvalid();
		}
	}

	Mark::operator int() const
	{
		return m_mark;
	}

	Mark& Mark::operator +=(int mark)
	{
		if (isMarkValid(mark) && m_state == true)
		{
			m_mark += mark;
			if (isMarkValid(m_mark))
			{
				setStateValid(m_mark);
			}
			else
			{
				setStateInvalid();
			}
		}
		return *this;
	}

	Mark& Mark::operator =(int mark)
	{
		if (isMarkValid(mark))
		{
			setStateValid(mark);
		}
		else
		{
			setStateInvalid();
		}
		return *this;
	}

	Mark::operator double() const
	{
		return m_scale;
	}

	Mark::operator char() const
	{
		return m_grade;
	}

	int operator+=(int& val, const Mark& objMark)
	{
		if (objMark.isMarkValid(int(objMark)))
		{
			val += int(objMark);
		}
		return val;
	}
}