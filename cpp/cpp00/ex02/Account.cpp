#include "Account.hpp"
#include <iostream>
#include <time.h>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;


int	Account::getNbDeposits( void )
{
    return(_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return(_totalNbWithdrawals);
}

int Account::getTotalAmount( void )
{
    return(_totalAmount);
}

int Account::getNbAccounts( void )
{
    return(_nbAccounts);
}

void	Account::_displayTimestamp( void )
{
    char local_time[18];
    time_t com_time;

    time(&com_time);
    strftime(local_time, sizeof(local_time), "[%Y%m%d_%H%M%S]", localtime(&com_time));
    std::cout << local_time ;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:"<< getNbAccounts() \
    << ";total:" << getTotalAmount() \
    << ";deposits:" << getNbDeposits() \
    << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account()
{
    ;
}


Account::Account(int initial_deposit)
{
    static int i;

    _displayTimestamp();
    _amount = initial_deposit;
    _accountIndex = i++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += _amount;
    _nbAccounts = i;
    std::cout << " index:" << _accountIndex << \
    ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account()
{
    ;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << \
    ";p_amount:" << _amount << ";deposits:" << \
    deposit << ";amount:" << (_amount + deposit) << \
    ";nb_deposits:" << ++_nbDeposits << std::endl;
    _amount += deposit;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << \
    ";amount:" << _amount << ";deposits:" << _nbDeposits << \
    ";withdrawals:" << _nbWithdrawals << std::endl;
}