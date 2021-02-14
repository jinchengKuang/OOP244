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
#include "LabelMaker.h"

using namespace std;

namespace sdds
{
	LabelMaker::LabelMaker(int noOfLabels)
	{
		m_labels = nullptr;
		m_labels = new Label[noOfLabels];
		m_noOfLabels = noOfLabels;
	}

	void LabelMaker::readLabels()
	{
		cout << "Enter " << m_noOfLabels << " labels:" << endl;
		for (int i = 0; i < m_noOfLabels; i++)
		{
			cout << "Enter label number " << i + 1 << "\n> ";
			m_labels[i].readLabel();
		}
	}

	void LabelMaker::printLabels()
	{
		for (int i = 0; i < m_noOfLabels; i++)
		{
			m_labels[i].printLabel();
			cout << endl;
		}
	}

	LabelMaker::~LabelMaker()
	{
		for (int i = 0; i < m_noOfLabels; i++)
		{
			m_labels[i].~Label();
		}
		delete[] m_labels;
	}
}