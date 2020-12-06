#include <iostream>
#include <sstream>
#include <string>
#include "prego.h"
#include "aviso.h"

using std::cout;
using std::ostringstream;
using std::string;
using std::to_string;
using std::vector;

Prego::Prego(int a, int b) {
	x = a; y = b;
	cout << "construindo prego em " << x << "," << y << "\n";
}
Prego::~Prego() {
	cout << "destruindo prego em " << x << "," << y << "\n";
	for (auto pa : avisos) {
		pa->tiraDoPrego(this);
	}
}

bool Prego::desligaAviso(Aviso *a) {
	vector<Aviso*>::iterator it = avisos.begin();
	while (it < avisos.end()) {
		if (*it == a) {
			avisos.erase(it);
			return true;
		}
		++it;
	}
	return false;
}
string Prego::listaAvisos() const {
	ostringstream os;
	for (Aviso *a : avisos)
		os << "\t" << a->getAsString() << "\n";
	return os.str();
}

string Prego::getAsString() const {
	return "Prego em (" + to_string(this->x) + ", " + to_string(this->y) + ")";
}

void Prego::mudaDeSitio(int a, int b) {
	x = a; y = b;
}
