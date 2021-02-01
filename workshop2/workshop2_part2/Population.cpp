/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 2 - DIY part
Submission Date: Jan 31, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds
{
	int noOfPostalCodes;
	Populations* populations;

	void sort()
	{
		int i, j;
		Populations temp;
		for (i = noOfPostalCodes - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (populations[j].m_population > populations[j + 1].m_population)
				{
					temp = populations[j];
					populations[j] = populations[j + 1];
					populations[j + 1] = temp;
				}
			}
		}
	}

	bool load(const char* filename)
	{
		bool ok = false;

		if (openFile(filename))
		{
			noOfPostalCodes = noOfRecords();
			populations = new Populations[noOfPostalCodes];

			int i, count = 0;
			char name[128];

			for (i = 0; i < noOfPostalCodes; i++)
			{
				if ((read(name) && read(populations[i].m_population)))
				{
					int nameLen = strLen(name) + 1;
					populations[i].m_postalCode = new char[nameLen];
					strCpy(populations[i].m_postalCode, name);
					count++;
				}
			}
			if (noOfPostalCodes != count)
			{
				cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
				noOfPostalCodes = count;
				ok = false;
			}
			else
			{
				ok = true;
			}
			closeFile();
		}
		else
		{
			cout << "Could not open data file: " << filename << endl;
			ok = false;
		}
		return ok;
	}

	// calculate the total population by looping populations
	int totalPopulation()
	{
		int total = 0;
		for (int i = 0; i < noOfPostalCodes; i++)
		{
			total += populations[i].m_population;
		}
		return total;
	}

	void display(const Populations& popul)
	{
		cout << popul.m_postalCode << ":  " << popul.m_population << endl;
	}

	void display()
	{
		cout << "Postal Code: population\n"
			<< "-------------------------" << endl;
		sort();
		for (int i = 0; i < noOfPostalCodes; i++)
		{
			cout << i + 1 << "- ";
			display(populations[i]);
		}
		cout << "-------------------------\n"
			<< "Population of Canada: " << totalPopulation() << endl;
	}

	void deallocateMemory()
	{
		for (int i = 0; i < noOfPostalCodes; i++)
		{
			delete[] populations[i].m_postalCode;
		}
		delete[] populations;
	}
}