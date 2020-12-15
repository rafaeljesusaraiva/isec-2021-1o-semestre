#ifndef PEIXE_H
#define PEIXE_H

#include <string>
class Aquario;

using namespace std;

class Peixe
{
	static unsigned int conta;
	string especie;
	string cor;
	unsigned int nSerie;
	unsigned int peso = 10;
	Aquario *aquario = nullptr;
	bool indigestao = false;
	unsigned int resta = 4; //eventos de alimentação até morrer depois da indigestão
public:
	Peixe(string es, string co = "cinzento") : especie(es), cor(co), nSerie(conta++) {}

	bool isVivo() const { return resta > 0;  }
	void come(unsigned int c);
	bool ligaAquario(Aquario *a);
	string getAsString() const;
};
ostream &operator<<(ostream &, const Peixe &);
#endif // !PEIXE_H


