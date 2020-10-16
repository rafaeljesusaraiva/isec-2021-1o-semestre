#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Automovel {
    
    string matricula = "00-AA-00";
    float combustivel = 0;
    string marca;
    string modelo;
    
    public: 
        Automovel(string in_matr, string in_mar, string in_mod) :
            matricula(in_matr), marca(in_mar), modelo(in_mod) {}
        string getMatricula() const;
        string getMarca() const;
        string getModelo() const;
        float getCombustivel() const;
        string getAsString() const;

        bool setMatricula(string nova);

        void showInfo() const {
            cout << "Informacao Carro: " << endl;
            cout << "    Matricula: " << matricula << endl;
            cout << "    Marca: " << marca << endl;
            cout << "    Modelo: " << modelo << endl;
            cout << "    Combustivel: " << combustivel << endl;
        }
};

string Automovel::getMatricula() const { return matricula; }
string Automovel::getMarca() const { return marca; };
string Automovel::getModelo() const { return modelo; };
float Automovel::getCombustivel() const { return combustivel; }
string Automovel::getAsString() const {
    ostringstream os;
    os << "Marca: " << marca << " Matricula: " << matricula << "  Marca: " << " Modelo: " << modelo << " Combustivel: " << combustivel;
    return os.str();
}

bool Automovel::setMatricula(string nova = "") {
    if (nova == "00-AA-00" || nova == "")
        return false;
    matricula = nova;
    return true;
}

int main() {

    Automovel honda("12-OI-69", "honda", "civic");

    cout << honda.getAsString() << endl;

    honda.setMatricula("HE-00-YO");
    honda.setMatricula();
    cout << honda.getAsString() << endl;

    return 0;
}