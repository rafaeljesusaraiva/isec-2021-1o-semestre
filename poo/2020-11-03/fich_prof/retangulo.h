#ifndef RETANGULO_H
#define RETANGULO

#include "ponto.h"

class Retangulo
{
	Ponto cse; //canto superior esquerdo
	double altura, largura;
public:
	Retangulo(const Ponto &p, double alt, double lar);
	~Retangulo();
	
	string getAsString() const;
	double area() const;

	void setCanto(const Ponto &p);
};
#endif
