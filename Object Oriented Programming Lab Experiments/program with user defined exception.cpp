#include <iostream>
#include <exception>
using namespace std;

class DayError: public exception {
public:
    const char* what() const throw() {
        return "\nDay value mismatch.";
    }
};

class MonthError: public exception {
public:
    const char* what() const throw() {
        return "\nMonth value incorrect.";
    }
};

void alpha(int m, int d) {
    const char month[][20] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };
    cout << "\nThe alphabetic format is: " << month[m - 1] << " " << d << endl;
}

int main() {
    try {
        int m, d;
        cout << "\nEnter the date in (mm/dd) format: ";
        scanf("%d/%d", &m, &d);
        
        if (m < 1 || m > 12) {
            throw MonthError();
        } else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d < 1 || d > 31)) {
            throw DayError();
        } else if ((m == 4 || m == 6 || m == 9 || m == 11) && (d < 1 || d > 30)) {
            throw DayError();
        } else if (m == 2 && (d < 1 || d > 29)) {
            throw DayError();
        }
        
        alpha(m, d);
    } catch (exception &E) {
        cout << E.what() << endl;
    }

    return 0;
}
