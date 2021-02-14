/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 4 - DIY part
Submission Date: Feb 13, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS

#include "cstring.h"
#include "Label.h"

using namespace std;

const int FRAMESIZE = 8;
const int CONTENTSIZE = 71;

namespace sdds
{
	void Label::setToDefault()
	{
		strCpy(m_frameArg, "+-+|+-+|");
		m_content = nullptr;
	}

	bool Label::isFrameArgValid(const char* frameArg)const
	{
		return (strLen(frameArg) == FRAMESIZE) ? true : false;
	}

	void Label::setFrame(const char* frameArg)
	{
		strCpy(m_frameArg, frameArg);
	}

	void Label::setContent(const char* content)
	{
		int contentLen = strLen(content) + 1;
		if (content != nullptr && content[0] != '\0')
		{
			if (contentLen > CONTENTSIZE)
			{
				contentLen = CONTENTSIZE;
			}
			m_content = nullptr;
			m_content = new char[contentLen];
			strCpy(m_content, content);
		}
	}

	Label::Label()
	{
		setToDefault();
	}

	Label::Label(const char* frameArg)
	{
		setToDefault();
		if (isFrameArgValid(frameArg))
		{
			setFrame(frameArg);
		}
	}

	Label::Label(const char* frameArg, const char* content)
	{
		setToDefault();
		if (isFrameArgValid(frameArg))
		{
			setFrame(frameArg);
			setContent(content);
		}
	}

	Label::~Label()
	{
		delete[] m_content;
		m_content = nullptr;
	}

	void Label::readLabel()
	{
		char readInput[CONTENTSIZE];
		cin.getline(readInput, CONTENTSIZE);
		setContent(readInput);
	}

	std::ostream& Label::printLabel()const
	{
		if (m_content != nullptr && m_content[0] != '\0')
		{
			int lineLen = strLen(m_content) + 3;
			cout << m_frameArg[topLft];
			cout.fill(m_frameArg[top]);
			cout.width(lineLen);
			cout << m_frameArg[topRit] << endl;

			cout << m_frameArg[lft];
			cout.fill(' ');
			cout.width(lineLen);
			cout << m_frameArg[rit] << endl;

			cout << m_frameArg[lft];
			cout << " " << m_content << " " << m_frameArg[rit] << endl;

			cout << m_frameArg[lft];
			cout.fill(' ');
			cout.width(lineLen);
			cout << m_frameArg[rit] << endl;

			cout << m_frameArg[bottomLft];
			cout.fill(m_frameArg[bottom]);
			cout.width(lineLen);
			cout << m_frameArg[bottomRit];
		}
		return cout;
	}

	char* Label::content()const
	{
		return m_content;
	}
}