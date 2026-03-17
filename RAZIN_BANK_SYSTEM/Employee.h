#pragma once
#include"Person.h"
#include"Client.h"
class Employee:public Person
{
protected:
	double salary;
public:

	Employee() {
		this->salary = 0.0;
	}

	Employee(int id, string name, string password, double salary) :Person(id, name, password) {
		setSalary(salary);
	}

	Employee(int id, string password) :Person(id, password) {
		this->salary = 0.0;
	}

	void setSalary(double salary) {
		this->salary = salary;
	}

	double getSalary() {
		return this->salary;
	}

	void editStatus(Client& c, bool newstate) {
		c.setStatus(newstate);
		cout << "\n [^-^] Client status updated successfully to " << (newstate ? "Active" : "Frozen") << endl;
	}

	void display() {
		Person::display();
		cout << "\n\tSalary: $" << this->salary << endl;
	}

	void addClient(Client& c) {
		AllClients.push_back(c);
	}

	Client* searchClient(int id) {
		for (int i = 0; i < AllClients.size(); i++) {
			if (AllClients[i].getId() == id)
				return &AllClients[i];
		}
		return nullptr;
	}

	void listClient() {
		for (int i = 0; i < AllClients.size(); i++) {
			AllClients[i].display();
			cout << "\n-----------------------------------\n";
		}
	}

	void editClient(int id, string name, string password, double balance) {
		for (int i = 0; i < AllClients.size(); i++) {
			if (AllClients[i].getId() == id) {
				AllClients[i].setName(name);
				AllClients[i].setPassword(password);
				AllClients[i].setBalance(balance);
				cout << "\n [*] Client data updated successfully";
				return;
			}
		}
		cout << "\n [!] Client with ID " << id << " not found.";
	}
};

static vector<Employee> AllEmployees;