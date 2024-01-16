See her code:#include <iostream>
#include <string>


// Base class Employee
class Employee {
public:
    Employee(const std::string& name, int employeeID)
        : name(name), employeeID(employeeID) {}

    // Virtual function to display employee details
    virtual void getInfo() const {
        std::cout << "Employee ID: " << employeeID << "\n";
        std::cout << "Name: " << name << "\n";
    }

private:
    std::string name;
    int employeeID;
};

// Derived class FullTimeEmployee
class FullTimeEmployee : public virtual Employee {
public:
    FullTimeEmployee(const std::string& name, int employeeID, double salary)
        : Employee(name, employeeID), salary(salary) {}

    // Override getInfo to display full-time employee details
    void getInfo() const override {
        Employee::getInfo();
        std::cout << "Type: Full-Time Employee\n";
        std::cout << "Salary: $" << salary << "\n";
    }

private:
    double salary;
};

// Derived class PartTimeEmployee
class PartTimeEmployee : public virtual Employee {
public:
    PartTimeEmployee(const std::string& name, int employeeID, double hourlyWage, double hoursWorked)
        : Employee(name, employeeID), hourlyWage(hourlyWage), hoursWorked(hoursWorked) {}

    // Override getInfo to display part-time employee details
    void getInfo() const override {
        Employee::getInfo();
        std::cout << "Type: Part-Time Employee\n";
        std::cout << "Hourly Wage: $" << hourlyWage << "\n";
        std::cout << "Hours Worked: " << hoursWorked << " hours\n";
    }

private:
    double hourlyWage;
    double hoursWorked;
};

int main() {
    // Create objects of FullTimeEmployee and PartTimeEmployee
    FullTimeEmployee fullTimeEmployee("Sedooter Yanmar-Ortese", 211203032, 5000.6);
    PartTimeEmployee partTimeEmployee("Sedooter Yanmar-Ortese", 211203032, 45.3, 47.9);

    // Display the details of both types of employees using the getInfo() method
    std::cout << "Full-Time Employee Details:\n";
    fullTimeEmployee.getInfo();
    std::cout << "\n";

    std::cout << "Part-Time Employee Details:\n";
    partTimeEmployee.getInfo();

    return 0;
}