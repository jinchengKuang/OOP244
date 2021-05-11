/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 6 - DIY part
Submission Date: March 15, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_STATS_H
#define SDDS_STATS_H

#include <iostream>

namespace sdds
{
	class Stats
	{
		char* m_filename;
		unsigned m_columnWidth;
		unsigned m_noOfColumns;
		unsigned m_precision;
		unsigned m_noOfNums;
		double* m_nums;

		double m_dummy = 0;

		void setEmpty();
		void setFilename(const char* fname, bool isCopy = false);
		void setNoOfNums();
		void loadStats();
		void saveAs(const char* filename) const;

	public:
		Stats(unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
		Stats(const char* filename, unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);

		Stats(const Stats& src);
		Stats& operator=(const Stats& src);
		~Stats();

		std::ostream& view(std::ostream& ostr)const;
		std::istream& getFile(std::istream& istr);

		double& operator[](unsigned idx);
		double operator[](unsigned idx) const;
		operator bool() const;

		void sort(bool ascending);
		unsigned size()const;
		const char* name()const;
		unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
	};
	std::ostream& operator<<(std::ostream& ostr, const Stats& s);
	std::istream& operator>>(std::istream& istr, Stats& s);
}
#endif // !SDDS_STATS_H