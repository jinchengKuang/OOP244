/* Citation and Sources...
Final Project Milestone 1
Module:   Time
Filename: Time.cpp
Version   1.0
Author	  Jincheng Kuang
Revision History
-----------------------------------------------------------
Date       Reason
2020/3/15  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Time.h"
#include "utils.h"
#include <string>
using namespace std;
namespace sdds
{
	const int MINSPERDAY = 1440;
	Time& Time::setToNow()
	{
		m_min = getTime();
		return *this;
	}

	void Time::setEmpty()
	{
		m_min = 0;
	}

	Time::Time(unsigned int min)
	{
		setEmpty();
		if (min >= 0)
		{
			m_min = min;
		}
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		unsigned int hours = m_min / 60;
		unsigned int minutes = m_min % 60;
		if (hours < 10)
		{
			ostr.fill('0');
			ostr.width(2);
			ostr << hours << ":";
		}
		else
		{
			ostr << hours << ":";
		}
		if (minutes < 10)
		{
			ostr.fill('0');
			ostr.width(2);
			ostr << minutes;
		}
		else
		{
			ostr << minutes;
		}
		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int hours = 0;
		int minutes = 0;
		char colon = '\0';

		istr >> hours;
		istr >> colon;
		istr >> minutes;

		if (hours < 0 || colon != ':' || minutes < 0)
		{
			istr.setstate(ios::failbit);
		}

		m_min = hours * 60 + minutes;
		return istr;
	}

	Time& Time::operator-=(const Time& D)
	{
		if (m_min < D.m_min)
		{
			int diffInMin = D.m_min - m_min;
			int diffInDay = diffInMin / MINSPERDAY;
			m_min = (MINSPERDAY * (diffInDay + 1)) - diffInMin;
		}
		else
		{
			m_min -= D.m_min;
		}
		return *this;
	}

	Time Time::operator-(const Time& D)const
	{
		unsigned int ret = 0;
		if (m_min < D.m_min)
		{
			int diffInMin = D.m_min - m_min;
			int diffInDay = diffInMin / MINSPERDAY;
			ret = (MINSPERDAY * (diffInDay + 1)) - diffInMin;
		}
		else
		{
			ret -= D.m_min;
		}
		return Time(ret);
	}

	Time& Time::operator+=(const Time& D)
	{
		m_min += D.m_min;
		return *this;
	}

	Time Time::operator+(const Time& D)const
	{
		return Time(m_min + D.m_min);
	}

	Time& Time::operator=(unsigned int val)
	{
		m_min = val;
		return *this;
	}

	Time& Time::operator *= (unsigned int val)
	{
		m_min *= val;
		return *this;
	}

	Time Time::operator *(unsigned int val)const
	{
		return Time(m_min * val);
	}

	Time& Time::operator /= (unsigned int val)
	{
		m_min /= val;
		return *this;
	}

	Time Time::operator /(unsigned int val)const
	{
		return Time(m_min / val);
	}

	Time::operator int()const
	{
		return int(m_min);
	}

	Time::operator unsigned int()const
	{
		return m_min;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		return D.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Time& D)
	{
		return D.read(istr);
	}
}