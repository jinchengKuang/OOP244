/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 2 - LAB part
Submission Date: Jan 27, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"

using namespace std;

namespace sdds
{
	int noOfEmployees;
	Employee* employees;

	void sort()
	{
		int i, j;
		Employee temp;
		for (i = noOfEmployees - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (employees[j].m_empNo > employees[j + 1].m_empNo)
				{
					temp = employees[j];
					employees[j] = employees[j + 1];
					employees[j + 1] = temp;
				}
			}
		}
	}

	// reads one employee record from the file and loads it into the employee reference
	bool load(Employee& emp)
	{
		bool ok = false;
		char name[128];
		if (read(emp.m_empNo) && read(emp.m_salary) && read(name))
		{
			int nameLen = strLen(name) + 1;
			emp.m_name = new char[nameLen];
			strCpy(emp.m_name, name);
			ok = true;
		}
		return ok;
	}

	bool load()
	{
		int count = 0;
		bool ok = false;

		if (openFile(DATAFILE))
		{
			noOfEmployees = noOfRecords();
			employees = new Employee[noOfEmployees];
			int i;
			for (i = 0; i < noOfEmployees && load(employees[i]); i++)
			{
				count++;
			}
			if (noOfEmployees != count)
			{
				cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
				noOfEmployees = count;
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
			cout << "Could not open data file: " << DATAFILE << endl;
			ok = false;
		}
		return ok;
	}

	void display(const Employee& employees)
	{
		cout << employees.m_empNo << ": " << employees.m_name << ", " << employees.m_salary << endl;
	}

	void display()
	{
		cout << "Employee Salary report, sorted by employee number\n"
			<< "no- Empno, Name, Salary\n"
			<< "------------------------------------------------"
			<< endl;
		sort();
		for (int i = 0; i < noOfEmployees; i++)
		{
			cout << i + 1 << "- ";
			display(employees[i]);
		}
	}

	void deallocateMemory()
	{
		for (int i = 0; i < noOfEmployees; i++)
		{
			delete[] employees[i].m_name;
			employees[i].m_name = nullptr;
		}
		delete[] employees;
		employees = nullptr;
	}
}