//Name: Abdulfattah Abdulsalam
//ID: 211103010
//Dept: Computer Engineering
//Level: 300 level
#include <iostream>
#include <cmath>
#include <list>
using namespace std;

class Employee {
protected:
    string Name;
    int Employee_ID;

public:
    Employee(const string& name, int employee_ID) : Name(name), Employee_ID(employee_ID) {
        // Name set to name, Employee_ID set to employee_ID
    }

    virtual void get_Info() {
        cout << "Name: " << Name << " Employee_ID: " << Employee_ID << endl;
    }
};
//sub class "Full_Time_Employee"
class Full_Time_Employee : public virtual Employee {
private:
    double Salary;

public:
    Full_Time_Employee(const string& name, int employee_ID, double salary) : Employee(name, employee_ID), Salary(salary) {
        // Parameterized constructor of Full_Time_Employee
    }

    void get_Info() override {
        cout << "Name: " << Name << " Employee_ID: " << Employee_ID << " Salary: $ " << Salary << endl;
    }
};
//sub class "Part_Time_Employee"
class Part_Time_Employee : public virtual Employee {
private:
    double Hourly_Wage;
    double Hours_Worked;

public:
    Part_Time_Employee(const string& name, int employee_ID, double hourly_wage, double hours_worked) : Employee(name, employee_ID), Hourly_Wage(hourly_wage), Hours_Worked(hours_worked) {
        // Parameterized constructor of Part_Time_Employee
    }

    void get_Info() override {
        cout << "Name: " << Name << " Employee_ID: " << Employee_ID << " Hourly_Wage: " << Hourly_Wage << " $/hr " << " Hours_Worked: " << Hours_Worked << " hours" << endl;
    }
};

int main() {
    Full_Time_Employee employee_1("Abdulfattah Abdulsalam, ", 211203010, 1000000.00);
    Part_Time_Employee employee_2("Abdulsalam Abdulfattah, ", 211203010, 550000.00, 27.35);

    employee_1.get_Info();
    employee_2.get_Info();

    return 0;
}
