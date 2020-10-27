#include <iostream>
#include <vector>
#include <string>
#include "televisao.h"

using namespace std;

int main() {
    Televisao tv1({"rtp1", "rtp2", "sic", "tvi"});
    tv1.liga();
    cout << tv1.getAsString() << endl;
    Televisao tv2({});
    cout << tv2.getAsString() << endl;

}