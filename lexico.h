/** Juan Jose Flores Vega
    09/09/2020
**/

#ifndef LEXICO_H_INCLUDED
#define LEXICO_H_INCLUDED

#include <iostream>
#include <string>
#include "pila.h"

using namespace std;

class Lexico{
private:
    string fuente;
    unsigned int ind;
    Pila pila;

    int estado;
    char c;

    char sigCaracter();
    int tipoCaracter();
    void sigEstado(int entrada);
    bool esLetra();
    bool esNumero();
    bool esPunto();
    bool esAdicion();
    bool esMultiplicacion();
    bool esAsignacion();
    bool esRelacional();
    bool esAnd();
    bool esOr();
    bool esNot();
    bool esLlave();
    bool esPuntoComa();
    bool esEspacio();
    bool esPesos();
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
