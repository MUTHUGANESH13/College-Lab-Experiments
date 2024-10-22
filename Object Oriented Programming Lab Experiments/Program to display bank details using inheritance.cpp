#include <iostream>
using namespace std;

class customer {
protected:
    string name;
    int age;
public:
    void getc() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }
    void disc() {
        cout << "\nName: " << name << "\nAge: " << age;
    }
};

class account {
protected:
    int acc;
public:
    void geta() {
        cout << "Enter account number: ";
        cin >> acc;
    }
    void disa() {
        cout << "\nAccount number: " << acc;
    }
};

class rbi : public customer, public account {
private:
    float minb, mini;
public:
    void getr() {
        minb = 300; 
        mini = 6.8;
        getc();
        geta();
    }
    void putr() {
        disc();
        disa();
    }
    void pu() {
        cout << "RBI Bank\n";
        putr();
        cout << "\nMinimum balance: " << minb << "\nMinimum interest: " << mini << endl;
    }
};

class sbi : public rbi {
private:
    float minb, mini;
public:
    void gets() {
        minb = 600; 
        mini = 7.6;
        getr();
    }
    void puts() {
        cout << "SBI Bank\n";
        putr();
        cout << "\nMinimum balance: " << minb << "\nMinimum interest: " << mini << endl;
    }
};

class icici : public rbi {
private:
    float minb, mini;
public:
    void geti() {
        minb = 1000; 
        mini = 9;
        getr();
    }
    void puti() {
        cout << "ICICI Bank\n";
        putr();
        cout << "\nMinimum balance: " << minb << "\nMinimum interest: " << mini << endl;
    }
};

int main() {
    int a;
    cout << "1. RBI\n2. SBI\n3. ICICI\nEnter your choice: ";
    cin >> a;
    
    switch (a) {
        case 1: {
            rbi r;
            r.getr();
            r.pu();
            break;
        }
        case 2: {
            sbi s;
            s.gets();
            s.puts();
            break;
        }
        case 3: {
            icici i;
            i.geti();
            i.puti();
            break;
        }
        default: {
            cout << "Wrong choice";
        }
    }
    return 0;
}
