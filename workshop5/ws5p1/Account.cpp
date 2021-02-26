#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds
{
	void Account::setEmpty()
	{
		m_number = -1;
		m_balance = 0.0;
	}
	// New account
	Account::Account()
	{
		m_number = 0;
		m_balance = 0.0;
	}
	Account::Account(int number, double balance)
	{
		setEmpty();
		if (number >= 10000 && number <= 99999
			&& balance > 0)
		{
			m_number = number;
			m_balance = balance;
		}
	}
	std::ostream& Account::display() const
	{
		if (*this)
		{
			cout << " ";
			cout << m_number;
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << m_balance;
			cout.unsetf(ios::right);
			cout << " ";
		}
		else if (~*this)
		{
			cout << "  NEW  |         0.00 ";
		}
		else
		{
			cout << "  BAD  |    ACCOUNT   ";
		}
		return cout;
	}

	Account:: operator bool() const
	{
		return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
	}

	Account:: operator int() const
	{
		return m_number;
	}

	Account:: operator double() const
	{
		return m_balance;
	}

	bool Account::operator ~() const
	{
		return m_number == 0;
	}

	Account& Account::operator=(int numAcc)
	{
		if (numAcc < 10000 && numAcc > 99999)
		{
			setEmpty();
		}
		else if (m_number == 0)
		{
			m_number = numAcc;
		}
		return *this;
	}

	Account& Account::operator=(Account& moveFromAcc)
	{
		if (m_number == 0 && bool(moveFromAcc))
		{
			m_number = moveFromAcc.m_number;
			moveFromAcc.m_number = 0;
			m_balance = moveFromAcc.m_balance;
			moveFromAcc.m_balance = 0.0;
		}
		return *this;
	}

	Account& Account::operator+=(double depositBalance)
	{
		if (bool(*this) && depositBalance > 0)
		{
			m_balance += depositBalance;
		}
		return *this;
	}

	Account& Account::operator-=(double withdrawBalance)
	{
		if (bool(*this) && withdrawBalance > 0 && m_balance >= withdrawBalance)
		{
			m_balance -= withdrawBalance;
		}
		return *this;
	}

	Account& Account::operator<<(Account& balanceFromAcc)
	{
		if (bool(*this) && bool(balanceFromAcc) && this != &balanceFromAcc)
		{
			m_balance += balanceFromAcc.m_balance;
			balanceFromAcc.m_balance = 0.0;
		}
		return *this;
	}

	Account& Account::operator>>(Account& balanceToAcc)
	{
		if (bool(*this) && bool(balanceToAcc))
		{
			balanceToAcc.m_balance += m_balance;
			m_balance = 0.0;
		}
		return *this;
	}

	double operator+(const Account& leftAcc, const Account& rightAcc)
	{
		double sum = 0.0;
		if (bool(leftAcc) && bool(rightAcc))
		{
			sum = double(leftAcc) + double(rightAcc);
		}
		return sum;
	}

	double operator+=(double& val, const Account& balanceAcc)
	{
		return val = val + double(balanceAcc);
	}
}