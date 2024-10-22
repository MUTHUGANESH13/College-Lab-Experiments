#include <fstream>
#include <iostream>
using namespace std;

void put(char to[]) {
    ofstream fout(to);
    char s[1000];
    cout << "\nEnter the string to be written to the file:\n";
    cin.getline(s, 1000);
    fout << s;
    fout.close();
}

void display(char from[]) {
    ifstream fin(from);
    char s[1000];
    fin.getline(s, 1000);
    cout << "\nThe contents of the file " << from << " are:\n";
    cout << s << endl;
    fin.close();
}

int main() {
    char file[100];
    cout << "\nEnter the file name: ";
    cin.getline(file, 100);
    put(file);
    display(file);
    return 0;
}
