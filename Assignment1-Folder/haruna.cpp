#include <iostream>
#include <string>

class Employee {
public:
    Employee(const std::string & name, int employeeID) : name(name), employeeID(employeeID) {}

    // display employee details
    virtual void getInfo() const {
        std::cout << "Employee Details\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Employee ID: " << employeeID << "\n";
    }

private:
    std::string name;
    int employeeID;
};

class FullTimeEmployee : public virtual Employee {
public:
    FullTimeEmployee(const std::string & name, int employeeID, double salary)
        : Employee(name, employeeID), salary(salary) {}

    // Override getInfo to display full-time employee details
    void getInfo() const override {
        Employee::getInfo();  // to Call base class getInfo()
        std::cout << "Salary: $" << salary << "\n";
    }

private:
    double salary;
};

class PartTimeEmployee : public virtual Employee {
public:
    PartTimeEmployee(const std::string& name, int employeeID, double hourlyWage, double hoursWorked)
        : Employee(name, employeeID), hourlyWage(hourlyWage), hoursWorked(hoursWorked) {}

    // Override getInfo to display part-time employee details
    void getInfo() const override {
        Employee::getInfo();  // to Call base class getInfo()
        std::cout << "Hourly Wage: $" << hourlyWage << "\n";
        std::cout << "Hours Worked: " << hoursWorked << "\n";
    }

private:
    double hourlyWage;
    double hoursWorked;
};

int main() {
    // Create objects of FullTimeEmployee and PartTimeEmployee
    FullTimeEmployee fullTimeEmployee("HARUNA SANI HARUNA", 211203073, 100000.0);
    PartTimeEmployee partTimeEmployee("ABBA MUHAMMAD SANI", 211203000, 50.0, 24.0);

    // Display details of both types of employees using the getInfo() method
    std::cout << "Full-Time Employee Details:\n";
    fullTimeEmployee.getInfo();
    std::cout << "\n";

    std::cout << "Part-Time Employee Details:\n";
    partTimeEmployee.getInfo();

    return 0;
}