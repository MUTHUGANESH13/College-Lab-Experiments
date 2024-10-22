#include <iostream>
using namespace std;

class Matrix {
    int x[5][5], m, n;

public:
    Matrix() {}

    Matrix(int a, int b) {
        m = a;
        n = b;
    }

    void get();
    void put();
    Matrix operator!();
};

void Matrix::get() {
    int i, j;
    cout << "Enter matrix of order " << m << " x " << n << ":" << endl;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> x[i][j];
        }
    }
}

void Matrix::put() {
    int i, j;
    cout << "Matrix after transpose:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << x[j][i] << "\t";
        }
        cout << endl;
    }
}

Matrix Matrix::operator!() {
    Matrix c(n, m);
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c.x[j][i] = x[i][j];
        }
    }
    return c;
}

int main() {
    int m, n;
    cout << "Enter order: ";
    cin >> m >> n;
    Matrix a(m, n), c;
    a.get();
    c = !a;
    c.put();
    return 0;
}
