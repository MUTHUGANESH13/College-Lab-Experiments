#include <iostream>
using namespace std;

class oops {
protected:
    int o;
public:
    void geto() {
        cout << "Enter OOPs marks: ";
        cin >> o;
    }
};

class python {
protected:
    int p;
public:
    void getp() {
        cout << "Enter Python marks: ";
        cin >> p;
    }
};

class maths {
protected:
    int m;
public:
    void getm() {
        cout << "Enter Maths marks: ";
        cin >> m;
    }
};

class stud : public oops, public python, public maths {
protected:
    int rn, ma;
    string n;
public:
    void gets() {
        cout << "Enter name and roll number: ";
        cin >> n >> rn;
        geto();
        getm();
        getp();
        ma = o + p + m;
        cout << "Total marks: " << ma << endl;
    }
};

int main() {
    stud s;
    s.gets();
    return 0;
}
