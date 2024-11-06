#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	//TODO
	time_t 	now = time(0);
	tm		*ltm = localtime(&now);
	std::cout << "[" << ltm->tm_year << ltm->tm_mon << ltm->tm_mday << "_" << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << "] "; 
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}



Account::~Account( void )
{
/* 	Account::_totalAmount -= this->_amount;
	Account::_nbAccounts -= 1;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals = this->_nbWithdrawals;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl; */
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_totalAmount += initial_deposit; 
	Account::_nbAccounts += 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";" << "created" << std::endl;
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << _totalAmount << ";deposits:" << getNbDeposits() << ";" << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}



void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits + 1 << std::endl;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	this->_nbDeposits += 1 ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (this->_amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
	this->_nbWithdrawals += 1;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	return (true);
}
