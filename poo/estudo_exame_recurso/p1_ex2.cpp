#include <iostream>
#include <string>

using namespace std;

class Erro {
public:
    virtual string what() const { return "quartzo"; }
};
class ErroDeriv : public Erro {
public:
    string what() const override { return "feldspato; "; }
};
void testar() {
    throw ErroDeriv();
    cout << "xisto; ";
}

int main() {
    try { testar(); cout << "ola"; }
    catch (Erro & e) { cout << e.what(); }
    catch (string e) { cout << "marmore; "; }
    cout << "fim; \n";
}

/*
 * OUTPUT
 * 
 * feldspato; fim; 
 * 
 */