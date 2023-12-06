#include "Account.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

Account::Account(int initial_deposit)
{
	
}

Account::~Account()
{
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Getters

static int	Account::getNbAccounts(void)
{
	return (this->_nbAccounts);
}

static int	Account::getTotalAmount(void)
{
	return (this->_totalAmount);
}

static int	Account::getNbDeposits(void)
{
	return (this->_totalNbDeposits);
}

static int	Account::getNbWithdrawals(void)
{
	return (this->_totalNbWithdrawals);
}

// Member functions

void	Account::makeDeposit( int deposit )
{
	
}