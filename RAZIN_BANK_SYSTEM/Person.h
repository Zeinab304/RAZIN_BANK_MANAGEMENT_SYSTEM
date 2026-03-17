#pragma once
#include"Validation.h"

class Person
{
protected:
	string name, password;
	int id;
public:
	static int idCounter;

	Person() {
		id = idCounter;
	}

	Person(int id, string name, string password) {
		this->id = id;
		setName(name);
		setPassword(password);
	}

	Person(int id, string password) {
		this->id = id;
		this->password = password;
	}

	void setId(int id) {
		this->id = id;
	}

	void setName(string name) {
		this->name = name;
	}

	void setPassword(string password) {
		this->password = password;
	}

	int getId() {
		return this->id;
	}

	string getName() {
		return this->name;
	}

	string getPassword() {
		return password;
	}

	virtual void display() {
		cout << "\tID: " << this->id;
		cout << "\n\tName: " << this->name;
		cout << "\n\tPassword: " << this->password;
	}

};

