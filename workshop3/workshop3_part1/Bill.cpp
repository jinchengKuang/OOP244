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
#include "Bill.h"

using namespace std;

namespace sdds
{
	void Bill::setEmpty()
	{
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid()const
	{
		bool ok = false;
		if (m_title[0] != '\0' && m_items != nullptr)
		{
			int i;
			for (i = 0; i < m_itemsAdded && m_items[i].isValid(); i++)
			{
				ok = true;
			}
			if (i != m_noOfItems)
			{
				ok = false;
			}
		}
		return ok;
	}

	double Bill::totalTax()const
	{
		double total = 0.0;
		for (int i = 0; i < m_itemsAdded; i++)
		{
			total += m_items[i].tax();
		}
		return total;
	}

	double Bill::totalPrice()const
	{
		double total = 0.0;
		for (int i = 0; i < m_itemsAdded; i++)
		{
			total += m_items[i].price();
		}
		return total;
	}

	void Bill::Title()const
	{
		cout << "+--------------------------------------+" << endl;
		if (isValid())
		{
			cout << "| ";
			cout.setf(ios::left);
			cout.width(36);
			cout << m_title << " |" << endl;
			cout.unsetf(ios::left);
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+----------------------+---------+-----+\n"
			<< "| Item Name            | Price   + Tax |\n"
			<< "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer()const
	{
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid())
		{
			cout << "|                Total Tax: ";
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(10);
			cout << totalTax() << " |" << endl;
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);

			cout << "|              Total Price: ";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(10);
			cout << totalPrice() << " |" << endl;
			cout.unsetf(ios::fixed);

			cout << "|          Total After Tax: ";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(10);
			cout << totalTax() + totalPrice() << " |" << endl;
			cout.unsetf(ios::fixed);
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	}

	void Bill::init(const char* title, int noOfItems)
	{
		if (title[0] == '\0' || noOfItems <= 0)
		{
			setEmpty();
		}
		else
		{
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);

			m_items = nullptr;
			m_items = new Item[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++)
			{
				m_items[i].setEmpty();
			}
		}
	}

	bool Bill::add(const char* item_name, double price, bool taxed)
	{
		bool ok = false;
		if (m_itemsAdded < m_noOfItems)
		{
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			ok = true;
		}
		return ok;
	}

	void Bill::display()const
	{
		Title();
		for (int i = 0; i < m_noOfItems; i++)
		{
			m_items[i].display();
		}
		footer();
	}

	void Bill::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;
	}
}