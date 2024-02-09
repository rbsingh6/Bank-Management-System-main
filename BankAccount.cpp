#include <iostream>

#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount(string username, string password)
{
	this->username = username;
	this->password = password;
}

void BankAccount::deposit(double amount)
{
	this->amount += amount;
}

void BankAccount::withdraw(double amount)
{
	this->amount -= amount;
}

void BankAccount::viewBalance()
{
	cout << "Your balance is: " << this->amount << endl;
}