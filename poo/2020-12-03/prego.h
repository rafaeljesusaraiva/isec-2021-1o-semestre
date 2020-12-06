#ifndef PREGO_H
#define PREGO_H

#include <vector>

class Aviso;

using namespace std;

class Prego {
	int x, y;
	vector<Aviso *> avisos;
public:
	Prego(int a, int b);
	~Prego();
	Prego(const Prego &) = delete;

	Prego &operator=(const Prego &) = delete;

	void ligaAviso(Aviso *a) {
		avisos.push_back(a);
	}
	bool desligaAviso(Aviso *a);
	string listaAvisos() const;
	std::string getAsString() const;
	int getX() const { return x; }
	int getY() const { return y; }

	void mudaDeSitio(int a, int b);
};

#endif

