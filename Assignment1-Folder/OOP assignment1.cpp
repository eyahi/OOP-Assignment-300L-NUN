#include <iostream>
#include <string>

// Base class Employee
class Employee {
public:
    std::string Name;
    std::string EmployeeID;

    // Constructor
    Employee(const std::string& name, const std::string& id) : Name(name), EmployeeID(id) {}

    // Virtual function to get employee details
    virtual void getInfo() const {
        std::cout << "Name: " << Name << "\nEmployee ID: " << EmployeeID << std::endl;
    }
};

// Derived class FullTimeEmployee
class FullTimeEmployee : virtual public Employee {
public:
    double Salary;

    // Constructor
    FullTimeEmployee(const std::string& name, const std::string& id, double salary)
        : Employee(name, id), Salary(salary) {}

    // Override getInfo() for full-time employees
    void getInfo() const override {
        Employee::getInfo();
        std::cout << "Salary: $" << Salary << std::endl;
    }
};

// Derived class PartTimeEmployee
class PartTimeEmployee : virtual public Employee {
public:
    double HourlyWage;
    double HoursWorked;

    // Constructor
    PartTimeEmployee(const std::string& name, const std::string& id, double hourlyWage, double hoursWorked)
        : Employee(name, id), HourlyWage(hourlyWage), HoursWorked(hoursWorked) {}

    // Override getInfo() for part-time employees
    void getInfo() const override {
        Employee::getInfo();
        std::cout << "Hourly Wage: $" << HourlyWage << "\nHours Worked: " << HoursWorked << std::endl;
    }
};

int main() {
    // Create objects of FullTimeEmployee and PartTimeEmployee
    FullTimeEmployee fullTimeEmp("Asmau Abubakar", "211203060", 600000.0);
    PartTimeEmployee partTimeEmp("Asmau Abubakar", "211203060", 100.0, 70.0);

    // Display details using the getInfo() method
    std::cout << "Full-Time Employee Details:\n";
    fullTimeEmp.getInfo();
    std::cout << "\nPart-Time Employee Details:\n";
    partTimeEmp.getInfo();

    return 0;
}
