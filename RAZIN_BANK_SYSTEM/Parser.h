#pragma once
#include <vector>
#include <sstream>
#include"Admin.h"
using namespace std;

class Parser 
{
public:
	static vector<string> split(string line) {
		vector<string> splitLine;
		stringstream ss(line);
		string parts;
		while (getline(ss, parts, '|')) {
			splitLine.push_back(parts);
		}
		return splitLine;
	}
	static Client parseToClient(string line) {
		vector<string> data = split(line);
		Client c;
		c.setId(stoi(data[0]));
		c.setName(data[1]);
		c.setPassword(Validation::decrypt(data[2]));
		c.setBalance(stod(data[3]));
		c.setStatus(stoi(data[4]));
		return c;
	}
	static Employee parseToEmployee(string line) {
		vector<string> data = split(line);
		Employee c;
		c.setId(stoi(data[0]));
		c.setName(data[1]);
		c.setPassword(Validation::decrypt(data[2]));
		c.setSalary(stod(data[3]));
		return c;
	}
	static Admin parseToAdmin(string line) {
		vector<string> data = split(line);
		Admin c;
		c.setId(stoi(data[0]));
		c.setName(data[1]);
		c.setPassword(Validation::decrypt(data[2]));
		c.setSalary(stod(data[3]));
		return c;
	}
};

