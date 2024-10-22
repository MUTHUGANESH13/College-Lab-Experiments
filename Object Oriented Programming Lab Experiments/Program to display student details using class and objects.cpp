#include <iostream>
using namespace std;

class Student {
private:
    char name[30];
    long rollNo;
    int m1, m2, m3;
    char branch[30];
    int total;

public:
    void getStudent() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll no: ";
        cin >> rollNo;
        cout << "Enter branch: ";
        cin >> branch;
    }

    void showStudent() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Branch: " << branch << endl;
    }

    void marks() {
        cout << "Enter marks for subject 1: ";
        cin >> m1;
        cout << "Enter marks for subject 2: ";
        cin >> m2;
        cout << "Enter marks for subject 3: ";
        cin >> m3;
        total = m1 + m2 + m3;
        cout << "Total Marks: " << total << endl;
    }
};

int main() {
    Student student[10];
    for (int i = 0; i < 5; i++) {
        student[i].getStudent();
    }

    cout << "Student Details are: " << endl;
    for (int i = 0; i < 5; i++) {
        student[i].showStudent();
    }

    for (int i = 0; i < 5; i++) {
        student[i].marks();
    }

    return 0;
}
