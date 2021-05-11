/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 6 - LAB part
Submission Date: March 11, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "cstring.h"
namespace sdds
{
	void strCpy(char* des, const char* src)
	{
		if (src != nullptr)
		{
			int i;
			for (i = 0; src[i] != '\0'; i++)
			{
				des[i] = src[i];
			}
			des[i] = '\0';
		}
		else
		{
			des = nullptr;
		}
	}

	int strLen(const char* s)
	{
		int count = 0;
		if (s != nullptr)
		{
			for (int i = 0; s[i] != '\0'; i++)
			{
				count++;
			}
		}
		return count;
	}

	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src)
	{
		if (des != nullptr && src != nullptr)
		{
			int desLen = strLen(des), srcLen = strLen(src);
			int i, j;
			for (i = desLen, j = 0; j < srcLen; i++, j++)
			{
				des[i] = src[j];
			}
			des[i] = '\0';
		}
	}
}