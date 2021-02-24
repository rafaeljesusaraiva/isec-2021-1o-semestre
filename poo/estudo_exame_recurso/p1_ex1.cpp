#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Item {
    string msg;
public:
    Item (const string & s): msg(s) { cout << "Constr " << msg << "; " << endl; }
    ~Item () { cout << "Destr " << msg << "; " << endl; }
};

void f() {
    Item *p1 = new Item("Girassol");
    unique_ptr<Item> a = make_unique<Item>("Magnolia");
    Item *p2 = new Item("Girassol");
}

int main() { f(); }

/*
 * OUTPUT
 * 
 * Constr Girassol; 
 * Constr Magnolia; 
 * Constr Girassol; 
 * Destr Magnolia; 
 * 
 */