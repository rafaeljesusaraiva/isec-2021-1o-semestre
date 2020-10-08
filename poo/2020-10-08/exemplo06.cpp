#include <iostream>
#include <string>

using namespace std;

void reset(int &i) {
    i = 0;
}

int main() {
    int i = 1024;
    cout << i << endl;

    int &refI = i;
    refI = 10;
    cout << i << endl;

    int &ref2 = refI;
    ref2 = 5;
    cout << i << endl;

    reset(i);
    cout << i << endl;

    return 0;
}