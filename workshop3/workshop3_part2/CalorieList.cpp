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
#include "CalorieList.h"

using namespace std;

namespace sdds
{
	void CalorieList::setEmpty()
	{
		m_foods = nullptr;
		m_size = 0;
		m_foodsAdded = 0;
	}

	bool CalorieList::isValid()const
	{
		bool ok = false;
		if (m_foods != nullptr)
		{
			int i;
			for (i = 0; i < m_foodsAdded && m_foods[i].isValid(); i++)
			{
				ok = true;
			}
			if (i != m_size)
			{
				ok = false;
			}
		}
		return ok;
	}

	int CalorieList::totalCals()const
	{
		int total = 0;
		for (int i = 0; i < m_foodsAdded; i++)
		{
			total += m_foods[i].calories();
		}
		return total;
	}

	void CalorieList::Title()const
	{
		cout << "+----------------------------------------------------+" << endl;
		if (isValid())
		{
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else
		{
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+\n"
			<< "| Food name                      | Cals | When       |\n"
			<< "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::footer()const
	{
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid())
		{
			cout << "|    Total Calories for today: ";
			cout.setf(ios::right);
			cout.width(8);
			cout << totalCals();
			cout << " |            |" << endl;
			cout.unsetf(ios::right);
		}
		else
		{
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}

	void CalorieList::init(int size)
	{
		if (size <= 0)
		{
			setEmpty();
		}
		else
		{
			m_size = size;
			m_foodsAdded = 0;
			m_foods = nullptr;
			m_foods = new Food[m_size];
			for (int i = 0; i < m_size; i++)
			{
				m_foods[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char* food_name, int calories, int when)
	{
		bool ok = false;
		if (food_name != nullptr)
		{
			if (m_foodsAdded < m_size)
			{
				m_foods[m_foodsAdded].set(food_name, calories, when);
				m_foodsAdded++;
				ok = true;
			}
		}
		else
		{
			m_foods[m_foodsAdded].setEmpty();
			m_foodsAdded++;
			ok = false;
		}
		return ok;
	}

	void CalorieList::display()const
	{
		Title();
		for (int i = 0; i < m_size; i++)
		{
			m_foods[i].display();
		}
		footer();
	}

	void CalorieList::deallocate()
	{
		delete[] m_foods;
		m_foods = nullptr;
	}
}