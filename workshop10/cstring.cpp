/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 7 - LAB part
Submission Date: March 17, 2021

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

	// returns the lenght of the C-string in characters
	int strLen(const char* s)
	{
		int count = 0;
		for (int i = 0; s[i] != '\0'; i++)
		{
			count++;
		}
		return count;
	}

	int strCmp(const char* s1, const char* s2)
	{
		int s1Len = strLen(s1), s2Len = strLen(s2);
		int flag = 0;
		for (int i = 0; i < (s1Len > s2Len ? s1Len : s2Len) && flag == 0; i++)
		{
			if (s1[i] > s2[i])
			{
				flag = 1;
			}
			else if (s1[i] < s2[i])
			{
				flag = -1;
			}
		}
		return flag;
	}
}