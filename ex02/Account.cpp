/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:51:45 by adrian            #+#    #+#             */
/*   Updated: 2024/09/18 19:39:26 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}
int Account::getNbAccounts(void)
{
    return _nbAccounts;
}
int Account::getTotalAmount(void)
{
    return _totalAmount;
}
int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}
int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount 
              << ";deposits:" << _totalNbDeposits 
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount 
              << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    if (_amount >= withdrawal)
    {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << ";withdrawal:" << withdrawal 
                  << ";amount:" << _amount 
                  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
    else
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
}
int Account::checkAmount(void) const
{
    return _amount;
}
void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount 
              << ";deposits:" << _nbDeposits 
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}
void Account::_displayTimestamp(void)
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    std::cout << "[" << (now->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << now->tm_mon + 1
              << std::setw(2) << std::setfill('0') << now->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec << "] ";
}
