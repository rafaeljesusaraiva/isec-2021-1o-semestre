#ifndef AQUARIO_H
#define AQUARIO
#include <vector>
#include "Peixe.h"

using namespace std;

class Aquario
{
	vector <Peixe *> peixes;
public:
	Aquario() = default;

	void selfClean();
	void alimentaPeixes(unsigned int q);
	bool addPeixe(Peixe *);
	string getAsString() const;
};
ostream &operator<<(ostream &, const Aquario &);

#endif

