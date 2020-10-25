#ifndef MSG_H
#define MSG_H
#include <iostream>

class MSG {
    int numero;
    char letra;
    static int proxNumero;
public:
    MSG(char c = 'x');
    MSG(const MSG &z);
    ~MSG();
    std::string getAsString() const;
};

#endif // !MSG_H