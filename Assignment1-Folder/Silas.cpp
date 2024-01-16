#include <iostream>
using namespace std;
#include <string>

class Employee {
    public:
        string Name;
        string EmployeeId;
    public:
        Employee (string name, string employeeId) : Name(name), EmployeeId(employeeId) {
        }
    virtual void getInfo(){
        cout <<"EMPLOYEE " << endl;
        cout <<"Name of Employee: " << Name <<'\n'<< "Employee ID: " << EmployeeId << endl << '\n';
    }
};

class FullTimeEmployee : Employee {
    private:
        double Salary;
    public:
        FullTimeEmployee (string name, string employeeId, double salary) : Employee(name, employeeId) , Salary(salary) {
    }
    void getInfo() override {
        cout <<"FULL TIME EMPLOYEE " << endl;
        cout << "Name of Employee: " << Name << '\n' << "Employee ID: " << EmployeeId << '\n' << "Salary: " << Salary << endl << '\n';
    }
};

class PartTimeEmployee : Employee {
    private:
        int HoursWorked;
        double HourlyPay;
    public:
        PartTimeEmployee (string name, string employeeId, int hoursWorked, int hourlyPay) :
        Employee(name, employeeId) , HourlyPay(hourlyPay), HoursWorked(hoursWorked) {
        }
    void getInfo() override {
        double Salary = HourlyPay * HoursWorked;
        cout <<"PART TIME EMPLOYEE " << endl;
        cout << "Name of Employee: " << Name << '\n' << "Employee ID: " << EmployeeId << '\n' << "Hours Worked: " << HoursWorked << " hours"<< '\n' 
        << "Hourly Pay: " << HourlyPay << " per hour"<< '\n' << "Salary: " << Salary << endl << '\n';
    }
};

int main () {
    Employee Silas("Ahmadu Silas", "NUN-211203008");
    Silas.getInfo();

    FullTimeEmployee Peter("Peter Obi", "564534564", 50000.00);
    Peter.getInfo();

    PartTimeEmployee Halima("Halima Sani", "3454676734", 6 , 1000.00);
    Halima.getInfo();
}
