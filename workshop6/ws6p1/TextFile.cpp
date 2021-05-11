/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 6 - LAB part
Submission Date: March 11, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
	Line::operator const char* () const
	{
		return (const char*)m_value;
	}
	Line& Line::operator=(const char* lineValue)
	{
		delete[] m_value;
		m_value = new char[strLen(lineValue) + 1];
		strCpy(m_value, lineValue);
		return *this;
	}
	Line::~Line()
	{
		delete[] m_value;
	}

	void TextFile::setEmpty()
	{
		delete[] m_textLines;
		m_textLines = nullptr;

		delete[] m_filename;
		m_filename = nullptr;

		m_noOfLines = 0;
	}

	void TextFile::setFilename(const char* fname, bool isCopy)
	{
		if (isCopy)
		{
			delete[] m_filename;
			m_filename = new char[strLen(fname) + 2 + 1];
			strCpy(m_filename, "C_");
			strCat(m_filename, fname);
		}
		else
		{
			delete[] m_filename;
			m_filename = new char[strLen(fname) + 1];
			strCpy(m_filename, fname);
		}
	}

	void TextFile::setNoOfLines()
	{
		int count = 0;
		ifstream fin(m_filename);
		if (fin.is_open())
		{
			while (fin)
			{
				if (fin.get() == '\n')
				{
					count++;
				}
			}
			fin.close();
		}

		if (count == 0)
		{
			setEmpty();
		}
		else
		{
			m_noOfLines = count + 1;
		}
	}

	void TextFile::loadText()
	{
		if (m_filename != nullptr)
		{
			delete[] m_textLines;
			m_textLines = new Line[m_noOfLines];

			ifstream fin(m_filename);
			unsigned i = 0;
			if (fin.is_open())
			{
				string temp;
				while (getline(fin, temp))
				{
					m_textLines[i] = temp.c_str();
					i++;
				}
				fin.close();
			}
			m_noOfLines = i;
		}
	}

	void TextFile::saveAs(const char* fileName)const
	{
		if (fileName != nullptr)
		{
			ofstream fout(fileName);
			if (fout.is_open())
			{
				for (unsigned i = 0; i < m_noOfLines; i++)
				{
					fout << m_textLines[i].m_value << endl;
				}
				fout.close();
			}
		}
	}

	TextFile::TextFile(unsigned pageSize)
	{
		m_textLines = nullptr;
		m_filename = nullptr;
		m_noOfLines = 0;
		m_pageSize = 0;

		if (pageSize > 0)
		{
			m_pageSize = pageSize;
		}
	}

	TextFile::TextFile(const char* filename, unsigned pageSize)
	{
		m_textLines = nullptr;
		m_filename = nullptr;
		m_noOfLines = 0;
		m_pageSize = 0;

		if (pageSize > 0)
		{
			m_pageSize = pageSize;
		}
		if (filename != nullptr && filename[0] != '\0')
		{
			setFilename(filename);
			setNoOfLines();
			loadText();
		}
	}

	TextFile::TextFile(const TextFile& src)
	{
		m_textLines = nullptr;
		m_filename = nullptr;
		m_noOfLines = 0;
		m_pageSize = src.m_pageSize;
		if (this != &src && src.m_filename != nullptr && src.m_filename[0] != '\0')
		{
			setFilename(src.m_filename, true);
			src.saveAs(m_filename);
			setNoOfLines();
			loadText();
		}
		//*this = src;
	}

	TextFile& TextFile::operator=(const TextFile& src)
	{
		if (this != &src && this->m_filename != nullptr && src.m_filename != nullptr && this->m_filename[0] != '\0' && src.m_filename[0] != '\0')
		{
			delete[] m_textLines;
			m_textLines = nullptr;
			src.saveAs(m_filename);
			setNoOfLines();
			loadText();
		}
		return *this;
	}

	TextFile::~TextFile()
	{
		delete[] m_filename;
		m_filename = nullptr;
		delete[] m_textLines;
		m_textLines = nullptr;
	}

	std::ostream& TextFile::view(std::ostream& ostr)const
	{
		if (m_filename != nullptr && m_filename[0] != '\0')
		{
			ostr << m_filename << endl;
			ostr.fill('=');
			ostr.width(strLen(m_filename));
			ostr << '=' << endl;
			for (unsigned i = 0; i < m_noOfLines; i++)
			{
				ostr << m_textLines[i].m_value << endl;
				if (m_pageSize != 0 && (i + 1) % m_pageSize == 0)
				{
					ostr << "Hit ENTER to continue...";
					cin.get();
				}
			}
		}
		return ostr;
	}

	std::istream& TextFile::getFile(std::istream& istr)
	{
		string fname;
		getline(istr, fname);
		setFilename(fname.c_str());
		setNoOfLines();
		loadText();
		return istr;
	}

	TextFile::operator bool()const
	{
		return m_filename != nullptr;
	}

	unsigned TextFile::lines()const
	{
		return m_noOfLines;
	}

	const char* TextFile::name()const
	{
		return m_filename;
	}

	const char* TextFile::operator[](unsigned index)const
	{
		return m_filename != nullptr ? m_textLines[index % m_noOfLines].m_value : nullptr;
	}

	std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
	{
		return text.view(ostr);
	}

	std::istream& operator>>(std::istream& istr, TextFile& text)
	{
		return text.getFile(istr);
	}
}