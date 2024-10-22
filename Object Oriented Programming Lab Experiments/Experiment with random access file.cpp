#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class student {
    int id;
    char grade;

public:
    void getv() {
        cout << "\nEnter the ID: ";
        cin >> id;
        cout << "\nEnter the Grade: ";
        cin >> grade;
    }

    int p_id() {
        return id;
    }

    void putv() {
        cout << "\nID: " << id;
        cout << "\nGRADE: " << grade;
    }

    void up_grade() {
        cout << "\nEnter the new grade: ";
        cin >> grade;
    }

    void disp() {
        cout << "\n" << setw(2) << id << " " << setw(3) << grade;
    }
};

void add_con() {
    student s;
    ofstream fout("student.dat", ios::app);
    cout << "\nEnter student details: ";
    s.getv();
    fout.write((char*)&s, sizeof(s));
    cout << "\nRecord added successfully";
    fout.close();
}

void read_con() {
    student s;
    int t_id, c = 0;
    ifstream fin;
    fin.open("student.dat", ios::in);
    cout << "\nEnter the ID of the student: ";
    cin >> t_id;
    while (!fin.eof()) {
        fin.read((char*)&s, sizeof(s));
        if (t_id == s.p_id()) {
            cout << "\nStudent details:";
            s.putv();
            c++;
            break;
        }
    }
    if (c == 0)
        cout << "\nNo record found";
    fin.close();
}

void up_con() {
    student s;
    int t_id, c = 0;
    fstream f("student.dat", ios::in | ios::out);
    cout << "\nEnter the ID of the student: ";
    cin >> t_id;
    while (!f.eof()) {
        f.read((char*)&s, sizeof(s));
        if (t_id == s.p_id()) {
            s.up_grade();
            f.seekg(-sizeof(s), ios::cur);
            f.write((char*)&s, sizeof(s));
            cout << "\nRecord updated successfully";
            c++;
            break;
        }
    }
    if (c == 0)
        cout << "\nNo record found";
    f.close();
}

int count() {
    ifstream fin("student.dat", ios::ate);
    int pos, c;
    student s;
    pos = fin.tellg();
    c = (pos + 1) / sizeof(s);
    return c;
}

void disp_con() {
    student s;
    int i, n;
    ifstream fin("student.dat");
    cout << "\nShowing " << count() << " records:";
    cout << "\nID GRADE";
    n = count();
    for (i = 0; i < n; i++) {
        fin.read((char*)&s, sizeof(s));
        s.disp();
    }
    fin.close();
}

int main() {
    int n, ch;
    do {
        cout << "\t\t\t\t MENU";
        cout << "\n\n 1. Add Record";
        cout << "\n 2. Display a Record (using ID)";
        cout << "\n 3. Update a Record";
        cout << "\n 4. Display all Records";
        cout << "\n!!!NOTE: Make sure that at least one record has been added before performing operations 2-4.!!!";
        cout << "\n\nEnter your choice: ";
        cin >> n;
        switch (n) {
            case 1: add_con(); break;
            case 2: read_con(); break;
            case 3: up_con(); break;
            case 4: disp_con(); break;
            default: cout << "\nInvalid command. ... Returning to menu\n";
        }
        cout << "\nDo you want to continue (1-yes): ";
        cin >> ch;
    } while (ch == 1);
    return 0;
}
