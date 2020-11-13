#ifndef PONTO_H
#define PONTO_H

#include <iostream>

using std::string;

class Ponto
{
	int y;
	int x;
public:
	Ponto(int x = 0, int y = 0);
	~Ponto();
	
	int getX() const;
	int getY() const;
	double distancia(const Ponto &p) const;
	string getAsString() const;

	void setX(int x);
	void setY(int y);
};
#endif
