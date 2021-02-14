/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 4 - DIY part
Submission Date: Feb 13, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>

namespace sdds
{
	class Label
	{
		char m_frameArg[8];
		char* m_content;
		void setToDefault();
		void setFrame(const char* frameArg);
		bool isFrameArgValid(const char* frameArg)const;

	public:
		enum frameArgLocation
		{
			topLft, top, topRit, rit, bottomRit, bottom, bottomLft, lft
		};
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();
		std::ostream& printLabel()const;
		char* content() const;
		void setContent(const char* content);
	};
}

#endif // !SDDS_LABEL_H