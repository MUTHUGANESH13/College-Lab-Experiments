#include <iostream>
using namespace std;

class Employee {
    int emp_no, emp_salary;
    string emp_name;

public:
    Employee(string s, int y, int z) {
        emp_name = s;
        emp_no = y;
        emp_salary = z;
    }

    void show() {
        cout << "Emp. Name: " << emp_name << endl;
        cout << "Number: " << emp_no << endl;
        cout << "Salary: " << emp_salary << endl;
    }
};

int main() {
    Employee e1("Ram", 1, 85000), e2("Raghu", 2, 90000), e3("Akaash", 3, 85600),
             e4("Adhi", 4, 76000), e5("Ganapathy", 5, 87000);
    e1.show();
    e2.show();
    e3.show();
    e4.show();
    e5.show();
    return 0;
}
