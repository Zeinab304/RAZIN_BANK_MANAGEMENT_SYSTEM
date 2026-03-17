#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Validation
{
public:
	static bool isValidName(string name) {
		if (name.length() >= 5 && name.length() <= 20)
		{
			for (auto i : name) {
				if (!((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))) {
					cout << "\n [Error] name must be only alphabetic characters without spaces!!\n";
					return false;
				}
			}
			return true;
		}
		cout << "\n [Error] min size 5 and max size 20!!\n";
		return false;
	}

	static bool isValidPWD(string password) {
		if (password.length() >= 8 && password.length() <= 20)
		{
			for (auto i : password) {
				if (!((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9') || i == '_' || i == '#'))
					return false;
			}
			return true;
		}
		cout << "\n [Error] Min size 8 and Max size 20!!";
		return false;
	}

	static bool passwordState(string password) {
		int score = 0;
		int upper = 0, lower = 0, digit = 0, special = 0;

		for (auto i : password) {
			if (i >= 'A' && i <= 'Z') upper++;
			else if (i >= 'a' && i <= 'z') lower++;
			else if (i >= '0' && i <= '9') digit++;
			else if (i == '_' || i == '#') special++;
		}

		if (upper >= 1) score++;
		else cout << " [!] not enough upper char.\n";
		if (lower >= 2) score++;
		else cout << " [!] not enough lower char.\n";
		if (digit >= 2) score++;
		else cout << " [!] not enough digit.\n";
		if (special >= 1) score++;
		else cout << " [!] at least one special char (#,_).\n";

		if (score <= 2) {
			cout << "\n [x] Password State: Weak\n";
			return false;
		}
		else {
			cout << "\n [*]Password State: Strong\n";
			return true;
		}
	}

	static bool isValidBalance(double balance) {
		return(balance >= 1500);
	}

	static bool isValidSalary(double salary) {
		return(salary >= 5000);
	}

	static string encrypt(string password) {
		for (int i = 0; i < password.length(); i++)
			password[i]++;
		return password;
	}

	static string decrypt(string encryptedpwd) {
		for (int i = 0; i < encryptedpwd.length(); i++)
			encryptedpwd[i]--;
		return encryptedpwd;
	}

	static void checkPWD(string password){
		while (!Validation::isValidPWD(password)|| !Validation::passwordState(password)) {
			cout << "\n [Error] Invalid password!\n";
			cout << "\n [~] Re-enter: ";
			cin >> password;
			cout << endl;
		}
	}

	static void checkBalance(double balance) {
		while (!Validation::isValidBalance(balance)) {
			cout << "\n [~] Balance must be at least 1500$\n";
			cout << "\n [Error] Invalid balance!\n";
			cout << "\n [~] Re-enter: ";
			cin >> balance;
			cout << endl;
		}
	}

	static void checkSalary(double salary) {
		while (!Validation::isValidSalary(salary)) {
			cout << "\n [~] Salary must be at least 5000$\n";
			cout << "\n [Error] Invalid salary!\n";
			cout << "\n [~] Re-enter: ";
			cin >> salary;
			cout << endl;
		}
	}

	static void checkName(string name) {
		while (!Validation::isValidName(name)) {
			cout << "\n [Error] Invalid name!\n";
			cout << "\n [~] Re-enter: ";
			cin >> name;
			cout << endl;
		}
	}
};

