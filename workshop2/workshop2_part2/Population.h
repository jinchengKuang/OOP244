/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 2 - DIY part
Submission Date: Jan 31, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds
{
	struct Populations
	{
		char* m_postalCode;
		int m_population;
	};
	void sort();
	bool load(const char* filename);
	int totalPopulation();
	void display(const Populations& populations);
	void display();
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_