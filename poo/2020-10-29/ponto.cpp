#include "ponto.h"

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

Ponto::Ponto(int xin, int yin): y(yin), x(xin) {
    cout << "[DEBUG] A construir " << getAsString() << endl;
}

Ponto::~Ponto() {
    cout << "[DEBUG] A destruir " << getAsString() << endl;
}

string Ponto::getAsString() const {
    return "Ponto ("+to_string(x)+", "+to_string(y)+") ";
}

double Ponto::distancia(const Ponto &p) const {
    double dist;
    
    dist = sqrt(((this->x - p.x) * (this->x - p.x))+((this->y - p.y) * (this->y - p.y)));

    return dist;
}

int Ponto::getX() const { return x; }
int Ponto::getY() const { return y; }


bool Ponto::setX(int x) {
    this->x = x;
    
    return true;
}
bool Ponto::setY(int y) {
    this->y = y;
    return true;
}