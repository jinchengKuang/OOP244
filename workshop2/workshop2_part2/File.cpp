/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 2 - DIY part
Submission Date: Jan 31, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds
{
	FILE* fptr;

	bool openFile(const char filename[])
	{
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}

	int noOfRecords()
	{
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1)
		{
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}

	void closeFile()
	{
		if (fptr) fclose(fptr);
	}

	bool read(char* postalCode)
	{
		bool ok = false;
		if (fscanf(fptr, "%[^','],", postalCode) == 1)
		{
			ok = true;
		}

		return ok;
	}

	bool read(int& population)
	{
		bool ok = false;
		if (fscanf(fptr, "%d\n", &population) == 1)
		{
			ok = true;
		}
		return ok;
	}
}