#include "Account.hpp"
#include <iostream>


int Account::_totalAmount = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalNbDeposits = 0;
int Account::_nbAccounts = 0;

//  * static accessors
int Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout<<"accounts:"<<Account::getNbAccounts()<<";";
	std::cout<<"total:"<<Account::getTotalAmount()<<";";
	std::cout<<"deposits:"<<Account::getNbDeposits()<<";";
	std::cout<<"withdrawals:"<<Account::getNbWithdrawals()<<std::endl;
}

void Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	Account::_totalNbDeposits++;
	this->_nbDeposits++;
	std::cout<<"index:"<<this->_accountIndex<<";p_amount:"<<this->checkAmount()<<";deposit:";
	std::cout<<deposit<<";amount:"<<this->checkAmount() + deposit;
	std::cout <<";nb_deposits:"<<this->_nbDeposits<<std::endl;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

bool Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	if (this->_amount - withdrawal >= 0)
	{
		Account::_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		std::cout<<"index:"<<this->_accountIndex<<";p_amount:"<<this->checkAmount()<<";withdrawal:"<<withdrawal<<";amount:";
		std::cout<<this->checkAmount() - withdrawal <<";nb_withdrawals:"<<this->_nbWithdrawals<<std::endl;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		return (true);
	}
	std::cout<<"index:"<< this->_accountIndex<<";p_amount:"<< this->checkAmount() <<";withdrawal:refused"<<std::endl;
	return (false);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp ();
	std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->_amount<<";deposits:";
	std::cout<<this->_nbDeposits<<";withdrawals:"<<this->_nbWithdrawals<<std::endl;
}

Account::Account(int init_deposit)
{
	Account::_displayTimestamp ();
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = init_deposit;
	Account::_totalAmount += init_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->_amount<<";created"<<std::endl;
	 Account::_nbAccounts++;
}

Account::~Account()
{
	Account::_displayTimestamp ();
	std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->_amount<<";closed"<<std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t curr_time;
	tm * curr_tm;
	char date_string[50];
	
	time(&curr_time);
	curr_tm = localtime(&curr_time);
	
	strftime(date_string, 30, "[%Y%m%d_%H%M%s]", curr_tm);
	
	std::cout << date_string<<" ";
}

