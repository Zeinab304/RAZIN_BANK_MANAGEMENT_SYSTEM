#pragma once
#include<fstream>
#include"parser.h"

class FilesHelper {
public:
	static void saveLast(string fileName, int id) {
		ofstream file(fileName, ios::trunc);
		if (file.is_open()) {
			file << id;
			file.close();
		}
	}

	static int getLast(string fileName) {
		ifstream file(fileName);
		int s = 1000;
		if (file.is_open()) {
			file >> s;
			file.close();
		}
		return s;
	}

	static void saveClient(Client c) {
		ofstream file("Clients.txt", ios::app);
		if(file.is_open()){
			file << c.getId() << "|" << c.getName() << "|" << Validation::encrypt(c.getPassword()) << "|" << c.getBalance() << "|" << c.getStatus() << "\n";
			file.close();
		}
		saveLast("lastIdClient.txt", c.getId());
	}

	static void saveEmployee(string fileName, string lastIdFile, Employee e) {
		ofstream file(fileName, ios::app);
		if (file.is_open()) {
			file << e.getId() << "|" << e.getName() << "|" << Validation::encrypt(e.getPassword()) << "|" << e.getSalary()<<"\n";
			file.close();
		}
		saveLast(lastIdFile, e.getId());
	}

	static void saveAdmin(Admin a) {
		ofstream file("Admin.txt", ios::app);
		if (file.is_open()) {
			file << a.getId() << "|" << a.getName() << "|" << Validation::encrypt(a.getPassword()) << "|" << a.getSalary() << "\n";
			file.close();
		}
		saveLast("lastIdAdmin.txt", a.getId());
	}

	static void getClients() {
		ifstream file("Clients.txt");
		string line;
		if (file.is_open()) {
			while (getline(file, line)) {
				AllClients.push_back(Parser::parseToClient(line));
			}
			file.close();
		}
	}

	static void getEmployees() {
		ifstream file("Employee.txt");
		string line;
		if (file.is_open()) {
			while (getline(file, line)) {
				AllEmployees.push_back(Parser::parseToEmployee(line));
			}
			file.close();
		}
	}

	static void getAdmins() {
		ifstream file("Admin.txt");
		string line;
		if (file.is_open()) {
			while (getline(file, line)) {
				AllAdmins.push_back(Parser::parseToAdmin(line));
			}
			file.close();
		}
	}

	static void clearFile(string fileName, string lastIdFile) {
		ofstream file(fileName, ios::trunc);
		file.close();
		ofstream myFile(lastIdFile, ios::trunc);
		myFile.close();
	}

	static void updateClientsFile() {
		ofstream file;
		file.open("Clients.txt", ios::trunc);
		file.close();
		for (int i = 0; i < AllClients.size(); i++)
			saveClient(AllClients[i]);
	}

	static void updateEmployeesFile() {
		ofstream file;
		file.open("Employee.txt", ios::trunc);
		file.close();
		for (int i = 0; i < AllEmployees.size(); i++)
			saveEmployee("Employee.txt", "lastIdEmployee.txt", AllEmployees[i]);
	}

	static void updateAdminsFile() {
		ofstream file;
		file.open("Admin.txt", ios::trunc);
		file.close();
		for (int i = 0; i < AllAdmins.size(); i++)
			saveAdmin(AllAdmins[i]);
	}

};
