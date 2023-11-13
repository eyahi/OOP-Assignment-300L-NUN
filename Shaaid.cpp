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
        cout <<"Name: " << Name <<'\n'<< "Employee ID: " << EmployeeId << endl<< '\n';

    }
};

class FullTimeEmployee : Employee {
    private: double Salary;

    public: FullTimeEmployee (string name, string employeeId, double salary) : Employee(name, employeeId) , Salary(salary) {
    }

    void getInfo() override {
        cout << "Name: " << Name << '\n' << "Employee ID: " << EmployeeId << '\n' << "Salary: " << Salary << endl<< '\n';
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
        << "Hourly Pay: " << HourlyPay << '\n' << "Salary: " << Salary << endl;
    }
};

int main () {
    Employee Solomon("Solomon Bola", "NUN-604303404");
    Solomon.getInfo();
    FullTimeEmployee Hassan("Hassan Ibrahim", "NUN-4050304303", 200000.00);
    Hassan.getInfo();
    PartTimeEmployee Shahid("Shahid Mohammed", "NUN-211203027", 8 , 4000.00);
    Shahid.getInfo();
}


