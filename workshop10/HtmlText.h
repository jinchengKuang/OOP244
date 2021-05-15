/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 10 - LAB part
Submission Date: April 7, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds
{
	class HtmlText : public Text
	{
		char* m_title;
	public:
		HtmlText(const char* filename = nullptr, const char* title = nullptr);
		void write(std::ostream& os)const;
		HtmlText(const HtmlText& src);
		HtmlText& operator=(const HtmlText& src);
		~HtmlText();
	};
}
#endif // !SDDS_HTMLTEXT_H__
