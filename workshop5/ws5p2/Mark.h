/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 5 - DIY part
Submission Date: Feb 20, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

namespace sdds
{
	class Mark
	{
		int m_mark;
		double m_scale;
		char m_grade;
		bool m_state;

		void setStateEmpty();
		void setStateInvalid();
		void setStateValid(int mark);
		void setScaleAndGrade(int mark);

	public:
		Mark();
		Mark(int mark);
		//~Mark();
		bool isMarkValid(int mark) const;
		operator int() const;
		Mark& operator +=(int mark);
		Mark& operator =(int mark);
		operator double() const;
		operator char() const;
	};
	int operator +=(int& val, const Mark& objMark);
}
#endif