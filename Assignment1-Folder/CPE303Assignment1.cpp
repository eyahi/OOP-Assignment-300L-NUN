//Name: Ikeamaka Collins Chidubem
//ID: 211103054
//Dept: Computer Engineering
//Level: 300 level

#include <iostream>
#include <string>
using namespace std;

//employee base class
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

//full time employee derived class
class FullTimeEmployee : public virtual Employee {
private:
    int Salary;
public:
    FullTimeEmployee(const string& name, int employeeID, int salary) : Employee(name, employeeID), Salary(salary) {};
    void getInfo() override {
        cout << "\nName: " << Name << "\nEmployee ID: " << EmployeeID << "\nSalary: " << Salary << "$" << endl;
    }
};

//part time employee derived class
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

//main function
int main() {
    //creating employee1 object as a full time employee
    FullTimeEmployee employee1("Ikeamaka Collins Chidubem", 211103054, 50000);

    //creating employee2 object as a part time employee
    PartTimeEmployee employee2("Ikeamaka Collins Chidubem", 211103054, 100, 500);

    //getting employee1 info
    employee1.getInfo();

    //getting employee2 info
    employee2.getInfo(); 
}