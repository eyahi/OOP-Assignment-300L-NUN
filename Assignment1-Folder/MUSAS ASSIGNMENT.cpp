//Name: Abdullahi Musa
//ID: 211103011
//Dept: Computer Engineering
//Level: 300 level
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string Name;
    int EmployeeID;
public:
    Employee(const string& name, int employeeID) : Name(name), EmployeeID(employeeID) {};
    virtual void get_Info() const {
        cout << "Name: " << Name << " Employee ID: " << EmployeeID << endl;
    }
    virtual ~Employee() {}
};

class FullTimeEmployee : public virtual Employee {
private:
    double Salary;
public:
    FullTimeEmployee(const string& name, int employeeID, double salary) : Employee(name, employeeID), Salary(salary) {};
    void get_Info() const override {
        Employee::get_Info();
        cout << "Salary: $ " << Salary << endl;
    }
};

class PartTimeEmployee : public virtual Employee {
private:
    double HourlyWage;
    double HoursWorked;
public:
    PartTimeEmployee(const string& name, int employeeID, double hourlywage, double hoursworked) : Employee(name, employeeID), HourlyWage(hourlywage), HoursWorked(hoursworked) {};
    void get_Info() const override {
        Employee::get_Info();
        cout << "Hourly Wage: " << HourlyWage << " $/hr Hours Worked: " << HoursWorked << " hr" << endl;
    }
};

int main() {
    FullTimeEmployee employee_1("Abdullahi Musa", 211203011, 12000);
    PartTimeEmployee employee_2("Abdullahi Musa", 211203011, 37000, 6.30);
    employee_1.get_Info();
    employee_2.get_Info();
}