#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds
{
	class Account
	{
		int m_number;
		double m_balance;
		void setEmpty();
	public:
		Account();
		Account(int number, double balance);
		std::ostream& display()const;
		operator bool() const;
		operator int() const;
		operator double() const;
		bool operator ~() const;
		Account& operator=(int numAcc);
		Account& operator=(Account& moveFromAcc);
		Account& operator+=(double depositBalance);
		Account& operator-=(double withdrawBalance);
		Account& operator<<(Account& balanceFromAcc);
		Account& operator>>(Account& balanceToAcc);
	};
	double operator+(const Account& leftAcc, const Account& rightAcc);
	double operator+=(double& val, const Account& balanceAcc);
}
#endif // SDDS_ACCOUNT_H_