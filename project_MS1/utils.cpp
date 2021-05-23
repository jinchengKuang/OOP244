/* Citation and Sources...
Final Project Milestone 1
Module:   utils
Filename: utils.cpp
Version   1.0
Author	  Jincheng Kuang
Revision History
-----------------------------------------------------------
Date       Reason
2020/3/15  Preliminary release
2020/3/19  Fixed 5-arg getInt() bug
2020/3/22  Fixed 1-arg getInt() bug: consider '-'
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cctype>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds
{
	bool debug = false;  // made global in utils.h
	int getTime()
	{
		int mins = -1;
		if (debug)
		{
			Time t(0);
			cout << "Enter current time: ";
			do
			{
				cin.clear();
				cin >> t;   // needs extraction operator overloaded for Time
				if (!cin)
				{
					cout << "Invlid time, try agian (HH:MM): ";
					cin.clear();
				}
				else
				{
					mins = int(t);
				}
				cin.ignore(1000, '\n');
			} while (mins < 0);
		}
		else
		{
			time_t t = time(NULL);
			tm lt = *localtime(&t);
			mins = lt.tm_hour * 60 + lt.tm_min;
		}
		return mins;
	}

	int getInt(const char* prompt)
	{
		if (prompt != nullptr)
		{
			cout << prompt;
		}
		string userEnter;
		bool keepTrying = true;
		int i = 0;
		do
		{
			getline(cin, userEnter, '\n');
			cin.clear();
			int length = userEnter.length();
			bool loopBreak = false;
			for (i = 0; i < length && !loopBreak; i++)
			{
				if (!isdigit(userEnter[i]))
				{
					loopBreak = true;
					if (i == 0)
					{
						if (length > 1 && isdigit(userEnter[i + 1]))
						{
							loopBreak = false;
						}
						else
						{
							cout << "Bad integer value, try again: ";
						}
					}
					else
					{
						cout << "Enter only an integer, try again: ";
					}
				}
				else
				{
					loopBreak = false;
				}
			}
			if (!loopBreak && i == length)
			{
				keepTrying = false;
			}
		} while (keepTrying);
		return stoi(userEnter);
	}

	int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
	{
		int validInt = 0;
		bool keepTrying = true;
		validInt = getInt(prompt);
		do
		{
			if (validInt<min || validInt>max)
			{
				if (errorMessage != nullptr)
				{
					cout << errorMessage;
				}
				if (showRangeAtError)
				{
					cout << "[" << min << " <= value <= " << max << "]: ";
				}
				keepTrying = true;
				validInt = getInt();
			}
			else
			{
				keepTrying = false;
			}
		} while (keepTrying);
		return validInt;
	}

	char* getcstr(const char* prompt, std::istream& istr, char delimiter)
	{
		if (prompt != nullptr)
		{
			cout << prompt;
		}
		string userEnter;
		getline(istr, userEnter, delimiter);
		char* ret = new char[userEnter.length() + 1];
		strcpy(ret, userEnter.c_str());
		return ret;
	}
}