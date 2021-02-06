/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 3 - DIY part
Submission Date: Feb 5, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "cstring.h"
namespace sdds
{
	void strnCpy(char* des, const char* src, int len)
	{
		int i;
		for (i = 0; i < len && src[i] != '\0'; i++)
		{
			des[i] = src[i];
		}
		des[i] = '\0';
	}
}