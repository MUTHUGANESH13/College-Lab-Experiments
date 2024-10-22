#include <iostream>
using namespace std;

class Sum {
private:
    int n, s = 0;

public:
    void calc();
    void display();
};

void Sum::calc() {
    for (n = 1; n <= 100; n += 2) {
        s = s + n;
    }
}

void Sum::display() {
    cout << "Sum of all odd numbers between 1-100: " << s << endl;
}

int main() {
    Sum s;
    s.calc();
    s.display();
    return 0;
}
