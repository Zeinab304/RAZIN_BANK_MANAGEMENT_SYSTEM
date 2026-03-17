#pragma once
#include "Admin.h"
#include"AdminManager.h"
class BankManager:public Admin
{
	BankManager() {
		this->setName("AhmedAbdo");
		this->setId(99999);
		this->setPassword("Ahmed#Abdo_99");
		this->setSalary(50000);
	}

	static BankManager* manager;

public:

	static BankManager* getManager() {
		if (manager == nullptr)
			manager = new BankManager;
		return manager;
	}

	void addAdmin(Admin& e) {
		AllAdmins.push_back(e);
	}

	Admin* searchAdmin(int id) {
		for (int i = 0; i < AllAdmins.size(); i++) {
			if (AllAdmins[i].getId() == id)
				return &AllAdmins[i];
		}
		return nullptr;
	}

	void listAdmin() {
		for (int i = 0; i < AllAdmins.size(); i++) {
			AllAdmins[i].display();
			cout << "\n-------------------------------------\n";
		}
	}

	void editAdmin(int id, string name, string password, double salary) {
		for (int i = 0; i < AllAdmins.size(); i++) {
			if (AllAdmins[i].getId() == id) {
				AllAdmins[i].setName(name);
				AllAdmins[i].setPassword(password);
				AllAdmins[i].setSalary(salary);
				cout << "\n [*] Admin data updated successfully";
				return;
			}
		}
	}

	double calculateTotalSalaries() {

		double total = 0;

		for (int i = 0; i < AllAdmins.size(); i++) {
			total += AllAdmins[i].getSalary();
		}

		for (int j = 0; j < AllEmployees.size(); j++) {
			total += AllEmployees[j].getSalary();
		}
		total += this->getSalary();
		return total;
	}

};

