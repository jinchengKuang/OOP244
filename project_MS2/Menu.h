/* Citation and Sources...
Final Project Milestone 2
Module:   Menu
Filename: Menu.h
Version   1.0
Author	  Jincheng Kuang
Revision History
-----------------------------------------------------------
Date       Reason
2020/3/22  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds
{
	class Menu
	{
		char* m_text; // holds the menu content dynamically
		int m_noOfSel;  // holds the number of options displayed in menu content
		void display()const;
	public:
		Menu(const char* MenuContent, int NoOfSelections);
		virtual ~Menu();
		int& operator>>(int& Selection);
		// add safe copying logic
		Menu(const Menu& m);
		Menu& operator=(const Menu& m) = delete;
	};
}
#endif