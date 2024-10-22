#include <iostream>
using namespace std;

class Volume {
    int s, l, b, h, a;

public:
    Volume(int x) {
        s = x;
        a = s * s * s;
    }

    Volume(int x, int y, int z) {
        l = x;
        b = y;
        h = z;
        a = l * b * h;
    }

    void display() {
        cout << "Volume = " << a << endl;
    }
};

int main() {
    Volume v1(4), v2(3, 4, 5);
    v1.display();
    v2.display();
    return 0;
}
