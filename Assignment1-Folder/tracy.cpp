#include <iostream>
#include <string>

class Employee {
public:
	Employee(const std::string& name, int employeeID)
	    : name(name), employeeID(employeeID) {}
	    
	void getInfo() const {
		std::cout << "Name:" << name  << "\nEmployeeID:" << employeeID << std::endl;
	}

private:
    std::string name;
	int employeeID;		
};

class FullTimeEmployee : public virtual Employee {
public:
	FullTimeEmployee(const std::string& name, int employeeID, double slary)
	    : Employee(name, employeeID), salary(salary) {}
	    
	void getInfo() const {
		Employee::getInfo();
		std::cout << "Salary: $" << salary << "(Full-Time Employee)" << std::endl;
	}

private:
	double salary;
};

class PartTimeEmployee : public virtual Employee {
public:
	PartTimeEmployee(const std::string& name, int employeeID, double hourlyWage, double hoursWorked)
	    : Employee(name, employeeID), hourlyWage(hourlyWage), hoursWorked(hoursWorked) {}
	    
	void getInfo() const {
		Employee::getInfo();
		std::cout << "Hourly Wage: $" << hourlyWage << "\nHours Worked: " << hoursWorked 
		          << "(Part-Time Employee)" << std::endl;
	}
	
private:
    double hourlyWage;
	double hoursWorked;		
};

int main() {
	FullTimeEmployee fullTimeEmployee("Tracy Amos-Nkpa", 211204020, 20.0);
	PartTimeEmployee partTimeEmployee("Jane Doe", 211204021, 20.0, 25.0);
	
	std::cout << "Full-Time Employee Detail:\n";
	fullTimeEmployee.getInfo();
	std::cout << "Part-Time Employee Details:\n";
	partTimeEmployee.getInfo();
	
	return 0;
}