#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    static int cur_id;
public:
    Person() {
        cur_id++;
    }
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

int Person::cur_id = 0;

class Professor : public Person {
    int publications;
public:
    Professor() {}
    void getdata() {
        cout << "Enter Professor Details:\n";
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter number of publications: ";
        cin >> publications;
    }
    void putdata() {
        cout << "Professor Details:\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Publications: " << publications << endl;
        cout << "ID: " << cur_id << endl;
    }
};

class Student : public Person {
    int marks[6];
public:
    Student() {}
    void getdata() {
        cout << "Enter Student Details:\n";
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter marks of 6 subjects: ";
        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
        }
    }
    void putdata() {
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            sum += marks[i];
        }
        cout << "Student Details:\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sum of Marks: " << sum << endl;
        cout << "ID: " << cur_id << endl;
    }
};

int main() {
    Person* person;

    Professor p;
    person = &p;
    person->getdata();
    person->putdata();

    Student s;
    person = &s;
    person->getdata();
    person->putdata();

    return 0;
}
