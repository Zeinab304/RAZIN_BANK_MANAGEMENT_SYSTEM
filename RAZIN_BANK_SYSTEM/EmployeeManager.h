#pragma once
#include "Employee.h"
#include "FilesHelper.h"
#define new_page system("cls")
class EmployeeManager
{
	static void printEmployeeMenu() {
		new_page;
		cout << "------------------------------------\n";
		cout << "          Employee Main Menu          \n";
		cout << "------------------------------------\n";
		cout << "\n [1] Add New Client " << endl;
		cout << "\n [2] List All Clients " << endl;
		cout << "\n [3] Search For Client " << endl;
		cout << "\n [4] Edit Client Info " << endl;
		cout << "\n [5] Edit Client State " << endl;
		cout << "\n [6] Display My Info " << endl;
		cout << "\n [7] Check Salary " << endl;
		cout << "\n [8] Logout " << endl;
		cout << "\n [?] Pleace enter a choice (1-8) : ";
	}

	static void newClient(Employee* employee) {
		new_page;
		cout << "-------------------------------------\n";
		cout << "           ADD NEW CLIENT            \n";
		cout << "-------------------------------------\n";

		int id = ++(Person::idCounter);
		string name, password;
		double balance;

		cout << "\n [~] Client ID: " << id << " (Generated)\n";

		cout << "\n [~] Enter Name: ";
		cin >> name;
		Validation::checkName(name);

		cout << "\n [~] Enter Password: ";
		cin >> password;
		Validation::checkPWD(password);

		cout << "\n [~] Enter Initial Balance: ";
		cin >> balance;
		Validation::checkBalance(balance);

		Client c(id, name, password, balance);
		employee->addClient(c);
		FilesHelper::updateClientsFile();
		cout << "\n [^_^] Client added successfully!\n";
		cout << "\n\n\n\n";
		system("pause");
	}

	static void listAllClients(Employee* employee) {
		new_page;
		cout << "-------------------------------------\n";
		cout << "         LIST ALL CLIENTS            \n";
		cout << "-------------------------------------\n";
		employee->listClient();
		cout << "\n\n\n\n";
		system("pause");
	}
	static void searchForClient(Employee* employee) {
		new_page;
		cout << "-------------------------------------\n";
		cout << "          SEARCH FOR CLIENT          \n";
		cout << "-------------------------------------\n";
		int id;
		cout << " Enter Client ID to search: ";
		cin >> id;
		Client* c = employee->searchClient(id); 
		if (c != nullptr) {
			cout << "\n [*] Client found:\n\n";
			c->display();
		}
		else {
			cout << "\n [!] Client not found.\n";
		}
		cout << "\n\n\n\n";
		system("pause");
	}

	static void editClientInfo(Employee* employee) {
		int id;
		string newName, newPass;
		double newBalance;
		new_page;
		cout << "-----------------------------\n";
		cout << "          EDIT CLIENT        \n";
		cout << "-----------------------------\n";
		cout << "\n [~] Enter Client's ID : ";
		cin >> id;

		cout << "\n [~] Enter New Name : ";
		cin >> newName;
		Validation::checkName(newName);

		cout << "\n [~] Enter New Passward : ";
		cin >> newPass;
		Validation::checkPWD(newPass);

		cout << "\n [~] Enter New Balance :$ ";
		cin >> newBalance;
		Validation::checkBalance(newBalance);

		employee->editClient(id, newName, newPass, newBalance);
		FilesHelper::updateClientsFile();
		cout << "\n\n\n\n";
		system("pause");
	}
	static void editClientState(Employee* employee) {
		int id;
		bool newState;
		new_page;
		cout << "-----------------------------\n";
		cout << "       EDIT CLIENT STATE     \n";
		cout << "-----------------------------\n";
		cout << "\n [~] Enter Client's ID : ";
		cin >> id;
		Client* c = employee->searchClient(id);
		if (c != nullptr) {
			cout << "\n [*] Current State: " << (c->getStatus() ? "Active" : "Frozen");
			cout << "\n [~] Enter New State (1 for Active, 0 for Frozen): ";
			cin >> newState;
			employee->editStatus(*c, newState);
			FilesHelper::updateClientsFile();
		}
		else {
			cout << "\n [!] Client not found.\n";
		}
		cout << "\n\n\n\n";
		system("pause");
	}

	static void employeeInfo(Employee* employee) {
		new_page;
		cout << "-----------------------------\n";
		cout << "         EMPLOYEE INFO       \n";
		cout << "-----------------------------\n";
		employee->display();
		cout << "\n\n\n\n";
		system("pause");
	}
	static void checkSalary(Employee* employee) {
		new_page;
		cout << "----------------------------------\n";
		cout << "            CHECK SALARY          \n";
		cout << "----------------------------------\n";
		cout << "\n [~] Your Current Salary:$ " << employee->getSalary();
		cout << "\n\n\n\n";
		system("pause");
	}

public:

	static Employee* login(int id, string password) {
		for (int i = 0; i < AllEmployees.size(); i++) {
			if (AllEmployees[i].getId() == id && AllEmployees[i].getPassword() == password) {
				cout << "\n [*] Login successful! Welcome, " << AllEmployees[i].getName();
				cout << "\n\n\n\n";
				system("pause");
				return &AllEmployees[i];
			}
		}
		return nullptr;
	}

	static bool employeeOptions(Employee* employee){

		printEmployeeMenu();

		int choice;

		cin >> choice;
		switch (choice) {
		case 1:
			newClient(employee);
			break;
		case 2:
			listAllClients(employee);
			break;
		case 3:
			searchForClient(employee);
			
			break;
		case 4:
			editClientInfo(employee);
			break;
		case 5:
			editClientState(employee);
			break;
		case 6:
			employeeInfo(employee);
			break;
		case 7:
			checkSalary(employee);
			break;
		case 8:
			new_page;
			cout << "\n [*] Thanks " << employee->getName() << " for your time ,Goodbye (*^_^*)\n\n";
			return false;
			break;
		default:
			cout << "\n [!] Invalid Choice !!";
		}
		return true;
	}

};

