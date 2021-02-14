/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 4 - DIY part
Submission Date: Feb 13, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABLEMAKER_H

#include "Label.h"

namespace sdds
{
	class LabelMaker
	{
		Label* m_labels;
		int m_noOfLabels;

	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}
#endif