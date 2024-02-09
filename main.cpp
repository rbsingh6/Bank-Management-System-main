#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "BankAccount.h"

using namespace std;

int main()
{
	string username;
	string password;
	double amount = 0;

	while (true)
	{
		cout << setw(35) << "Bank Management System" << endl;
		cout << endl;

		cout << "Username: ";
		cin >> username;
		cout << "\n";
		cout << "Password: ";
		cin >> password;

		if (username == "admin" && password == "password")
		{
			system("cls");
			while (true)
			{
				cout << setw(35) << "Admin's Main Menu" << endl;
				cout << endl;
				cout << "1. Add Account" << endl;
				cout << "2. Delete Account" << endl;
				cout << "3. View Account Details" << endl;
				cout << "4. Exit" << endl;
				cout << endl;
				cout << "Enter your choice: ";
				int choice;
				cin >> choice;
				cout << endl;

				if (choice == 1)
				{
					cout << "Enter the username: ";
					cin >> username;
					cout << "\n";
					cout << "Enter the password: ";
					cin >> password;
					cout << "\n";
					cout << "Enter the amount to deposit: ";
					cin >> amount;
					cout << endl;
					cout << "Account successfully added!" << endl;
					system("pause");
					system("cls");

					BankAccount account(username, password);

					ofstream outFile;
					outFile.open("accounts.txt", ios::app);
					outFile << endl;
					outFile << username << " " << password << endl;
					outFile.close();

					outFile.open("log.txt", ios::app);
					outFile << "Add Account: " << username << " " << password << " " << amount << endl;
					outFile.close();
				}
				else if (choice == 2)
				{
					cout << "Enter the username: ";
					cin >> username;
					cout << "\n";
					cout << "Enter the password: ";
					cin >> password;
					cout << "\n";
					cout << "Account successfully deleted!" << endl;
					system("pause");
					system("cls");

					BankAccount account(username, password);

					ifstream inFile;
					inFile.open("accounts.txt");
					string line;
					while (getline(inFile, line))
					{
						if (line == username + " " + password)
						{
							inFile.close();
							ofstream outFile;
							outFile.open("accounts.txt");
							while (getline(inFile, line))
							{
								if (line != username + " " + password)
								{
									outFile << line << endl;
								}
							}
							outFile.close();
							break;
						}
					}
					inFile.close();

					ofstream outFile;
					outFile.open("log.txt", ios::app);
					outFile << "Delete Account: " << username << " " << password << endl;
					outFile.close();
				}
				else if (choice == 3)
				{
					cout << "Enter the username: ";
					cin >> username;
					cout << "\n";
					cout << "Enter the password: ";
					cin >> password;
					cout << "\n";

					BankAccount account(username, password);

					ifstream inFile;
					inFile.open("accounts.txt");
					string line;
					while (getline(inFile, line))
					{
						if (line == username + " " + password)
						{
							inFile.close();
							cout << "Username: " << username << endl;
							cout << "Password: " << password << endl;
							cout << "Amount: " << amount << endl;
							cout << "\n";
							break;
						}
					}
					
					inFile.close();
					
					ofstream outFile;
					outFile.open("log.txt", ios::app);
					outFile << "View Account: " << username << " " << password << endl;
					outFile.close();
					system("pause");
					system("cls");
				}
				else if (choice == 4)
				{
					system("cls");
					break;
				}
				else
				{
					cout << "Invalid choice!" << endl;
				}
			}
		}
		
		ifstream inFile;
		inFile.open("accounts.txt");
		string line;
		while (getline(inFile, line))
		{
			if (line == username + " " + password)
			{
				cout << setw(35) << "\n\nLogin successful!" << endl;
				system("cls");
				break;
			}
		}
		inFile.close();

		if (line != username + " " + password)
		{
			cout << setw(35) << "\n\nLogin failed!" << endl;
			system("pause");
			system("cls");
			continue;
		}

		ofstream outFile;
		outFile.open("log.txt", ios::app);
		outFile << username << " " << password << endl;
		outFile.close();

		while (true)
		{
			cout << setw(35) << "Main Menu" << endl;
			cout << endl;
			cout << "1. Deposit Money" << endl;
			cout << "2. Withdraw Money" << endl;
			cout << "3. View Balance" << endl;
			cout << "4. Exit" << endl;
			cout << endl;
			cout << "Enter your choice: ";
			int choice;
			cin >> choice;
			cout << endl;

			if (choice == 1)
			{
				cout << "Enter the amount to deposit: ";
				cin >> amount;
				cout << endl;

				BankAccount account(username, password);
				account.deposit(amount);

				outFile.open("log.txt", ios::app);
				outFile << "Deposit: " << amount << endl;
				outFile.close();
			}
			else if (choice == 2)
			{
				cout << "Enter the amount to withdraw: ";
				cin >> amount;
				cout << endl;

				BankAccount account(username, password);
				account.withdraw(amount);

				outFile.open("log.txt", ios::app);
				outFile << "Withdraw: " << amount << endl;
				outFile.close();
			}
			else if (choice == 3)
			{
				BankAccount account(username, password);
				account.viewBalance();
			}
			else if (choice == 4)
			{
				system("cls");
				break;
			}
			else
			{
				cout << "Invalid choice!" << endl;
			}
			system("pause");
			system("cls");
		}
	}
	return 0;
}