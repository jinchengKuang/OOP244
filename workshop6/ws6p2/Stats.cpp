/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 6 - DIY part
Submission Date: March 15, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Stats.h"
#include "cstring.h"

using namespace std;

namespace sdds
{
	void Stats::setEmpty()
	{
		delete[] m_filename;
		m_filename = nullptr;
		m_columnWidth = 0;
		m_noOfColumns = 0;
		m_precision = 0;
		m_noOfNums = 0;
		delete[] m_nums;
		m_nums = nullptr;
	}

	void Stats::setFilename(const char* fname, bool isCopy)
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

	void Stats::setNoOfNums()
	{
		int count = 0;
		ifstream fin(m_filename);
		if (fin.is_open())
		{
			while (fin)
			{
				if (fin.get() == ',')
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
			m_noOfNums = count + 1;
		}
	}

	void Stats::loadStats()
	{
		if (*this)
		{
			delete[] m_nums;
			m_nums = new double[m_noOfNums];

			ifstream fin(m_filename);
			if (fin.is_open())
			{
				string str;
				unsigned i = 0;
				while (fin)
				{
					getline(fin, str, ',');
					if (fin)
					{
						fin.setf(ios::fixed);
						fin.precision(m_precision);
						m_nums[i] = stod(str);
						i++;
					}
				}
				fin.close();
			}
		}
	}

	void Stats::saveAs(const char* filename) const
	{
		if (filename != nullptr)
		{
			ifstream fin(m_filename);
			ofstream fout(filename);
			char ch;
			while (fin.get(ch)) fout << ch;
		}
	}

	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision)
	{
		m_filename = nullptr;
		m_columnWidth = 0;
		m_noOfColumns = 0;
		m_precision = 0;
		m_noOfNums = 0;
		m_nums = nullptr;
		if (columnWidth > 0 && noOfColumns > 0 && precision >= 0)
		{
			m_columnWidth = columnWidth;
			m_noOfColumns = noOfColumns;
			m_precision = precision;
		}
	}

	Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision)
	{
		m_filename = nullptr;
		m_columnWidth = 0;
		m_noOfColumns = 0;
		m_precision = 0;
		m_noOfNums = 0;
		m_nums = nullptr;
		if (columnWidth > 0 && noOfColumns > 0 && precision >= 0)
		{
			m_columnWidth = columnWidth;
			m_noOfColumns = noOfColumns;
			m_precision = precision;
		}
		if (filename != nullptr && filename[0] != '\0')
		{
			setFilename(filename);
			setNoOfNums();
			loadStats();
		}
	}

	Stats::Stats(const Stats& src)
	{
		m_filename = nullptr;
		m_nums = nullptr;

		m_columnWidth = src.m_columnWidth;
		m_noOfColumns = src.m_noOfColumns;
		m_precision = src.m_precision;
		m_noOfNums = src.m_noOfColumns;

		if (this != &src && src)
		{
			setFilename(src.m_filename, true);
			src.saveAs(m_filename);
			setNoOfNums();
			loadStats();
		}
	}

	Stats& Stats::operator=(const Stats& src)
	{
		if (this != &src && *this && src)
		{
			delete[] m_nums;
			m_nums = nullptr;

			m_columnWidth = src.m_columnWidth;
			m_noOfColumns = src.m_noOfColumns;
			m_precision = src.m_precision;
			m_noOfNums = src.m_noOfColumns;

			src.saveAs(m_filename);
			setNoOfNums();
			loadStats();
		}
		return *this;
	}

	Stats::~Stats()
	{
		delete[] m_filename;
		m_filename = nullptr;

		delete[] m_nums;
		m_nums = nullptr;
	}

	std::ostream& Stats::view(std::ostream& ostr)const
	{
		if (*this)
		{
			ostr << m_filename << endl;
			ostr.fill('=');
			ostr.width(strLen(m_filename));
			ostr << '=' << endl << endl;

			unsigned i = 0;
			ostr.setf(ios::fixed);
			ostr.precision(m_precision);
			ostr.fill(' ');
			for (i = 0; i < m_noOfNums; i++)
			{
				ostr.width(m_columnWidth);
				ostr << m_nums[i];
				if (m_noOfColumns != 0 && (i + 1) % m_noOfColumns == 0)
				{
					ostr << endl;
				}
			}
			if (m_noOfNums % m_noOfColumns != 0)
			{
				ostr << endl;
			}
			ostr << "Total of " << m_noOfNums << " listed!" << endl;
		}
		return ostr;
	}

	std::istream& Stats::getFile(std::istream& istr)
	{
		string fname;
		getline(istr, fname);
		setFilename(fname.c_str());
		setNoOfNums();
		loadStats();
		return istr;
	}

	double& Stats::operator[](unsigned idx)
	{
		double* ret = &m_dummy;
		if (*this)
		{
			ret = &m_nums[idx % m_noOfNums];
		}
		return *ret;
	}

	double Stats::operator[](unsigned idx) const
	{
		double ret = m_dummy;
		if (*this)
		{
			ret = m_nums[idx % m_noOfNums];
		}
		return ret;
	}

	Stats::operator bool() const
	{
		return m_filename != nullptr && m_filename[0] != '\0';
	}

	void Stats::sort(bool ascending)
	{
		if (m_noOfNums > 0)
		{
			if (ascending)
			{
				for (unsigned i = 0; i < m_noOfNums - 1; i++)
				{
					for (unsigned j = 0; j < m_noOfNums - i - 1; j++)
					{
						if (m_nums[j] > m_nums[j + 1])
						{
							double temp = 0;
							temp = m_nums[j];
							m_nums[j] = m_nums[j + 1];
							m_nums[j + 1] = temp;
						}
					}
				}
			}
			else
			{
				for (unsigned i = 0; i < m_noOfNums - 1; i++)
				{
					for (unsigned j = 0; j < m_noOfNums - i - 1; j++)
					{
						if (m_nums[j] < m_nums[j + 1])
						{
							double temp = 0;
							temp = m_nums[j];
							m_nums[j] = m_nums[j + 1];
							m_nums[j + 1] = temp;
						}
					}
				}
			}
		}
	}

	unsigned Stats::size()const
	{
		return m_noOfNums;
	}

	const char* Stats::name()const
	{
		return m_filename;
	}

	unsigned Stats::occurrence(double min, double max, std::ostream& ostr)
	{
		unsigned count = 0;
		double* newArr = new double[m_noOfNums];
		if (*this)
		{
			for (unsigned i = 0; i < m_noOfNums; i++)
			{
				if (m_nums[i] > min && m_nums[i] < max)
				{
					newArr[count++] = m_nums[i];
				}
			}
			ostr << endl;
			ostr.setf(ios::fixed);
			ostr.precision(m_precision);
			ostr.fill(' ');
			for (unsigned i = 0; i < count; i++)
			{
				ostr.width(m_columnWidth);
				ostr << newArr[i];
				if ((i + 1) % m_noOfColumns == 0)
				{
					ostr << endl;
				}
			}
			if (count % m_noOfColumns != 0)
			{
				ostr << endl;
			}
			ostr << "Total of " << count << " numbers are between " << min << " and " << max << endl;
		}
		delete[] newArr;
		return count;
	}

	std::ostream& operator<<(std::ostream& ostr, const Stats& s)
	{
		return s.view(ostr);
	}

	std::istream& operator>>(std::istream& istr, Stats& s)
	{
		return s.getFile(istr);
	}
}