/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 10 - LAB part
Submission Date: April 7, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "HtmlText.h"
#include "Text.h"
#include "cstring.h"
namespace sdds
{
	HtmlText::HtmlText(const char* filename, const char* title) :Text(filename)
	{
		m_title = nullptr;
		if (title != nullptr)
		{
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
	}
	void HtmlText::write(std::ostream& os)const
	{
		int i = 0;
		bool MS = false;
		bool keepLooping = true;
		os << "<html><head><title>";
		if (m_title != nullptr)
		{
			os << m_title;
		}
		else
		{
			os << "No Title";
		}
		os << "</title></head>\n<body>\n";
		if (m_title != nullptr)
		{
			os << "<h1>" << m_title << "</h1>\n";
		}
		do
		{
			if ((*this)[i] == ' ')
			{
				if (MS)
				{
					os << "&nbsp;";
				}
				else
				{
					MS = true;
					os << ' ';
				}
			}
			else if ((*this)[i] == '<')
			{
				os << "&lt;";
				MS = false;
			}
			else if ((*this)[i] == '>')
			{
				os << "&gt;";
				MS = false;
			}
			else if ((*this)[i] == '\n')
			{
				os << "<br />\n";
				MS = false;
			}
			else
			{
				os << (*this)[i];
				MS = false;
			}
			if ((*this)[i + 1] == '\0')
			{
				keepLooping = false;
			}
			else
			{
				i++;
			}
		} while (keepLooping);
		os << "</body>\n</html>";
	}
	HtmlText::HtmlText(const HtmlText& src)
	{
		m_title = nullptr;
		*this = src;
	}
	HtmlText& HtmlText::operator=(const HtmlText& src)
	{
		if (this != &src)
		{
			if (src.m_title != nullptr)
			{
				(Text&)*this = src;
				delete[] m_title;
				m_title = new char[strLen(src.m_title) + 1];
				strCpy(m_title, src.m_title);
			}
		}
		return *this;
	}
	HtmlText::~HtmlText()
	{
		delete[] m_title;
		m_title = nullptr;
	}
}