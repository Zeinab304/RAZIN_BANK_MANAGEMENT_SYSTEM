#pragma once
#include"Person.h"

class Client:public Person
{
private:
	double balance = 0.0;
	bool status = true;
public:

	Client() {
		balance = 0.0;
		status = true;
	}

	Client(int id, string name, string password, double balance) :Person(id, name, password) {
		setBalance(balance);
	}

	Client(int id, string password) :Person(id, password) {
		this->balance = 0.0;
		this->status = true;
	}

	void setAllDate(int id, string name, string password, double balance) {
		this->id = id;
		setBalance(balance);
		setName(name);
		setPassword(password);
	}

	void setBalance(double balance) {
		this->balance = balance;
	}

	bool getStatus() {
		return this->status;
	}

	void setStatus(bool status) {
		this->status = status;
	}

	double getBalance() {
		return this->balance;
	}

	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			cout << " [~] Current balance= " << balance << "$";
			cout << "\n [^_^] Deposit successfully !" << endl;
		}
		else
		    cout << " [Error] Invalid amount !";
	}

	void withdraw(double amount) {
		if (status) {
			if (amount < balance) {
				balance -= amount;
				cout << " [~] Current balance= " << balance << "$";
				cout << "\n [^_^] Withdraw successfully !" << endl;
			}
			else if (amount == balance) {
				cout << " [Warning] You will withdraw all your balance!!\n";
				cout << " [?] Do you want to continue 1) continue\t0) cancelled : ";
				int choice;
				cin >> choice;
				if (choice == 1) {
					balance -= amount;
					cout << " [^o^] Your account is empty\n";
				}
				else
				{
					cout << " [x] Withdraw Cancelled......\n";
					return;
				}
			}

			else
				cout << "\n [!] Insufficient balance!" << endl;
		}
		else
			cout << "\n [!] Sorry your account is frozen!";
	}

	void transferTo(double amount, Client& recipient) {
		if (status) {
			withdraw(amount);
			recipient.deposit(amount);
			cout << " [^-^] Transfer successful!" << endl;
		}
		else
			cout << "\n [!] Sorry your account is frozen!";
	}

	void display() {
		Person::display();
		cout << "\n\tBalance: " << this->balance;
		cout << "\n\tStatus: " << (status ? "Active" : "Frozen") << endl;;
	}

};

static vector<Client> AllClients;