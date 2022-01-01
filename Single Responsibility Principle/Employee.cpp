#include<bits/stdc++.h>
using namespace std;
class Employee {
private:
    int id;
    string name;
    int salary;
    int yearOfExperience;
public:
    Employee(int id, string name, int salary, int yearOfExperience) {
        this->id = id;
        this->name = name;
        this->salary = salary;
        this->yearOfExperience = yearOfExperience;
    }
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return this->name;
    }
    void setSalary(int salary) {
        this->salary = salary;
    }
    int getSalary() {
        return this->salary;
    }
    void setYearOfExperience(int yearOfExperience) {
        this->yearOfExperience = yearOfExperience;
    }
    int getYearOfExperience() {
        return this->yearOfExperience;
    }
    // This is voilating the single responsibility principle.
    int findNewSalary() {
        this->salary = this->salary + this->salary * this->yearOfExperience;
        return getSalary();
    }
};

int main() {
    Employee employee(1, "shubham", 10000, 1);
    int nextSalary = employee.findNewSalary();
    cout << nextSalary;
}
