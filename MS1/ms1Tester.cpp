// ms1 Tester:
// Version: 1.0
// Date: 20201-03-03
// Author: Fardad Soleimanloo
// Description:
// This file tests the utils and Time Module of your project
/////////////////////////////////////////////
#include <iostream>
#include "utils.h"
#include "utils.h"
#include "Time.h"
#include "Time.h"
using namespace std;
using namespace sdds;
void getIntTester();
void timeTester();
void getcstrTester();
int main()
{
	getIntTester();
	getcstrTester();
	timeTester();
	return 0;
}
void getIntTester()
{
	cout << "getInt tester:" << endl;

	cout << "enter 11: ";
	cout << getInt() << endl << endl;

	cout << "enter the following values at the prompt: " << endl;
	cout << "abc<enter>" << endl;
	cout << "9abc<enter>" << endl;
	cout << "9 <enter> (there is a space after 9)" << endl;
	cout << "9<enter>" << endl;
	cout << getInt("> ") << endl << endl;

	cout << "enter the following values at the prompt: " << endl;
	cout << "abc<enter>" << endl;
	cout << "9<enter>" << endl;
	cout << "10<enter>" << endl;
	cout << "21<enter>" << endl;
	cout << "21 <enter> (there is a space after 21)" << endl;
	cout << "20<enter>" << endl;
	getInt(10, 20, "> ", "value must be between 10 and 20: ", false);
	cout << "last value entered: " << getInt(10, 20, "> ", "invalid value, retry ") << endl;
}
void timeTester()
{
	Time D(1385u), C(65u), E;
	cout << "E: " << E << endl;
	cout << "D: " << D << endl;
	cout << "C: " << C << endl;

	cout << "  D        C     D-=C" << endl;
	cout << D << " -= " << C << " = ";
	cout << (D -= C) << endl << endl;

	cout << "  C        D     C-=D" << endl;
	cout << C << " -= " << D << " = ";
	cout << (C -= D) << endl << endl;

	cout << "  C        D     C+=D" << endl;
	cout << C << " += " << D << " = ";
	cout << (C += D) << endl << endl;

	cout << " C = 245u" << endl;
	cout << "C: " << (C = 245u) << endl << endl;

	cout << " D = 2760u" << endl;
	cout << "D: " << (D = 2760u) << endl << endl;

	cout << "  E   =   C   +   D" << endl;
	E = C + D;
	cout << E << " = " << C << " + " << D << endl << endl;

	cout << "  E   =   C   -   D" << endl;
	E = C - D;
	cout << E << " = " << C << " - " << D << endl << endl;

	cout << "C: " << C << endl;
	cout << " C *= 2u;" << endl << "C: ";
	cout << (C *= 2u) << endl;
	cout << " C *= 12u" << endl << "C: ";
	cout << (C *= 12u) << endl << endl;

	cout << " C = 245u" << endl;
	cout << "C: " << (C = 245u) << endl << endl;

	cout << "  E   =   C   *  2u" << endl;
	E = C * 2u;
	cout << E << " = " << C << " *  2u" << endl << endl;
	cout << "  E   =   C   *  12u" << endl;
	E = C * 12u;
	cout << E << " = " << C << " *  12u" << endl << endl;

	cout << "C: " << C << endl;
	cout << " C /= 2u;" << endl << "C: ";
	cout << (C /= 2u) << endl;

	cout << " C = 245u" << endl;
	cout << "C: " << (C = 245u) << endl << endl;

	cout << "  E   =   C   /  2u" << endl;
	E = C / 2u;
	cout << E << " = " << C << " /  2u" << endl << endl;

	cout << "E: " << E << endl;
	cout << "D: " << D << endl;
	cout << "C: " << C << endl << endl;

	cout << "Enter the following values at the prompt:" << endl;
	cout << "aa:bb<ENTER>" << endl;
	cout << "12,12<ENTER>" << endl;
	cout << "-12:12<ENTER>" << endl;
	cout << "12:-12" << endl;
	cout << "12:12" << endl;

	cout << "Please enter the time (HH:MM): ";
	bool done;
	do
	{
		done = true;
		cin >> E;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			done = false;
			cout << "Bad time entry, retry (HH:MM): ";
		}
	} while (!done);
	cout << "you entered: " << E << endl << endl;
	cout << "Enter 100:100 at the prompt: " << endl;
	sdds::debug = true;
	E.setToNow();
	cout << E << endl;
	sdds::debug = false;
	cout << "The actual system time is: " << Time().setToNow() << endl;
}

void getcstrTester()
{
	char* cstr;
	cout << "copy and paste the following at the prompt:" << endl;
	cout << "if you didn't care what happened to me, "
		"and i didn't care for you, "
		"we would zig zag our way through the boredom and pain, "
		"occasionally glancing up through the rain. "
		"wondering which of the brothers to blame. "
		"and watching for pigs on the wing." << endl;
	cstr = getcstr("paste here /> ");
	cout << "you entered:" << endl << cstr << endl;
	delete[] cstr;
}