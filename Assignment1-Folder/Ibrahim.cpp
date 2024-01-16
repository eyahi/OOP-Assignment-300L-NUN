#include <iostream>
#include <string>

class Employee {
public:
    Employee(const std::string& name, int employeeId) : name(name), employeeId(employeeId) {}

    void getInfo() {
        std::cout << "Employee ID: " << employeeId << std::endl;
        std::cout << "Name: " << name << std::endl;
    }

private:
    std::string name;
    int employeeId;
};

class FullTimeEmployee : virtual public Employee {
public:
    FullTimeEmployee(const std::string& name, int employeeId, double salary) : Employee(name, employeeId), salary(salary) {}

    void getInfo() {
        Employee::getInfo();
        std::cout << "Salary: $" << salary << std::endl;
    }

private:
    double salary;
};

class PartTimeEmployee : virtual public Employee {
public:
    PartTimeEmployee(const std::string& name, int employeeId, double hourlyWage, int hoursWorked) : Employee(name, employeeId), hourlyWage(hourlyWage), hoursWorked(hoursWorked) {}

    void getInfo() {
        Employee::getInfo();
        std::cout << "Hourly Wage: $" << hourlyWage << std::endl;
        std::cout << "Hours Worked: " << hoursWorked << " hours" << std::endl;
    }

private:
    double hourlyWage;
    int hoursWorked;
};

int main() {
    FullTimeEmployee fullTime("Ibrahim Muhammad Mustapha", 101, 200000.0);
    PartTimeEmployee partTime("Muhammad Kalli Kolo", 202, 100.0, 70);

    std::cout << "Full-Time Employee Details:" << std::endl;
    fullTime.getInfo();
    std::cout << "\nPart-Time Employee Details:" << std::endl;
    partTime.getInfo();

    return 0;
}