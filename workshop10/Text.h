/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 10 - LAB part
Submission Date: April 7, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream>

using namespace std;

namespace sdds
{
	class Text
	{
		char* m_filename;
		char* m_content;
		int getFileLength()const;
	protected:
		const char& operator[](int index)const;
	public:
		Text(const char* filename = nullptr);
		Text(const Text& src);
		Text& operator=(const Text& src);
		virtual ~Text();
		void read();
		virtual void write(std::ostream& os)const;
	};
	ostream& operator<<(ostream& os, const Text& text);
}
#endif // !SDDS_PERSON_H__
