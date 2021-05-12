/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 8 - LAB part
Submission Date: March 23, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "LblShape.h"

namespace sdds
{
	char* LblShape::label() const
	{
		return m_label;
	}

	LblShape::LblShape(const char* label)
	{
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}

	LblShape::~LblShape()
	{
		delete[] m_label;
		m_label = nullptr;
	}

	void LblShape::getSpecs(istream& istr)
	{
		char userInput[1000] = "\0";
		istr.getline(userInput, 1000, ',');
		delete[] m_label;
		m_label = new char[strlen(userInput) + 1];
		strcpy(m_label, userInput);
	}
}