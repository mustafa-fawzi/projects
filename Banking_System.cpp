#include<iostream>
using namespace std;
class Person {
protected:
	string name;
	int id;
	string password;
public:
	Person(string name, int id, string password) {
		bool check = 1;
		if (name.size() > 3 && name.size() < 20) {
			for (int i = 0;i < name.size();i++) {
				if (!(name[i] >= 'A' && name[i] <= 'z')) {
					check = 0;
					break;
				}
			}

		}
		else {
			check = 0;
		}
		if (check) {
			this->name = name;
		}
		this->id = id;
		if (password.size() > 8 && password.size() < 20) {
			this->password = password;
		}
	}
	Person() {

	}
	void setName(string name) {
		bool check = 1;
		if (name.size() > 3 && name.size() < 20) {
			for (int i = 0;i < name.size();i++) {
				if (!(name[i] >= 'A' && name[i] <= 'z')) {
					check = 0;
					break;
				}
			}

		}
		else {
			check = 0;
		}
		if (check) {
			this->name = name;
		}
	}
	void setId(int id) {
		this->id = id;
	}
	void setPassword(string password) {
		if (password.size() > 8 && password.size() < 20) {
			bool check = 1;
			for (auto c : password) {
				if (c == ' ') {
					check = 0;
				}
			}
			if (check) {
				this->password = password;
			}
		}
	}
	string getName() {
		return name;
	}
	int getId() {
		return id;
	}
	string getPassword() {
		return password;
	}

	//virtual void display_info() = 0;
};
class Client :public Person {
	double balance;
	static int countClient;
	int numberOfClient;
public:
	Client(string name, int id, string password, double balance)
		:Person(name, id, password) {
		if (balance >= 1500) {
			this->balance = balance;
		}
		countClient++;
		numberOfClient==countClient;

	}
	Client() {
		numberOfClient=++countClient;
	}
	void setCount() {
		cout << "Number of Client is " << countClient << '\n';
	}
	void setBalance(double balance) {
		if (balance >= 1500) {
			this->balance = balance;
		}
	}
	double getBalance() {
		return balance;
	}
	void deposit(double amount) {
		balance += amount;
	}
	void withdraw(double amount) {
		if (balance - amount >= 1500) {
			balance -= amount;
		}
	}
	void transfer(double amount, Client& recipient) {
		if (balance - amount >= 1500) {
			balance -= amount;
			recipient.withdraw(amount);
		}
	}
	void checkBalance() {
		cout << "Your balance is " << balance << '\n';
	}
	void dispaly() {
		cout << "Client is " << name << '\n';
		cout << "ID is " << id << '\n';
		cout << "Balance is " << balance << '\n';
	}

};
class Employee :public Person {
	static int countEmployee;
	int salary;
	int numberOfEmployee;
public:
	Employee(string name, int id, int salary, string password)
		:Person(name, id, password), salary(salary) {
		
		if (salary >= 5000) {
			this->salary = salary;
		}
		countEmployee++;
		numberOfEmployee= countEmployee;
	}
	Employee():Person() {
		countEmployee++;
		numberOfEmployee = countEmployee;
	}
	void setSalary(int salary) {
		if (salary >= 5000) {
			this->salary = salary;
		}
	}
	int getSalary() {
		return salary;
	}
	void display_info() {
		cout << "Employee is " << name << '\n';
		cout << "ID is " << id << '\n';
		cout << "Salary is " << salary << '\n';
	}


	static void setCount() {
		cout << "Number of employees is " << countEmployee << '\n';
	}
};
class Admin :public Person {
	int salary;
	static int countAdmin;
	int numberOfAdmin;
public:
	Admin(string name, int id, int salary, string password) :
		Person(name, id, password) {
		if (salary >= 5000) {
			this->salary == salary;
		}
		numberOfAdmin=++countAdmin;
	}
	Admin() :Person() {
		numberOfAdmin=countAdmin;
	}
	int getSalary() {
		return salary;
	}
	static void setCount() {
		cout<<"Nubmer of Admin is "<< countAdmin<<'\n';
	}
};
int Client::countClient = 0;
int Employee::countEmployee = 0;
int Admin::countAdmin = 0;
int main() {
	

}
