#include <iostream>
using namespace std;

class Time {
    int ts;

public:
    void getseconds() {
        cout << "Enter Seconds: ";
        cin >> ts;
    }

    operator int() {
        return ts / 60; // Convert seconds to minutes
    }

    operator float() {
        return ts % 60; // Convert seconds to seconds
    }
};

int main() {
    Time ob;
    ob.getseconds();
    int minutes = ob; // Implicit conversion to int for minutes
    float seconds = ob; // Implicit conversion to float for seconds
    cout << "Mins = " << minutes << endl;
    cout << "Secs = " << seconds << endl;
    return 0;
}
