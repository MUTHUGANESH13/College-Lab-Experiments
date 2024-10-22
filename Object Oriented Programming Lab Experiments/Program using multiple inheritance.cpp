#include <iostream>
using namespace std;

class vehicle {
protected:
    int mile, p;

public:
    void getv() {
        cout << "Enter miles and price: ";
        cin >> mile >> p;
    }

    void putv() {
        cout << "Miles: " << mile << " Price: " << p << endl;
    }
};

class car : public vehicle {
protected:
    int cost, war, sc;
    string f;

public:
    void getc() {
        getv();
        cout << "Enter cost, warranty years, seating capacity, and fuel type: ";
        cin >> cost >> war >> sc >> f;
    }

    void putc() {
        putv();
        cout << " Cost: " << cost << " Warranty: " << war << " Seating capacity: " << sc << " Fuel type: " << f << endl;
    }
};

class bike : public vehicle {
protected:
    int cyl, gear, fts;
    string wt, ct;

public:
    void getb() {
        getv();
        cout << "Enter cylinder type, no of gears, fuel tank size, wheel type, and cooling type: ";
        cin >> cyl >> gear >> fts >> wt >> ct;
    }

    void putb() {
        putv();
        cout << " Cylinder type: " << cyl << " No of gears: " << gear << " Fuel tank size: " << fts << " Wheel type: " << wt << " Cooling type: " << ct << endl;
    }
};

class audi : public car {
protected:
    int mot;

public:
    void geta() {
        cout << "\nAudi car:\n";
        getc();
        cout << "Enter model type: ";
        cin >> mot;
    }

    void puta() {
        cout << "\nAudi car details\n----------------------------------\n";
        putc();
        cout << " Model type: " << mot << endl;
    }
};

class ford : public car {
protected:
    int mot;

public:
    void getf() {
        cout << "\nFord car:\n";
        getc();
        cout << "Enter model type: ";
        cin >> mot;
    }

    void putf() {
        cout << "\nFord car details\n--------------------------\n";
        putc();
        cout << " Model type: " << mot << endl;
    }
};

class bajaj : public bike {
protected:
    int mat;

public:
    void getba() {
        cout << "\nBajaj bike:\n";
        getb();
        cout << "Enter make type: ";
        cin >> mat;
    }

    void putba() {
        cout << "\nBajaj bike details\n------------------------------\n";
        putb();
        cout << " Make type: " << mat << endl;
    }
};

class tvs : public bike {
protected:
    int mat;

public:
    void gett() {
        cout << "\nTVS bike:\n";
        getb();
        cout << "Enter make type: ";
        cin >> mat;
    }

    void putt() {
        cout << "\nTVS bike details\n------------------------------\n";
        putb();
        cout << " Make type: " << mat << endl;
    }
};

int main() {
    tvs t;
    bajaj b;
    audi a;
    ford f;

    t.gett();
    b.getba();
    a.geta();
    f.getf();

    t.putt();
    b.putba();
    a.puta();
    f.putf();

    return 0;
}
