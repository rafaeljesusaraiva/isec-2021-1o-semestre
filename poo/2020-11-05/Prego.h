#ifndef PREGO_H
#define PREGO_H

#include <iostream>
#include <string>
using namespace std;

class Prego {
  int x, y;

public:
    Prego(int a, int b) {
        x = a; y = b;
        cout << "[DEBUG] Construindo prego em " << x << "," << y << endl;
    }
    ~Prego() {
        cout << "[DEBUG] Destruindo prego em " << x << "," << y << endl;
    }

    int getX() const { return x; }
    int getY() const { return y; }
    string getAsString() const {
        return "Prego em (" + to_string(this->x) + ", " + to_string(this->y) + ")";
    }

    void mudaDeSitio(int a, int b) {
        x = a; y = b;
    }
};

#endif // !PREGO_H
