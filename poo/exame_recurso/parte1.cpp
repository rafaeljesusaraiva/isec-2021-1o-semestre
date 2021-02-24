class Conjunto {
    const string data, nome;
    int quantos_maximo, limite_inf, limite_sup;
    vector<int> numeros;

public:

    Conjunto(string i_nome, string i_data, int i_qtMax, int i_limInf, int i_limSup, vector<int> i_nums) 
    : nome(i_nome), data(i_data), quantos_maximo(i_qtMax), limite_inf(i_limInf), limite_sup(i_limSup) {
        if (i_nums.size() != 0) {
            for (int i=0; i<i_nums.size(); i++) {
                if (count(numeros.begin(), numeros.end(), i_nums[i]) == 0 && numeros.size() <= quantos_maximo)
                    numeros.push_back(i_nums[i]);
            }
        }
    }

    Conjunto operator << (int novo) {
        if (count(numeros.begin(), numeros.end(), novo) == 0 && numeros.size() <= quantos_maximo)
            numeros.append(novo);
    }

    Conjunto operator >> (int remove) {
        for (int i=0; i<numeros.size(); i++)
            if (numeros[i] >= remove) numeros.erase(numeros.begin() + i);
    }

    bool operator == (const Conjunto &primeiro, const Conjunto &segundo) {
        if (primeiro.size() == segundo.size()) {
            int check = 1;
            for (int i=0; i<primeiro.size(); i++) {
                if (count(primeiro.begin(), primeiro.end(), segundo[i]) == 0)
                    check = 0;
            }
            if (check == 1) return true; else return false;
        } else return false;
    }

    int& operator [] (int i) {
        return numeros[i];
    }

}