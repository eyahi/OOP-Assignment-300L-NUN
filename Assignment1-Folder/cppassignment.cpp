#include <string>
#include <iostream>
using namespace std;

class Employee {
protected:
    string Name;
    int EmployeeID;
public:
    Employee(const string& name, int employeeID) : Name(name), EmployeeID(employeeID) {};
    virtual void getInfo() {
        cout << "\nName: " << Name << "\nEmployee ID: " << EmployeeID << endl;
    }
};

class FullTimeEmployee : public virtual Employee {
private:
    int Salary;
public:
    FullTimeEmployee(const string& name, int employeeID, int salary) : Employee(name, employeeID), Salary(salary) {};
    void getInfo() override {
        cout << "\nName: " << Name << "\nEmployee ID: " << EmployeeID << "\nSalary: " << Salary << "$" << endl;
    }
};

class PartTimeEmployee : public virtual Employee {
private:
    int HourlyWage;
    int HoursWorked;
public:
    PartTimeEmployee(const string& name, int employeeID, int hourlyWage, int hoursWorked) : Employee(name, employeeID), HourlyWage(hourlyWage), HoursWorked(hoursWorked) {};
    void getInfo() override {
        cout << "\nName: " << Name << "\nEmployee ID: " << EmployeeID << "\nHourly Wage: " << HourlyWage << "$/hr" << "\nHours Worked: " << HoursWorked << "hrs" << endl;
    }
};

int main() {
    FullTimeEmployee employee1("Okafor Nzube", 211203028, 4000);

    PartTimeEmployee employee2("Okafor Nzube", 211203028, 10, 400);

    employee1.getInfo();

    employee2.getInfo(); 
}