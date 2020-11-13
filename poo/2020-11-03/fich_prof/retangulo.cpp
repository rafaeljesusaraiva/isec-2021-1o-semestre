#include <sstream>
#include "retangulo.h"

using std::ostringstream;

Retangulo::Retangulo(const Ponto &p, double alt, double lar) : cse(p.getX(), p.getY()), altura(alt), largura(lar) {
	if (altura < 0)
		altura = -altura;
	if (largura < 0)
		largura = -largura;
	std::cout << " a construir: " << getAsString() << "\n";
}
Retangulo::~Retangulo() {
	std::cout << " a destruir: " << getAsString() << "\n";
}

string Retangulo::getAsString() const {
	ostringstream os;
	os << "retangulo com canto superior esquerdo em " << cse.getAsString();
	os << " altura " << altura << " largura " << largura;
	return os.str();
}

double Retangulo::area() const { return altura * largura; }

void Retangulo::setCanto(const Ponto &nc) {
	cse = nc;
}

 