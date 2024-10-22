#include <iostream>
using namespace std;

class Matrix {
    int a[10][10], m, n;

public:
    void inputmat();
    void outputmat();
    Matrix operator+(Matrix x);
};

void Matrix::inputmat() {
    int i, j;
    cout << "Enter order: ";
    cin >> m >> n;
    cout << "Enter matrix elements: ";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void Matrix::outputmat() {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

Matrix Matrix::operator+(Matrix x) {
    Matrix c;
    if (n == x.m) {
        c.m = m;
        c.n = x.n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < x.n; j++) {
                c.a[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    c.a[i][j] += a[i][k] * x.a[k][j];
                }
            }
        }
    } else {
        cout << "Multiplication not possible." << endl;
    }
    return c;
}

int main() {
    Matrix A, B, C;
    cout << "Enter A order & elements:" << endl;
    A.inputmat();
    cout << "Enter B order & elements:" << endl;
    B.inputmat();
    C = A + B;
    cout << "Resultant Matrix:" << endl;
    C.outputmat();
    return 0;
}
