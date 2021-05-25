/* Citation and Sources...
Final Project Milestone 2
Module:   IOAble
Filename: IOAble.cpp
Version   1.0
Author	  Jincheng Kuang
Revision History
-----------------------------------------------------------
Date       Reason
2020/3/22  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include "IOAble.h"

using namespace std;

namespace sdds
{
	ostream& operator<<(ostream& ostr, const IOAble& io)
	{
		return io.write(ostr);
	}

	istream& operator>>(istream& istr, IOAble& io)
	{
		return io.read(istr);
	}
}