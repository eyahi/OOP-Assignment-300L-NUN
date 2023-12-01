#include <iostream>
using namespace std;
#include <string>

class Employee {
    protected:
        string Name;
        string EmployeeId;

    public: Employee (string name, string employeeId) : Name(name), EmployeeId(employeeId) {
        }
    virtual void getInfo(){
        cout <<"Name: " << Name <<'\n'<< "Employee ID: " << EmployeeId << endl << '\n';

    }
};

class FullTimeEmployee : Employee {
    private: double Salary;

    public: FullTimeEmployee (string name, string employeeId, double salary) : Employee(name, employeeId) , Salary(salary) {
    }

    void getInfo() override {
        cout << "Name: " << Name << '\n' << "Employee ID: " << EmployeeId << '\n' << "Salary: " << Salary << endl << '\n';
    }
};

class PartTimeEmployee : Employee {
    private:
        int HoursWorked;
        double HourlyPay;

    public: PartTimeEmployee (string name, string employeeId, int hoursWorked, int hourlyPay) :
        Employee(name, employeeId) , HourlyPay(hourlyPay), HoursWorked(hoursWorked) {
        }

    void getInfo() override {
        double Salary = HourlyPay * HoursWorked;
        cout << "Name: " << Name << '\n' << "Employee ID: " << EmployeeId << '\n' << "Hours Worked: " << HoursWorked << '\n' 
        << "Hourly Pay: " << HourlyPay << '\n' << "Salary: " << Salary << endl << '\n';
    }
};

int main () {
    Employee Talib("Ahmed Talib Jibril", "NUN-211203033");
    Talib.getInfo();
    FullTimeEmployee Destiny("Destiny Michael", "NUN-00340404033", 500000.00);
    Destiny.getInfo();
    PartTimeEmployee Ayuba("Suleman Ayuba", "NUN-02340232342", 8 , 5000.00);
    Ayuba.getInfo();
}
