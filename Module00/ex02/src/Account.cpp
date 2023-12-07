#include "Account.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Account::Account()
{
	this->__nbAccounts = 0;
	this->_totalAmount = 0;
	this->_totalNbDeposits = 0;
	this->_totalNbWithdrawals = 0;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_totalAmount += this_amount;
	this->_totalNbDeposits = 0;
	this->_totalNbWithdrawals = 0;
	this->_accountIndex = this->_nbAccounts;
	this->__nbAccounts += 1;

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

int		Account::getNbAccounts(void)
{
	return (this->_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return (this->_totalAmount);
}

int		Account::getNbDeposits(void)
{
	return (this->_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (this->_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << this->_nbAccounts
				<< ";total:" << this->_totalAmount
				<< ";deposits:" << this->_totalNbDeposits
				<< ";withdrawals:" << this->_totalNbWithdrawals
				<< std::endl;
}

// Public member functions

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	this->_totalNbDeposits += 1;
	this->_totalAmount += deposit;
	this->_nbDeposits += 1;
	
	std::cout << " index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";deposit:" << deposit
				<< ";amount:" << this->_amount += deposit;
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount;
	if (this->_amount < withdrawal)
	{
		std::cout <<  ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_totalNbWithdrawals += 1;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		this->_amount -= withdrawal

		std::cout << ";withdrawal:" << withdrawal
					<< ";amount:" << this->checkAmount();
					<< ";nb_Withdrawals:" << this->_nbWithdrawals
					<< std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Amount::displayStatus( void ) const
{
	
}

// Private member functions

void	Account::_displayTimestamp( void )
{
	
}
