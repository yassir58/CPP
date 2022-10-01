#include "Account.hpp"
#include <iostream>

//  *  accessors
int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout<<"accounts:"<<_nbAccounts<<";";
	std::cout<<"total:"<<_totalAmount<<";";
	std::cout<<"deposits:"<<_totalNbDeposits<<";";
	std::cout<<"withdrawals:"<<_totalNbWithdrawals<<std::endl;
}

void Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
}

int		Account::checkAmount( void ) const
{
	if (this->_amount > 0)
		return (1);
	return (0);
}

bool Account::makeWithdrawal( int withdrawal )
{
	if (this->checkAmount() && this->_amount - withdrawal >= 0)
	{
		this->_amount -= withdrawal;
		return (true);
	}
	return (false);
}

int	Account::displayStatus( void ) const
{

}