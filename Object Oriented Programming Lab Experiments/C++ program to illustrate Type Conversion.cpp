#include <iostream>
using namespace std;

class Time {
    int m, s;

public:
    Time(int x) {
        m = x / 60;
        s = x % 60;
    }

    void display() {
        cout << "Min = " << m << " Sec = " << s << endl;
    }
};

int main() {
    int x;
    cout << "Enter seconds: ";
    cin >> x;
    Time ob(x);
    ob.display();
    return 0;
}
