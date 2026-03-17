# Bank Management System (C++ OOP)

A comprehensive Financial Management System developed in **C++** using **Object-Oriented Programming (OOP)** principles. The system manages multiple user roles (Clients, Employees, and Admins) with full data persistence through file handling. It features a secure login system, transaction management, and a hierarchical administrative structure.

## 🚀 Key Features:

* **Role-Based Access Control:** Distinct functionalities for Clients, Employees, and Admins.
* **Data Persistence:** Uses custom file handling to save and retrieve data (Clients, Employees, Admins, and IDs).
* **OOP Principles:** Implementation of Inheritance, Encapsulation, Polymorphism, and Abstraction.
* **Financial Operations:** Secure deposit, withdrawal, and transfer operations between clients.
* **Security:** Password validation and basic encryption/decryption mechanisms.
* **Manager Layer:** Specialized manager classes (ClientManager, EmployeeManager, AdminManager) to handle console UI and logic separation.
* **Singleton Pattern:** Implemented in `BankManager` to ensure a single central authority for the system.

## 🛠 Technical Skills:

* **Language:** C++
* **Concepts:** OOP, STL (Vectors), File I/O, Static Members.
* **Tools:** Visual Studio, Git.

## 📁 Project Structure:
* `Person.h / Person.cpp`: The base class for all users.
* `Client.h / Employee.h / Admin.h`: Derived classes with specific roles.
* `BankManager.h`: The central authority of the system.
* `Screens.h`: Handles the console UI and application flow.
