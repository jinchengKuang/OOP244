/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 6 - LAB part
Submission Date: March 11, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds
{
	class Text;
	class Line
	{
		char* m_value{ nullptr };
		operator const char* ()const;
		Line()
		{
		}
		Line& operator=(const char*);
		~Line();
		friend class TextFile;
		// copy and copy assignment prevention goes here
		Line(const Line&) = delete;
		Line& operator=(const Line&) = delete;
	};

	class TextFile
	{
		Line* m_textLines;
		char* m_filename;
		unsigned m_noOfLines;
		unsigned m_pageSize;
		void setEmpty();
		void setFilename(const char* fname, bool isCopy = false);
		void setNoOfLines();
		void loadText();
		void saveAs(const char* fileName)const;
	public:
		TextFile(unsigned pageSize = 15);
		TextFile(const char* filename, unsigned pageSize = 15);
		TextFile(const TextFile& src);
		TextFile& operator=(const TextFile& src);
		~TextFile();
		std::ostream& view(std::ostream& ostr)const;
		std::istream& getFile(std::istream& istr);
		operator bool()const;
		unsigned lines()const;
		const char* name()const;
		const char* operator[](unsigned index)const;
	};
	std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
	std::istream& operator>>(std::istream& istr, TextFile& text);
}
#endif // !SDDS_TEXTFILE_H__
