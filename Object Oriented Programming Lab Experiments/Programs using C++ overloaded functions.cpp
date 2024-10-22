#include <iostream>
using namespace std;

float area(float side) {
    return side * side; // Calculate area of square
}

float area(float length, float width) {
    return length * width; // Calculate area of rectangle
}

int main() {
    int c;
    float l, w, s;

    cout << "1. Square" << endl;
    cout << "2. Rectangle" << endl;
    cout << "Enter the shape of your choice: ";
    cin >> c;

    switch (c) {
        case 1:
            cout << "\nEnter the side of the square: ";
            cin >> s;
            cout << "\nThe area of the square is " << area(s);
            break;
        case 2:
            cout << "\nEnter the length of the rectangle: ";
            cin >> l;
            cout << "\nEnter the width of the rectangle: ";
            cin >> w;
            cout << "\nThe area of the rectangle is " << area(l, w);
            break;
        default:
            cout << "\nInvalid choice!!!";
            break;
    }

    return 0;
}
