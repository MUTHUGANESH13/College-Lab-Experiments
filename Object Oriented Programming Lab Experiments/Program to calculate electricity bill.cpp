#include <iostream>
using namespace std;

class Bill {
    int s, bill;
    string name;

public:
    Bill(int units, string name) {
        this->name = name; // Store the name
        if (units > 100) {
            s = units - 100;
            bill = s * 5;
            cout << "Name: " << name << endl;
            cout << "Price: " << bill << " rs" << endl;
        } else {
            cout << "Name: " << name << endl;
            cout << "Minimal consumption." << endl;
        }
    }
};

int main() {
    int n, i;
    string name;
    for (i = 1; i <= 5; i++) {
        cout << "Enter name: " << endl;
        cin >> name;
        cout << "Enter units: " << endl;
        cin >> n;
        Bill b(n, name);
    }
    return 0;
}
