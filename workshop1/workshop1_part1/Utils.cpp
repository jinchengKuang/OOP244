/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Submission Date: Jan 20, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Utils.h"

using namespace std;

namespace sdds
{
	void flushkeys()
	{
		while (cin.get() != '\n');
	}

	bool ValidYesResponse(char ch)
	{
		return ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n';
	}

	bool yes()
	{
		char ch = 0;
		do
		{
			cin >> ch;
			flushkeys();
		} while (!ValidYesResponse(ch) && cout << "Only (Y/y) or (N/n) is acceptable: ");
		return ch == 'y' || ch == 'Y';
	}

	void readCstr(char cstr[], int len)
	{
		char buf[1024] = {};
		int i;
		cin.getline(buf, 1024);
		for (i = 0; i < len && buf[i]; i++)
		{
			cstr[i] = buf[i];
		}
		cstr[i] = 0;
	}

	int readInt(int min, int max)
	{
		int value = 0;
		bool done = false;
		while (!done)
		{
			cin >> value;
			if (!cin)
			{
				cin.clear();
				cout << "Bad integer, try agian: ";
			}
			else
			{
				if (value >= min && value <= max)
				{
					done = true;
				}
				else
				{
					cout << "Value out of range (" << min << "<=value<=" << max << "): ";
				}
			}
			flushkeys();
		}
		return value;
	}
}