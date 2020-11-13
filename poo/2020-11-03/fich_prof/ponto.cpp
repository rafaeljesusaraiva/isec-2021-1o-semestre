#include "ponto.h"
#include <string>

using std::to_string;

Ponto::Ponto(int xx, int yy) : x(xx), y(yy) {
    std::cout << " a construir: " << getAsString() << "\n";
}
Ponto::~Ponto() {
    std::cout << " a destruir: " << getAsString() << "\n";
}

string Ponto::getAsString() const {
	return "( " + to_string(x) + ", " + to_string(y) + " ) ";
}

double Ponto::distancia(const Ponto &p) const {
    double dist;

    dist = sqrt(((this->x - p.x) * (this->x - p.x)) + ((this->y - p.y) * (this->y - p.y)));

    return dist;
}

int Ponto::getX() const { return x; }
int Ponto::getY() const { return y; }

void Ponto::setX(int xx) { x = xx; }
void Ponto::setY(int yy) { y = yy; }