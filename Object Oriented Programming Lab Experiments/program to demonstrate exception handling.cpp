#include <iostream>
#include <exception>
using namespace std;

int main() {
    int dividend, divisor;
    float quotient;
    cout << "\nEnter the dividend: "; 
    cin >> dividend;
    cout << "\nEnter the divisor: "; 
    cin >> divisor;
    
    try {
        if (divisor == 0)
            throw "Divide by zero";
        quotient = dividend / (divisor * 1.0);
        cout << "\nThe quotient is " << quotient;
    } catch (const char* c) {
        cout << c << endl;
    }
    
    return 0;
}
