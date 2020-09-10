/** Juan Jose Flores Vega
    09/09/2020
**/

#ifndef LEXICO_H_INCLUDED
#define LEXICO_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define ERROR -1
#define LETRA 0
#define NUMERO 1
#define PUNTO 2

class Lexico{
private:
    string fuente;
    unsigned int ind;

    int estado;
    char c;

    char sigCaracter();
    int tipoCaracter();
    void sigEstado(int entrada);
    bool esLetra();
    bool esNumero();
    bool esPunto();
    bool terminado();

public:
    Lexico(string fuente);
    Lexico();

    void entrada(string fuente);
    void analizar();
    string getFuente();
    string resultado();
};

#endif // LEXICO_H_INCLUDED
