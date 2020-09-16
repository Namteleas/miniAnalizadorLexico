#include "pila.h"

void Pila::push(int x, string s)
{
    codigo.push_back(x);
    entrada.push_back(s);
}

void Pila::push(int x)
{
    codigo.push_front(x);
}

int Pila::top()
{
    return *codigo.begin();
}

int Pila::pop()
{
    int x = *codigo.begin();
    codigo.erase(codigo.begin());

    return x;
}

void Pila::muestra()
{
    list <int>::iterator it;
    list <string>::iterator it2;

    for (it= codigo.begin(), it2= entrada.begin(); it != codigo.end(); it++, it2++){
        cout << (*it) << "\t" << (*it2) << endl;
    }
}
