#include <iostream>
using namespace std;

class Largest {
private:
    int x, y, z;

public:
    void input();
    void calc();
};

void Largest::input() {
    cout << "\nEnter 1st number: ";
    cin >> x;
    cout << "\nEnter 2nd number: ";
    cin >> y;
    cout << "\nEnter 3rd number: ";
    cin >> z;
}

void Largest::calc() {
    int r;
    r = (x > y && x > z) ? x : (y > x && y > z) ? y : z;
    cout << "\nThe largest number among [" << x << ", " << y << ", " << z << "] = " << r << "\n";
}

int main() {
    Largest g;
    g.input();
    g.calc();
    return 0;
}
