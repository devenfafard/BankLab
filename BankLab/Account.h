#pragma once
#include <vector>
#include "Customer.h"

class Account
{
private:
	int _accountNumber;
	int _balanceInPennies = 0;	
	Customer _accountOwner;
	std::vector<std::string> _log;
public:
	Account(Customer customer, int accountNumber);
	~Account();

	Customer getOwner();
	void Deposit(int numberOfPennies);
	void Withdraw(int numberOfPennies);
	std::string ShowAccountLog();
	int getBalance();
	int getAccountNumber();
};