/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 2 - LAB part
Submission Date: Jan 27, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds
{
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();

	bool read(char* employeeName);
	bool read(int& employeeNum);
	bool read(double& employeeSalary);
}
#endif // !SDDS_FILE_H_
