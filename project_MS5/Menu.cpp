/* Citation and Sources...
Final Project Milestone 2
Module:   Menu
Filename: Menu.cpp
Version   1.0
Author	  Jincheng Kuang
Revision History
-----------------------------------------------------------
Date       Reason
2020/3/22  Preliminary release
2020/4/7   Destructor added m_text=nullptr;

-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Menu.h"
#include "utils.h"

using namespace std;

namespace sdds
{
	void Menu::display()const
	{
		cout << m_text << endl;
	}

	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		if (MenuContent != nullptr && MenuContent[0] != '\0' && NoOfSelections > 0)
		{
			m_text = new char[strlen(MenuContent) + 1];
			strcpy(m_text, MenuContent);
			m_noOfSel = NoOfSelections;
		}
		else
		{
			m_text = nullptr;
			m_noOfSel = 0;
		}
	}

	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}

	int& Menu::operator>>(int& Selection)
	{
		display();
		Selection = getInt(0, m_noOfSel, "0- Exit\n> ", "Invalid option ");
		return Selection;
	}

	Menu::Menu(const Menu& src)
	{
		m_noOfSel = src.m_noOfSel;
		if (src.m_text != nullptr && src.m_text[0] != '\0')
		{
			m_text = new char[strlen(src.m_text) + 1];
			strcpy(m_text, src.m_text);
		}
		else
		{
			m_text = nullptr;
		}
	}
}