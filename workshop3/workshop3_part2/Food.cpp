/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 3 - DIY part
Submission Date: Feb 5, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"
#include "Food.h"

const int TIMENAMELEN = 10;

using namespace std;

namespace sdds
{
	void Food::setName(const char* name)
	{
		strnCpy(m_foodName, name, FOODNAMELEN);
	}

	void Food::setEmpty()
	{
		m_foodName[0] = '\0';
		m_calories = 0;
		m_time = 0;
	}

	void Food::set(const char* name, int cals, int time)
	{
		if (name != nullptr && cals > 0 && time > 0)
		{
			setName(name);
			m_calories = cals;
			m_time = time;
		}
		else
		{
			setEmpty();
		}
	}

	int Food::calories()const
	{
		return m_calories;
	}

	bool Food::isTimeValid() const
	{
		return (m_time == 1 || m_time == 2 || m_time == 3 || m_time == 4) ? true : false;
	}

	bool Food::isValid()const
	{
		bool ok = false;
		if (m_foodName != nullptr && m_foodName[0] != '\0' && (m_calories > 0 && m_calories <= 3000) && (isTimeValid()))
		{
			ok = true;
		}
		return ok;
	}

	void Food::display()const
	{
		if (isValid())
		{
			cout << "| ";
			cout.fill('.');
			cout.setf(ios::left);
			cout.width(30);
			cout << m_foodName << " | ";
			cout.unsetf(ios::left);

			cout.fill(' ');
			cout.setf(ios::right);
			cout.width(4);
			cout << m_calories << " | ";
			cout.unsetf(ios::right);

			char timeName[TIMENAMELEN];
			switch (m_time)
			{
			case 1:
				strnCpy(timeName, "Breakfast", TIMENAMELEN);
				break;
			case 2:
				strnCpy(timeName, "Lunch", TIMENAMELEN);
				break;
			case 3:
				strnCpy(timeName, "Dinner", TIMENAMELEN);
				break;
			case 4:
				strnCpy(timeName, "Snack", TIMENAMELEN);
				break;
			default:
				break;
			}

			cout.setf(ios::left);
			cout.width(10);
			cout << timeName << " |" << endl;
			cout.unsetf(ios::left);
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}
}