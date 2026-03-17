#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Client.h"
#include"FilesHelper.h"
#include<ctime>

#define new_page system("cls")
#define time_op  {time_t timestamp; time(&timestamp); cout<<"\n------------\n"<<ctime(&timestamp)<<"\n";}

class ClientManager
{
	static void printClientMenu() {
		new_page;
		cout << "------------------------------------\n";
		cout << "          Client Main Menu          \n";
		cout << "------------------------------------\n";
		cout << "\n [1] WithDraw"<<endl;
		cout << "\n [2] Deposit" << endl;
		cout << "\n [3] Transfer To" << endl;
		cout << "\n [4] Check Balance" << endl;
		cout << "\n [5] Display My Info" << endl;
		cout << "\n [6] Update Passward" << endl;
		cout << "\n [7] Logout" << endl;
		cout << "\n [?] Pleace enter a choice (1-6) : ";
	}

	static void updatePassword(Person* person) {
		string newpass;
		new_page;
		cout << "---------------------------------\n";
		cout << "          UPDATE PASSWARD        \n";
		cout << "---------------------------------\n";
		cout << " Enter New Password: ";
		cin >> newpass;
		Validation::checkPWD(newpass);

		person->setPassword(newpass);
		cout << "\n [^-^] Password Updated Successfully\n";
		cout << "\n\n\n\n";
		system("pause");

	}

	static void withdrawOperation(Client* client) {
		double amount;
		new_page;
		cout << "-------------------------------------\n";
		cout << "         WITHDRAW OPERATION          \n";
		cout << "-------------------------------------\n";
		cout << "\n [~] Please enter amount to withdraw: ";
		cin >> amount;
		client->withdraw(amount);
		FilesHelper::updateClientsFile();
		time_op;
		cout << "\n\n\n\n";
		system("pause");
	}

	static void depositOperation(Client* client) {
		double amount;
		new_page;
		cout << "-------------------------------------\n";
		cout << "         DEPOSIT OPERATION          \n";
		cout << "-------------------------------------\n";
		cout << "\n [~] Please enter amount to deposit: ";
		cin >> amount;
		client->deposit(amount);
		FilesHelper::updateClientsFile();
		time_op;
		cout << "\n\n\n\n";
		system("pause");
	}

	static void transferOperation(Client* client) {
		double amount;
		new_page;
		cout << "-------------------------------------\n";
		cout << "         TRANSFER OPERATION         \n";
		cout << "-------------------------------------\n";
		cout << "\n [~] Please enter recipient ID: ";
		int recipientId;
		cin >> recipientId;
		Client* recipient = nullptr;
		for (int i = 0; i < AllClients.size(); i++) {
			if (AllClients[i].getId() == recipientId) {
				recipient = &AllClients[i];
				break;
			}
		}
		if (recipient) {
			cout << " [~] Please enter amount to transfer: ";
			cin >> amount;
			client->transferTo(amount, *recipient);
			FilesHelper::updateClientsFile();
			time_op;
		}
		else
			cout << "\n [!] Recipient not found!";
		cout << "\n\n\n\n";
		system("pause");
	}

	static void checkBalance(Client* client) {
		new_page;
		cout << "---------------------------------\n";
		cout << "         CHECK BALANCE           \n";
		cout << "---------------------------------\n";
		cout << "\n [~] Your Current Balance:$ " << client->getBalance();
		cout << "\n\n\n\n";
		system("pause");
	}

	static void clientInfo(Client* client) {
		new_page;
		cout << "-----------------------------\n";
		cout << "         CLIENT INFO         \n";
		cout << "-----------------------------\n";
		client->display();
		cout << "\n\n\n\n";
		system("pause");
	}

public:

	static Client* login(int id, string password) {
		for (int i = 0; i < AllClients.size(); i++) {
			if (AllClients[i].getId() == id && AllClients[i].getPassword() == password) {
				cout << "\n [*] Login successful! Welcome, " << AllClients[i].getName();
				cout << "\n\n\n\n";
				system("pause");
				return &AllClients[i];
			}
		}
		return nullptr;
	}

	static bool clientOptions(Client* client) {
		printClientMenu();

		int choice;

		cin >> choice;
		switch(choice){
		case 1:
			withdrawOperation(client);
			break;
		case 2:
			depositOperation(client);
			break;
		case 3:
		
			transferOperation(client);
			break;
		case 4:
			checkBalance(client);
			break;
		case 5:
			clientInfo(client);
			break;
		case 6:
			updatePassword(client);
			FilesHelper::updateClientsFile();
			break;
		case 7:
			new_page;
			cout << "\n [*] Thanks " << client->getName() << " for your time ,Goodbye (*^_^*)\n\n\n";
			return false;
			break;
		default:
			cout << "\n [!] Invalid Choice !!";
		}
		return true;
	}

};

