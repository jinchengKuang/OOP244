/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 8 - LAB part
Submission Date: March 23, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_LBLSHAPE_H__
#define SDDS_LBLSHAPE_H__

#include "Shape.h"

namespace sdds
{
	class LblShape :public Shape
	{
		char* m_label{ nullptr };
	protected:
		char* label()const;
	public:
		LblShape()
		{
		};
		LblShape(const char* label);
		~LblShape();
		LblShape(const LblShape& lblShpae) = delete;
		LblShape& operator=(const LblShape& lblshape) = delete;
		void getSpecs(istream& istr);
	};
}

#endif