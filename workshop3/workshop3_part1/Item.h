/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 3 - LAB part
Submission Date: Feb 3, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SUBJECT_H
#define SDDS_SUBJECT_H
namespace sdds
{
	class Item
	{
		char m_itemName[21];
		double m_price;
		bool m_taxed;
		void setName(const char* name);
	public:
		void setEmpty();
		void set(const char* name, double price, bool taxed);
		void display()const;
		bool isValid()const;
		double price()const;
		double tax()const;
	};
}

#endif // !SDDS_SUBJECT_H
