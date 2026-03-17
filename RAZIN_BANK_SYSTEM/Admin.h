#pragma once
#include"Employee.h"
class Admin:public Employee
{
public:

	Admin() {
	}
	Admin(int id, string password) :Employee(id, password) {
	}
	Admin(int id, string name, string password, double salary) :Employee(id, name, password, salary) {
	}
	void display() {
		Employee::display();
	}

	void addEmployee(Employee& e) {
		AllEmployees.push_back(e);
	}

	Employee* searchEmployee(int id) {
		for (int i = 0; i < AllEmployees.size(); i++) {
			if (AllEmployees[i].getId() == id)
				return &AllEmployees[i];
		}
		return nullptr;
	}
		
	void listEmployee() {
		for (int i = 0; i < AllEmployees.size(); i++) {
			AllEmployees[i].display();
			cout << "\n-------------------------------------\n";
		}
	}

	void editEmployee(int id, string name, string password, double salary) {
		for (int i = 0; i <AllEmployees.size(); i++) {
			if (AllEmployees[i].getId() == id) {
				AllEmployees[i].setName(name);
				AllEmployees[i].setPassword(password);
				AllEmployees[i].setSalary(salary);
				cout << "\n [*] Employee data updated successfully";
				return;
			}
		}
		/*cout << "[!] Employee with ID " << id << " not found.";
		FilesHelper::updateEmployeesFile();*/
	}

};

static vector<Admin> AllAdmins;