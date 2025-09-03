#include <iostream>
#include <cctype>
using namespace std;

class Person {
protected:
    int id;
    string password, name;

public:
    void setName(string n) {
        if (n.size() >= 3 && n.size() <= 20) {
            bool valid = true;
            for (char c : n) {
                if (!isalpha(c) && c != ' ') {
                    valid = false;
                    break;
                }
            }
            if (valid) name = n;
        }
    }
    string getName() { return name; }

    void setId(int i) { id = i; }
    int getId() { return id; }

    bool isValidPassword(string pass) {
        if (pass.size() < 8 || pass.size() > 20) return false;
        for (char c : pass) if (c == ' ') return false;
        return true;
    }

    void setPassword(string p) {
        if (isValidPassword(p)) password = p;
    }
    string getPassword() { return password; }
};

class Client : public Person {
private:
    double balance;

public:

    void setBalance(double b) {
        if (b >= 1500) balance = b;
    }
    double getBalance() { return balance; }

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && balance - amount >= 1500) balance -= amount;
    }

    void transfer(Client &recipient, double amount) {
        if (amount > 0 && balance - amount >= 1500) {
            balance -= amount;
            recipient.deposit(amount);
        }
    }
    void display() {
        cout << "Client Name: " << name << "\n";
        cout << "ID: " << id << "\n";
        cout << "Balance: " << balance << "\n";
    }
};

class Employee : public Person {
private:
    double salary;

public:
    void setSalary(double s) { salary = s; }
    double getSalary() { return salary; }

    void display() {
        cout << "Employee Name: " << name << "\n";
        cout << "ID: " << id << "\n";
        cout << "Salary: " << salary << "\n";
    }
};
class Admin : public Person {
    private:
    double salary;
    public:
    void setSalary(double s) { salary = s; }
    double getSalary() { return salary; }
    void minsalary(double s) { 
        if(s>=5000){ 
        salary=s; 
        }   
    }
    void display() {
        cout << "Admin Name: " << name << "\n";
        cout << "ID: " << id << "\n";
        cout << "Salary: " << salary << "\n";
    }
};
