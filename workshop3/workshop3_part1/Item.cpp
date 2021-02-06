/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 3 - LAB part
Submission Date: Feb 3, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"
#include "Item.h"

const int ITEMNAMELEN = 20;
const double TAXRATE = 0.13;

using namespace std;

namespace sdds
{
	void Item::setName(const char* name)
	{
		strnCpy(m_itemName, name, ITEMNAMELEN);
	}

	void Item::setEmpty()
	{
		m_price = 0.0;
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed)
	{
		if (price >= 0 && name != nullptr)
		{
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
		else
		{
			setEmpty();
		}
	}

	double Item::price()const
	{
		return m_price;
	}

	double Item::tax()const
	{
		return m_taxed ? m_price * TAXRATE : 0.0;
	}

	bool Item::isValid()const
	{
		return (m_price > 0 && m_itemName[0] != '\0') ? true : false;
	}

	void Item::display()const
	{
		if (isValid())
		{
			cout << "| ";
			cout.fill('.');
			cout.setf(ios::left);
			cout.width(20);
			cout << m_itemName << " | ";
			cout.unsetf(ios::left);

			cout.fill(' ');
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(7);
			cout << m_price << " | ";
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);

			cout << (m_taxed ? "Yes" : "No ") << " |" << endl;
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}
}