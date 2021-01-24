#include <iostream>
#include "cstring.h"

namespace sdds
{
	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src)
	{
		int i;
		for (i = 0; src[i] != '\0'; i++)
		{
			des[i] = src[i];
		}
		des[i] = '\0';
	}

	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len)
	{
		int i;
		for (i = 0; i < len; i++)
		{
			des[i] = src[i];
			if (src[i] == '\0')
			{
				break;
			}
		}
	}

	// Compares two C-strings
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2)
	{
		int s1Len = strLen(s1), s2Len = strLen(s2);
		int flag = 0;
		for (int i = 0; i < (s1Len > s2Len ? s1Len : s2Len); i++)
		{
			if (s1[i] > s2[i])
			{
				flag = 1;
				break;
			}
			else if (s1[i] < s2[i])
			{
				flag = -1;
				break;
			}
		}
		return flag;
	}

	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len)
	{
		int flag = 0;
		for (int i = 0; i < len; i++)
		{
			if (s1[i] > s2[i])
			{
				flag = 1;
				break;
			}
			else if (s1[i] < s2[i])
			{
				flag = -1;
				break;
			}
		}
		return flag;
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

	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2)
	{
		const char* locationOfMatch = nullptr;
		int str1Len = strLen(str1), str2Len = strLen(str2);
		if (str1Len >= str2Len)
		{
			for (int i = 0; i < str1Len - str2Len; i++)
			{
				if (!strnCmp(&str1[i], str2, str2Len))
				{
					locationOfMatch = &str1[i];
					break;
				}
			}
		}
		return locationOfMatch;
	}

	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src)
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