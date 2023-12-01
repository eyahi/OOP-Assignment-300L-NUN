#include <iostream>
#include <string>

class Employee {
protected:
    std::string Name;
    int EmployeeID;

public:
    Employee(const std::string& name, int employeeID) : Name(name), EmployeeID(employeeID) {}

    virtual void getInfo() {
        std::cout << "Employee Name: " << Name << std::endl;
        std::cout << "Employee ID: " << EmployeeID << std::endl;
    }
};

class FullTimeEmployee : virtual public Employee {
protected:
    double Salary;

public:
    FullTimeEmployee(const std::string& name, int employeeID, double salary)
        : Employee(name, employeeID), Salary(salary) {}

    void getInfo() override {
        Employee::getInfo();
        std::cout << "Employee Type: Full-Time" << std::endl;
        std::cout << "Salary: $" << Salary << std::endl;
    }
};

class PartTimeEmployee : virtual public Employee {
protected:
    double HourlyWage;
    int HoursWorked;

public:
    PartTimeEmployee(const std::string& name, int employeeID, double hourlyWage, int hoursWorked)
        : Employee(name, employeeID), HourlyWage(hourlyWage), HoursWorked(hoursWorked) {}

    void getInfo() override {
        Employee::getInfo();
        std::cout << "Employee Type: Part-Time" << std::endl;
        std::cout << "Hourly Wage: $" << HourlyWage << std::endl;
        std::cout << "Hours Worked: " << HoursWorked << " hours" << std::endl;
    }
};

int main() {
    FullTimeEmployee fullTimeEmployee("Dolapo Agboola", 211203004, 7000.0);
    PartTimeEmployee partTimeEmployee("Clinton Mike",012345, 2000.0, 92);

    std::cout << "Full-Time Employee Details:" << std::endl;
    fullTimeEmployee.getInfo();
    std::cout << std::endl;

    std::cout << "Part-Time Employee Details:" << std::endl;
    partTimeEmployee.getInfo();

    return 0;
}