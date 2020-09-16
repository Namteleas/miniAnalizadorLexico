#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <list>
#include <iostream>
#include <string>

using namespace std;

class Pila{
private:
    list <int> codigo;
    list <string> entrada;

public:
    void push(int x, string s);
    void push(int x);
    int top();
    int pop();
    void muestra();

};

#endif // PILA_H_INCLUDED
