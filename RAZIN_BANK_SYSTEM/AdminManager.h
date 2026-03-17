#pragma once
#include"Admin.h"
#include"EmployeeManager.h"
#include"FilesHelper.h"
#define new_page system("cls")

class AdminManager
{

	static void printAdminMenu() {
		new_page;
		cout << "------------------------------------\n";
		cout << "          Admin Main Menu          \n";
		cout << "------------------------------------\n";
		cout << "\n [1] Add New Employee" << endl;
		cout << "\n [2] List All Employees" << endl;
		cout << "\n [3] Search For Employee" << endl;
		cout << "\n [4] Edit Employee Info" << endl;
		cout << "\n [5] Manage Clients (Go to Employee Menu)" << endl;
		cout << "\n [6] Display My Info" << endl;
		cout << "\n [7] Logout" << endl;
		cout << "\n [?] Please enter your choice (1-7): ";
	}

	static void addNewEmployee(Admin* Admin) {
		new_page;
		int id;
		string newName, newPass;
		double newSalary;
		cout << "-------------------------------------\n";
		cout << "         ADD NEW EMPLOYEE            \n";
		cout << "-------------------------------------\n";
		id = ++(Person::idCounter);
		cout << "\n [~] Employee ID: " << id << " (Generated)\n";

		cout << "\n [~] Enter New Name : ";
		cin >> newName;
		Validation::checkName(newName);

		cout << "\n [~] Enter New Passward : ";
		cin >> newPass;
		Validation::checkPWD(newPass);

		cout << "\n [~] Enter New Salary :$ ";
		cin >> newSalary;
		Validation::checkSalary(newSalary);

		Employee em(id, newName, newPass, newSalary);
		Admin->addEmployee(em);
		FilesHelper::updateEmployeesFile();
		cout << "\n\n\n";
		system("pause");
	}

	static void listAllEmployee(Admin* Admin) {
		new_page;
		cout << "-------------------------------------\n";
		cout << "         LIST ALL EMPLOYEES          \n";
		cout << "-------------------------------------\n";
		Admin->listEmployee();
		cout << "\n\n\n\n";
		system("pause");
	}

	static void searchForEmployee(Admin* Admin) {
		int id;
		new_page;
		cout << "-------------------------------------\n";
		cout << "         SEARCH FOR EMPLOYEE         \n";
		cout << "-------------------------------------\n";
		cout << "\n [~] Enter Employee's ID : ";
		cin >> id;
		Employee* e = Admin->searchEmployee(id);
		if (e != nullptr) {
			cout << "\n [*] Employee founded: \n";
			e->display();
			cout << "\n\n\n\n";
			system("pause");
		}
		else
			cout << "\n [!] Employee Not found..!";
	}

	static void editEmployee(Admin* Admin) {
		int id;
		string newName, newPass;
		double newSalary;
		new_page;
		cout << "-----------------------------\n";
		cout << "         EDIT EMPLOYEE       \n";
		cout << "-----------------------------\n";
		cout << "\n [~] Enter Employee's ID : ";
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

		Admin->editEmployee(id, newName, newPass, newSalary);
		FilesHelper::updateEmployeesFile();
		cout << "\n\n\n\n";
		system("pause");
	}

	static void adminInfo(Admin* Admin) {
		new_page;
		cout << "-----------------------------\n";
		cout << "           ADMIN INFO        \n";
		cout << "-----------------------------\n";
		Admin->display();
		cout << "\n\n\n\n";
		system("pause");
	}

public:

	static Admin* login(int id, string password) {
		for (int i = 0; i < AllAdmins.size(); i++) {
			if (AllAdmins[i].getId() == id && AllAdmins[i].getPassword() == password) {
				cout << "\n [*] Login successful! Welcome, " << AllAdmins[i].getName()<<endl;
				cout << "\n\n\n\n";
				system("pause");
				return &AllAdmins[i];
			}
		}
		return nullptr;
	}

	static bool AdminOptions(Admin* Admin) {

		printAdminMenu();

		int choice ;
		cin >> choice;

		switch (choice) {
		case 1:
			addNewEmployee(Admin);
			break;
		case 2:
			listAllEmployee(Admin);
			break;
		case 3:
			searchForEmployee(Admin);
			break;
		case 4:
			editEmployee(Admin);
			break;
		case 5:
			while(EmployeeManager::employeeOptions(Admin));
			break;
		case 6:
			adminInfo(Admin);
			break;
		case 7:
			new_page;
			cout << "\n\n\n [*] Thanks " << Admin->getName() << " for your time ,Goodbye (*^_^*)\n\n";
			return false;
			break;
		default:
			cout << "\n [!] Invalid Choice !!";
		}
		return true;
	}

};
