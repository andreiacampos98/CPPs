# include "Account.hpp"
# include <iostream>
# include <iomanip>
# include <ctime>

int	Account::_nbAccounts = 0;

int	Account::_totalNbWithdrawals = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalAmount = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:";
	std::cout << this->checkAmount() <<";created" << std::endl;
	Account::_nbAccounts++;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:";
	std::cout << this->checkAmount() <<";closed" << std::endl;
	Account::_nbAccounts--;
}

void	Account::_displayTimestamp(void)
{
	time_t	now;

	now = time(NULL);
	std::cout << std::put_time(localtime(&now), "[%Y%m%d_%H%M%S] ");
}

int	Account::getNbAccounts(void)
{
	return(Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return(Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return(Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return(Account::_totalNbWithdrawals);
}
void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << ";" <<  std::endl;
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << ";" <<  std::endl;
}


void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	time_t curr_time;
	time(&curr_time);
	std::cout << "[curr_time] ";
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount + deposit;
	std::cout << ";nb_deposits:" << this->_nbDeposits << ";" <<  std::endl;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	time_t curr_time;
	time(&curr_time);
	std::cout << "[curr_time] ";
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";withdrawal:" << withdrawal;
	if(withdrawal > this->checkAmount())
	{
		std::cout << "refused" <<std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	std::cout << ";amount:" << this->checkAmount() - withdrawal;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << ";" <<  std::endl;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return (true);
}