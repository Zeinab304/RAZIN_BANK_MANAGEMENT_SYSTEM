#pragma once
#include<sstream>
#include"DataSourceInterface.h"
#include"FilesHelper.h"

class FileManager : public DataSourceInterface
{
public:
	static void addClient(Client c) {
		FilesHelper::saveClient(c);
	}
	static void addEmployee(Employee e) {
		FilesHelper::saveEmployee("Employee.txt", "lastIdEmployee.txt", e);
	}
	static void addAdmin(Admin a) {
		FilesHelper::saveAdmin(a);
	}

	static void getAllClients() {
		FilesHelper::getClients();
	}
	static void getAllEmployees() {
		FilesHelper::getEmployees();
	}
	static void getAllAdmins() {
		FilesHelper::getAdmins();
	}

	static void removeAllClients() {
		FilesHelper::clearFile("Clients.txt", "lastIdClient.txt");
	}
	static void removeAllEmployees() {
		FilesHelper::clearFile("Employee.txt", "lastIdEmployee.txt");
	}
	static void removeAllAdmins() {
		FilesHelper::clearFile("Admin.txt", "lastIdAdmin.txt");
	}

};
