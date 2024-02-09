#ifndef BANKACCOUNTH
#define BANKACCOUNTH

#include <string>

using namespace std;

class BankAccount
{
	public:
	
		BankAccount(string username, string password);
	
		void deposit(double amount);
	
		void withdraw(double amount);
	
		void viewBalance();
	
	private:
		
		string username;
		
		string password;
		
		double amount;
};

#endif