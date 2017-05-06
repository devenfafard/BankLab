#include "Account.h"
#include <iostream>
using namespace std;
#include <string>

Account::Account(Customer customer, int accountNumber) : _accountOwner(customer), _accountNumber(accountNumber)
{		
}

Account::~Account()
{
}



Customer Account::getOwner()
{
	return this->_accountOwner;
}

void Account::Deposit(int numberOfPennies)
{
	_balanceInPennies += numberOfPennies;	
	std::string newEntry = "Deposited " + std::to_string(numberOfPennies) + " cents into " + std::to_string(getAccountNumber()) + "\n";
	_log.push_back(newEntry);
}

void Account::Withdraw(int numberOfPennies)
{
	_balanceInPennies -= numberOfPennies;
	std::string newEntry = "Withdrew " + std::to_string(numberOfPennies) + " cents from " + std::to_string(getAccountNumber()) + "\n";
	_log.push_back(newEntry);
}

string Account::ShowAccountLog()
{
	string output = "";
	for (std::string l : _log)
	{
		output += l;
	}

	return output;
}

int Account::getBalance()
{
	return _balanceInPennies;
}

int Account::getAccountNumber()
{
	return _accountNumber;
}
