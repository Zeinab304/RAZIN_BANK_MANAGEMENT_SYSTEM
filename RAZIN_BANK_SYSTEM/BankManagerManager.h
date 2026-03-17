#pragma once
#include"BankManager.h"
#include"AdminManager.h"

class BankManagerManager
{
public:
	static void printManagerMenu() {
		new_page;
		cout << "------------------------------------------\n";
		cout << "          BANK MANAGER MAIN MENU          \n";
		cout << "------------------------------------------\n";
		cout << "\n [1] Add New Admin" << endl;
		cout << "\n [2] List All Admins" << endl;
		cout << "\n [3] Search For Admin" << endl;
		cout << "\n [4] Edit Admin Info" << endl;
		cout << "\n [5] Manage Employees (Go to Admin Menu)" << endl;
		cout << "\n [6] View Total Salaries" << endl;
		cout << "\n [7] View Bank Financial Report" << endl;
		cout << "\n [8] Logout" << endl;
		cout << "\n [?] Please enter your choice (1-8): ";
	}

	static void showTotalSalaries(BankManager* bm) {
		new_page;
		cout << "-------------------------------------\n";
		cout << "          TOTAL BANK SALARIES        \n";
		cout << "-------------------------------------\n";
		cout << "\n\n Total Bank Salaries: $" << bm->calculateTotalSalaries() << endl;
		cout << "\n\n\n\n";
		system("pause");
	}

	static void showBankReports(BankManager* bm) {
		new_page;
		cout << "----------------------------------------\n";
		cout << "          BANK FINANCIAL REPORT         \n";
		cout << "----------------------------------------\n";
		cout << "\n [~] Total Salaries to pay: $" << bm->calculateTotalSalaries();
		cout << "\n [~] Number of Admins: " << AllAdmins.size();
		cout << "\n [~] Number of Employees: " << AllEmployees.size();
		cout << "\n [~] Number of Clients: " << AllClients.size();
		cout << "\n\n\n\n";
		system("pause");
	}

	static void addNewAdmin(BankManager* bm) {
		new_page;
		int id;
		string newName, newPass;
		double newSalary;
		cout << "----------------------------------\n";
		cout << "           ADD NEW ADMIN          \n";
		cout << "----------------------------------\n";
		id = ++(Person::idCounter);
		cout << "\n [~] Admin ID: " << id << " (Generated)\n";

		cout << "\n [~] Enter New Name : ";
		cin >> newName;
		Validation::checkName(newName);

		cout << "\n [~] Enter New Passward : ";
		cin >> newPass;
		Validation::checkPWD(newPass);

		cout << "\n [~] Enter New Salary :$ ";
		cin >> newSalary;
		Validation::checkSalary(newSalary);

		Admin a(id, newName, newPass, newSalary);
		bm->addAdmin(a);
		FilesHelper::updateAdminsFile();
		cout << "\n\n\n";
		system("pause");
	}

	static void listAllAdmin(BankManager* bm) {
		new_page;
		cout << "------------------------------------\n";
		cout << "          LIST ALL ADMINS           \n";
		cout << "------------------------------------\n";
		bm->listAdmin();
		cout << "\n\n\n\n";
		system("pause");
	}

	static void searchForAdmin(BankManager* bm) {
		int id;
		new_page;
		cout << "-------------------------------------\n";
		cout << "         SEARCH FOR Admin         \n";
		cout << "-------------------------------------\n";
		cout << "\n [~] Enter Admin's ID : ";
		cin >> id;
		Admin* e = bm->searchAdmin(id);
		if (e != nullptr) {
			cout << "\n [*] Admin founded: \n";
			e->display();
			cout << "\n\n\n\n";
			system("pause");
		}
		else
			cout << "\n [!] Admin Not found..!";
	}

	static void editAdmin(BankManager* bm) {
		int id;
		string newName, newPass;
		double newSalary;
		new_page;
		cout << "-----------------------------\n";
		cout << "         EDIT Admin       \n";
		cout << "-----------------------------\n";
		cout << "\n [~] Enter Admin's ID : ";
		cin >> id;

		cout << "\n [~] Enter New Name : ";
		cin >> newName;
		Validation::checkName(newName);

		cout << "\n [~] Enter New Passward : ";
		cin >> newPass;
		Validation::checkPWD(newPass);

		cout << "\n [~] Enter New Salary : ";
		cin >> newSalary;
		Validation::checkSalary(newSalary);

		bm->editAdmin(id, newName, newPass, newSalary);
		FilesHelper::updateAdminsFile();
		cout << "\n\n\n\n";
		system("pause");
	}

	static bool login(int id, string password){
		if (id == 99999 && password == "Ahmed#Abdo_99") {
			cout << "\n [^_^] Login successful! Welcome, MR\\ Ahmed Abdo" << endl;
			cout << "\n\n\n\n";
			system("pause");
			return true;
		}
		return false;
	}

	static bool BankManagerOptions(BankManager* bm) {

		printManagerMenu();

		int choice;
		cin >> choice;

		switch (choice) {
		case 1:
			addNewAdmin(bm);
			break;
		case 2:
			listAllAdmin(bm);
			break;
		case 3:
			searchForAdmin(bm);
			break;
		case 4:
			editAdmin(bm);
			break;
		case 5:
			while (AdminManager::AdminOptions(bm));
			break;
		case 6:
			showTotalSalaries(bm);
			break;
		case 7:
			showBankReports(bm);
			break;
		case 8:
			new_page;
			cout << "\n\n\n [*] Thanks " << bm->getName() << " for your time ,Goodbye (*^_^*)\n\n";
			return false;
			break;
		default:
			cout << "\n [!] Invalid Choice !!";
		}
		return true;
	}

};

