#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include"AdminManager.h"
#include"ClientManager.h"
#include"BankManagerManager.h"
#include<algorithm>
#include<cmath>

#define NOMINMAX 
#include <windows.h>

#define new_page system("cls")
class Screens
{
public:

	static void bankName() {
		new_page;
		system("color 87");
		cout << "\n\n\n\n";
		cout << "\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" << endl;
		cout << "\n\t\t\t\t\t   _____                _____    _____    _   _ " << endl;
		cout << "\t\t\t\t\t  |  __ \\      /\\      |___  |  |_   _|  | \\ | |" << endl;
		cout << "\t\t\t\t\t  | |__) |    /  \\        / /     | |    |  \\| |" << endl;
		cout << "\t\t\t\t\t  |  _  /    / /\\ \\      / /      | |    | . ` |" << endl;
		cout << "\t\t\t\t\t  | | \\ \\   / ____ \\    / /__    _| |_   | |\\  |" << endl;
		cout << "\t\t\t\t\t  |_|  \\_\\ /_/    \\_\\  /_____|  |_____|  |_| \\_|" << endl;

		cout << "\n\n\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" << endl;
		cout << "\t\t\t\t\t           THE FUTURE OF BANKING SYSTEMS          " << endl;
		cout << "\t\t\t\t\t       Created by: Eng. Zeinab & Eng. Rewan        " << endl;
		cout << "\n\n\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "\n\n\n";
		system("pause");
	}

	static void welcome() {
		new_page;
		int t = 100;
		cout << "\n\n\n\n";
		cout << "\t\t\t      __          __  ______  _        _____   ____   __  __  _____ " << endl;
		Sleep(t);
		cout << "\t\t\t      \\ \\        / / |  ____|| |      / ____| / __ \\ |  \\/  ||  ___|" << endl;
		Sleep(t);
		cout << "\t\t\t       \\ \\  /\\  / /  | |__   | |     | |     | |  | || \\  / || |__  " << endl;
		Sleep(t);
		cout << "\t\t\t        \\ \\/  \\/ /   |  __|  | |     | |     | |  | || |\\/| ||  __| " << endl;
		Sleep(t);
		cout << "\t\t\t         \\  /\\  /    | |____ | |____ | |____ | |__| || |  | || |____" << endl;
		Sleep(t);
		cout << "\t\t\t          \\/  \\/     |______||______| \\_____| \\____/ |_|  |_||______|" << endl;
		Sleep(t);

		cout << "\n\n\t\t\t\t\t            ========= TO =========" << endl;
		Sleep(t);
		cout << "\n\t\t\t\t\t     _____            _____  _____  _   _ " << endl;
		Sleep(t);
		cout << "\t\t\t\t\t    |  __ \\    /\\    |___  ||_   _|| \\ | |" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t    | |__) |  /  \\      / /   | |  |  \\| |" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t    |  _  /  / /\\ \\    / /    | |  | . ` |" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t    | | \\ \\ / ____ \\  / /__  _| |_ | |\\  |" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t    |_|  \\_/_/    \\_\\/_____||_____||_| \\_|" << endl;
		Sleep(t);

		cout << "\n\n\t\t\t\t\t        --- FINANCIAL SYSTEM v1.0 ---" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t_____________________________________________" << endl;
		Sleep(t);
		cout << "\n\n";
		system("pause");
	}

	static void loginOptions() {
		new_page;
		cout << "------------------------------------\n";
		cout << "           Login Options            \n";
		cout << "------------------------------------\n";
		cout << "\n   Please select your login type:\n";
		cout << "\n   [1] Login as Admin\n";
		cout << "\n   [2] Login as Employee\n";
		cout << "\n   [3] Login as Client\n";
		cout << "\n   [4] Exit\n";
		cout << "\n   Please enter your choice (1-4): ";
	}

	static int loginAs() {
		int choice;
		cin >> choice;
		return choice;
	}

	static void invalid(int &c) {
		while (c < 1 || c > 4) {
			cin.clear();
			cout << "\n\t [!] Invalid choice. Please enter a number between 1 and 4: ";
			cin >> c;	
		}
	}

	static void loginSystem(int type){
		int attempts = 0;
		while (attempts < 3) {
			cout << "\n [~] Enter ID: ";
			int id;
			cin >> id;
			cout << "\n [~] Enter Password: ";
			string password;
			cin >> password;

			switch (type)
			{
				case 1:
					if (BankManagerManager::login(id, password))
					{
						BankManager* bm = BankManager::getManager();
						while (BankManagerManager::BankManagerOptions(bm));
						cout << "\n\n";
						system("pause");
						return;
					}
					else if (Admin* admin = AdminManager::login(id, password)) {
						while (AdminManager::AdminOptions(admin));
						cout << "\n\n";
						system("pause");
						return;
					}
					break;
				case 2:
					if (Employee* employee = EmployeeManager::login(id, password)) {
						while (EmployeeManager::employeeOptions(employee));
						cout << "\n\n";
						system("pause");
						return;
					}
					break;
				case 3:
					if (Client* client = ClientManager::login(id, password)) {
						while (ClientManager::clientOptions(client));
						cout << "\n\n";
						system("pause");
						return;
					}
					break;
			}
			attempts++;
			cout << "\n [!] Invalid ID or Password, " << (3 - attempts) << " attemps remain!\n";
		}
		cout << "\n\n\n\n";
		system("pause");
		cout << "\n [!!!] Too many failed attempts. Access Denied.\n";
		logout();
		return;
	}

	static void logout() {
		new_page;
		cout << "\n [*] Thanks for your time ,Goodbye (*^_^*)\n\n";
	}
		
	static void loginScreen(int c) {
		switch (c) {
		case 1:
			new_page;
			cout << "-------------------------------------------\n";
			cout << "                Admin Login                \n";
			cout << "-------------------------------------------\n";
			loginSystem(1);
			break;
		case 2:
			new_page;
			cout << "------------------------------------\n";
			cout << "         Employee Login             \n";
			cout << "------------------------------------\n";
			loginSystem(2);
			break;
		case 3:
			new_page;
			cout << "------------------------------------\n";
			cout << "           Client Login              \n";
			cout << "------------------------------------\n";
			loginSystem(3);
			break;
		case 4:
			logout();
			 break;
		default:
			cout << "\n\t [!] Invalid choice.";
			break;
		}
	}

	static void getAllData() {
		FilesHelper::getClients();
		FilesHelper::getEmployees();
		FilesHelper::getAdmins();
		int lastClient = FilesHelper::getLast("lastIdClient.txt");
		int lastAdmin = FilesHelper::getLast("lastIdAdmin.txt");
		int lastEmployee = FilesHelper::getLast("lastIdEmployee.txt");
		Person::idCounter = max({ lastClient ,lastAdmin ,lastEmployee });
		BankManager *BM = BankManager::getManager();
	}

	static void runApp() {
		getAllData();
		bankName();
		welcome();
		while (true) { 
			loginOptions();
			int choice = loginAs();
			invalid(choice);
			if (choice == 4) {
				logout();
				break;
			}
			loginScreen(choice); 
		}
	}

};