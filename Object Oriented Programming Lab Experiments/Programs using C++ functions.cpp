#include <iostream>
using namespace std;

float area(float side) {
    return side * side;
}

int main() {
    float s;
    cout << "Enter the side of the square: ";
    cin >> s;
    cout << endl;
    cout << "The area of the square with side " << s << " is " << area(s);
    return 0;
}
