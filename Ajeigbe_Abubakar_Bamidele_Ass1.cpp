#include <iostream>
#include <string>

// Base class Employee
class Employee
{
protected:
    std::string name;
    int employeeID;

public:
    // Constructor
    Employee(const std::string &_name, int _employeeID) : name(_name), employeeID(_employeeID) {}

    // Virtual destructor to enable polymorphism
    virtual ~Employee() {}

    // Virtual function to get employee information
    virtual void getInfo() const
    {
        std::cout << "Name: " << name << "\nEmployee ID: " << employeeID << std::endl;
    }
};

// Derived class FullTimeEmployee
class FullTimeEmployee : virtual public Employee
{
protected:
    double salary;

public:
    // Constructor
    FullTimeEmployee(const std::string &_name, int _employeeID, double _salary)
        : Employee(_name, _employeeID), salary(_salary) {}

    // getInfo for the full-time employees
    void getInfo() const override
    {
        Employee::getInfo();
        std::cout << "Salary: $" << salary << std::endl;
    }
};

// PartTimeEmployee
class PartTimeEmployee : virtual public Employee
{
protected:
    double hourlyWage;
    double hoursWorked;

public:
    // Constructor
    PartTimeEmployee(const std::string &_name, int _employeeID, double _hourlyWage, double _hoursWorked)
        : Employee(_name, _employeeID), hourlyWage(_hourlyWage), hoursWorked(_hoursWorked) {}

    // Override getInfo for part-time employees
    void getInfo() const override
    {
        Employee::getInfo();
        std::cout << "Hourly Wage: $" << hourlyWage << "\nHours Worked: " << hoursWorked << " hours" << std::endl;
    }
};

int main()
{
    // Create objects of FullTimeEmployee and PartTimeEmployee
    FullTimeEmployee fullTimeEmp("Ajeigbe Abubakar Bamidele", 001, 50000.0);
    PartTimeEmployee partTimeEmp("Cristiano Ronaldo", 002, 20.0, 25.0);

    // Display employee details using the getInfo() method
    std::cout << "Full-Time Employee Details:\n";
    fullTimeEmp.getInfo();
    std::cout << "\nPart-Time Employee Details:\n";
    partTimeEmp.getInfo();

    return 0;
}
