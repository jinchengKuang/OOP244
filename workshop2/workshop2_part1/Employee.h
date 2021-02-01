/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 2 - LAB part
Submission Date: Jan 27, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds
{
	struct Employee
	{
		char* m_name;
		int m_empNo;
		double m_salary;
	};

	//sorts the dynamic array of employees based on the GPA of the employees.
	void sort();

	// loads a employee structue with its values from the file
	bool load(Employee& emp);

	// allocates the dyanmic array of employees and loads all the file
	// recoreds into the array
	bool load();

	// displays a employee record on the screen:
	void display(const Employee& employees);

	// first sorts the employees then displays all the employees on the screen
	void display();

	// first will deallocate all the names in the employee elements
	// then it will deallocate the employee array
	void deallocateMemory();
}
#endif // SDDS_EMPLOYEE_H_