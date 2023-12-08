#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

Account::Account()
{
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	Account::_totalNbDeposits = 0;
	Account::_totalNbWithdrawals = 0;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;

	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			  << ";amount:" << this->checkAmount()
			  << ";created"
			  << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			  << ";amount:" << this->checkAmount()
			  << ";closed"
			  << std::endl;
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Getters

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts()
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawals:" << Account::getNbWithdrawals()
			  << std::endl;
}

// Public member functions

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	this->_nbDeposits += 1;

	std::cout << " index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount
			  << ";deposit:" << deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->checkAmount()
			  << ";nb_deposits:" << this->_nbDeposits
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount;
	if (this->_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		Account::_totalNbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		this->_amount -= withdrawal;

		std::cout << ";withdrawal:" << withdrawal
				  << ";amount:" << this->checkAmount()
				  << ";nb_Withdrawals:" << this->_nbWithdrawals
				  << std::endl;
		return (true);
	}
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			  << ";total:" << this->checkAmount()
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}

// Private member functions

void Account::_displayTimestamp(void)
{
	time_t now = std::time(NULL);
	struct tm timenow = *std::localtime(&now);

	std::cout << "[" << timenow.tm_year + 1900 << timenow.tm_mon + 1 << timenow.tm_mday
			  << "_" << timenow.tm_hour << timenow.tm_min << timenow.tm_sec << "]";
}
