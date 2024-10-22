#include <iostream>
using namespace std;

template <class T>
class Number {
private:
    T num;
public:
    Number(T n) : num(n) {}
    T getNum() {
        return num;
    }
};

int main() {
    Number<int> numberInt(7);
    Number<double> numberDouble(7.7);
    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;
    return 0;
}
