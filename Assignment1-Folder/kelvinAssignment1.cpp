#include <iostream>
#include <string>
using namespace std;

// Base class
class Employee {
public:
    string name;
    int employeeID;

    Employee(string name, int employeeID) : name(name), employeeID(employeeID) {}

    virtual void getInfo() {
        cout << "Name: " << name << ", Employee ID: " << employeeID << endl;
    }
};

// Derived class for Full-Time Employee
class FullTimeEmployee : virtual public Employee {
public:
    double salary;

    FullTimeEmployee(string name, int employeeID, double salary)
        : Employee(name, employeeID), salary(salary) {}

    void getInfo() override {
        Employee::getInfo();
        cout << "Salary: $" << salary << endl;
    }
};

// Derived class for Part-Time Employee
class PartTimeEmployee : virtual public Employee {
public:
    double hourlyWage;
    int hoursWorked;

    PartTimeEmployee(string name, int employeeID, double hourlyWage, int hoursWorked)
        : Employee(name, employeeID), hourlyWage(hourlyWage), hoursWorked(hoursWorked) {}

    void getInfo() override {
        Employee::getInfo();
        cout << "Hourly Wage: $" << hourlyWage << ", Hours Worked: " << hoursWorked << endl;
    }
};

// Main function
int main() {
    FullTimeEmployee ftEmployee("kelvin Joseph Effiong", 211203017, 4000);
    PartTimeEmployee ptEmployee("Ken Effiong", 2345, 20, 25);

    cout << "Full-Time Employee Details:" << endl;
    ftEmployee.getInfo();

    cout << "\nPart-Time Employee Details:" << endl;
    ptEmployee.getInfo();

    return 0;
}