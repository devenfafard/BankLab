#include "Bank.h"
#include <iostream>
using namespace std;

Bank::Bank(std::string name) : _name(name)
{	
}

Bank::~Bank()
{
}

std::string Bank::getName()
{
	return _name;
}

void Bank::CreateAccount(Account newAccount)
{
	_accounts.push_back(newAccount);
}

std::string Bank::ShowAccounts()
{
	std::string output = "Accounts for " + _name + "\n";
	for (Account account : _accounts)
	{		
		output += "Account #: " + to_string(account.getAccountNumber()) + "\n" + 
			      "Name: " + account.getOwner().getFullName() + "\n" +
			      "Balance: " + to_string(account.getBalance()) + "\n\n";
	}
	return output;
}

std::string Bank::ListAccounts()
{
	std::string output = "Accounts for " + _name + "\n";
	for (Account account : _accounts)
	{
		output += " - " + std::to_string(account.getAccountNumber()) + "\n";
	}
	return output;
}

void Bank::Deposit(int accountNumber, int amount)
{
	for (Account &account : _accounts) {
		if (account.getAccountNumber() == accountNumber)
		{
			account.Deposit(amount);
			return;
		}
		else
		{
			cout << endl << "Error with transaction!" << endl;
			system("pause");
		}
	}
	return;
}

void Bank::Withdraw(int accountNumber, int amount)
{
	for (Account &account : _accounts) {
		if (account.getAccountNumber() == accountNumber && account.getBalance() > 0 && amount < account.getBalance()) 
		{
			account.Withdraw(amount);
			return;
		}
		else
		{
			cout << endl << "Error with transaction!" << endl;
			system("pause");
		}
	}
	return;
}

Account Bank::GetAccount(int accountNum)
{
	for (Account a : _accounts) {
		if (a.getAccountNumber() == accountNum)
		{
			return a;
		}
	}
}
