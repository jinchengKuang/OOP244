/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 4 - LAB part
Submission Date: Feb 10, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp
#include "Canister.h"

using namespace std;

const double PI = 3.14159265;

namespace sdds
{
	void Canister::setToDefault()
	{
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	bool Canister::isEmpty()const
	{
		return m_contentVolume < 0.00001 ? true : false;
	}

	bool Canister::hasSameContent(const Canister& C)const
	{
		bool ret = false;
		if (m_contentName != nullptr && C.m_contentName != nullptr && m_contentName[0] != '\0' && C.m_contentName[0] != '\0')
		{
			ret = !strCmp(m_contentName, C.m_contentName) ? true : false;
		}
		return ret;
	}

	void Canister::setName(const char* Cstr)
	{
		if (Cstr != nullptr && m_usable == true)
		{
			delete[] m_contentName;
			m_contentName = nullptr;
			m_contentName = new char[strLen(Cstr) + 1];
			strCpy(m_contentName, Cstr);
		}
	}

	Canister::Canister()
	{
		setToDefault();
	}

	Canister::Canister(const char* contentName)
	{
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char* contentName)
	{
		setToDefault();
		if (height >= 10 && height <= 40 && diameter >= 10 && diameter <= 30)
		{
			m_height = height;
			m_diameter = diameter;
			m_contentVolume = 0.0;
			setName(contentName);
		}
		else
		{
			m_usable = false;
		}
	}
	Canister::~Canister()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
	}

	void Canister::clear()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	double Canister::capacity()const
	{
		return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}

	double Canister::volume()const
	{
		return m_contentVolume;
	}

	Canister& Canister::setContent(const char* contentName)
	{
		if (contentName == nullptr || contentName[0] == '\0')
		{
			m_usable = false;
		}
		else if (isEmpty())
		{
			setName(contentName);
		}
		else if (!hasSameContent(*this))
		{
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(double quantity)
	{
		if (m_usable == true && quantity > 0 && quantity + m_contentVolume <= capacity())
		{
			m_contentVolume += quantity;
		}
		else
		{
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(Canister& C)
	{
		setContent(C.m_contentName);
		if (C.volume() > capacity() - volume())
		{
			C.m_contentVolume -= capacity() - volume();
			m_contentVolume = capacity();
		}
		else
		{
			pour(C.volume());
			C.m_contentVolume = 0.0;
		}
		if (!hasSameContent(C))
		{
			m_usable = false;
		}
		return *this;
	}

	std::ostream& Canister::display()const
	{
		cout.setf(ios::fixed);
		cout.precision(1);
		cout.width(7);
		cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
		if (!m_usable)
		{
			cout << " of Unusable content, discard!";
		}
		else if (m_contentName != nullptr && m_contentName[0] != '\0')
		{
			cout << " of ";
			cout.width(7);
			cout << volume() << "cc   " << m_contentName;
		}
		return cout;
	}
}