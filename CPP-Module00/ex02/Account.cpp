#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// 静的メンバの定義
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// --- コンストラクタ / デストラクタ ---
Account::Account(int initial_deposit)
: _accountIndex(_nbAccounts),
  _amount(initial_deposit),
  _nbDeposits(0),
  _nbWithdrawals(0)
{
	_nbAccounts += 1;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";closed" << std::endl;
}

// --- static アクセサ ---
int		Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int		Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
	          << ";total:" << getTotalAmount()
	          << ";deposits:" << getNbDeposits()
	          << ";withdrawals:" << getNbWithdrawals()
	          << std::endl;
}

// --- インスタンスメソッド ---
void	Account::makeDeposit(int deposit)
{
	int p_amount = _amount;

	_amount += deposit;
	_nbDeposits += 1;

	_totalAmount += deposit;
	_totalNbDeposits += 1;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";p_amount:" << p_amount
	          << ";deposit:" << deposit
	          << ";amount:" << _amount
	          << ";nb_deposits:" << _nbDeposits
	          << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int p_amount = _amount;

	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
		          << ";p_amount:" << p_amount
		          << ";withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals += 1;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";p_amount:" << p_amount
	          << ";withdrawal:" << withdrawal
	          << ";amount:" << _amount
	          << ";nb_withdrawals:" << _nbWithdrawals
	          << std::endl;
	return true;
}

int		Account::checkAmount(void) const
{
	return (Account::_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";deposits:" << _nbDeposits
	          << ";withdrawals:" << _nbWithdrawals
	          << std::endl;
}

// タイムスタンプ表示 [YYYYMMDD_HHMMSS]
void	Account::_displayTimestamp(void)
{
	std::time_t	t = std::time(NULL);
	std::tm		*lt = std::localtime(&t);

	std::cout << '['
	          << std::setw(4) << std::setfill('0') << (lt->tm_year + 1900)
	          << std::setw(2) << std::setfill('0') << (lt->tm_mon + 1)
	          << std::setw(2) << std::setfill('0') << lt->tm_mday
	          << '_'
	          << std::setw(2) << std::setfill('0') << lt->tm_hour
	          << std::setw(2) << std::setfill('0') << lt->tm_min
	          << std::setw(2) << std::setfill('0') << lt->tm_sec
	          << "] ";
}
