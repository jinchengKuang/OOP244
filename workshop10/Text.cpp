/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 10 - LAB part
Submission Date: April 7, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <fstream>
#include "cstring.h"
#include "Text.h"

using namespace std;

namespace sdds
{
	int Text::getFileLength() const
	{
		int len = 0;
		ifstream fin(m_filename);
		while (fin)
		{
			fin.get();
			len += !!fin;
		}
		return len;
	}
	const char& Text::operator[](int index)const
	{
		return m_content != nullptr ? m_content[index] : m_content[0];
	}
	Text::Text(const char* filename)
	{
		m_filename = nullptr;
		m_content = nullptr;
		if (filename != nullptr)
		{
			if (m_filename != nullptr)
			{
				delete[] m_filename;
			}
			m_filename = new char[strLen(filename) + 1];
			strCpy(m_filename, filename);
		}
		read();
	}
	Text::Text(const Text& src)
	{
		m_filename = nullptr;
		m_content = nullptr;
		*this = src;
	}
	Text& Text::operator=(const Text& src)
	{
		if (this != &src)
		{
			if (src.m_filename != nullptr)
			{
				if (m_filename != nullptr)
				{
					delete[] m_filename;
				}
				m_filename = new char[strLen(src.m_filename) + 1];
				strCpy(m_filename, src.m_filename);
			}
			read();
		}
		return *this;
	}
	Text::~Text()
	{
		delete[] m_filename;
		m_filename = nullptr;
		delete[] m_content;
		m_content = nullptr;
	}
	void Text::read()
	{
		if (m_filename != nullptr)
		{
			ifstream fin(m_filename);
			int len = getFileLength();
			delete[] m_content;
			m_content = new char[len + 1];
			for (int i = 0; i < len; i++)
			{
				m_content[i] = fin.get();
			}
			m_content[len] = '\0';
		}
		else
		{
			m_content = nullptr;
		}
	}
	void Text::write(std::ostream& os)const
	{
		if (m_content != nullptr)
		{
			os << m_content;
		}
	}

	ostream& operator<<(ostream& os, const Text& text)
	{
		text.write(os);
		return os;
	}
}