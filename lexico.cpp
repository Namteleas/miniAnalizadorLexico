/** Juan Jose Flores Vega
    09/09/2020
**/

#include "lexico.h"
#include "macros.h"

char Lexico::sigCaracter()
{
    return fuente[ind++];
}

int Lexico::tipoCaracter()
{
    if(esLetra())
        return LETRA;
    else if(esNumero())
        return NUMERO;
    else if(esPunto())
        return PUNTO;
    else if(esAdicion())
        return ADICION;
    else if(esMultiplicacion())
        return MULTIPLICACION;
    else if(esAsignacion())
        return ASIGNACION;
    else if(esRelacional())
        return RELACIONAL;
    else if(esAnd())
        return AND;
    else if(esOr())
        return OR;
    else if(esNot())
        return NOT;
    else if(esLlave())
        return LLAVE;
    else if(esPuntoComa())
        return PCOMA;
    else if(esEspacio())
        return ESPACIO;
    else if(esPesos())
        return PESOS;
    else
        return ERROR;
}

void Lexico::sigEstado(int entrada)
{
    switch(estado){
    case -1:{
        if(entrada == LETRA){
            if(c == 'i')
                estado = AUX_0;
            else if(c == 'f')
                estado = AUX_1;
            else if(c == 'v')
                estado = AUX_2;
            else if(c == 'w')
                estado = AUX_3;
            else if(c == 'r')
                estado = AUX_4;
            else if(c == 'e')
                estado = AUX_5;
            else
                estado = IDENTIFICADOR;
        }
    }


    }
}

bool Lexico::esLetra()
{
    return isalpha(c) || c == '_';
}

bool Lexico::esNumero()
{
    return isdigit(c);
}

bool Lexico::esPunto()
{
    return c == '.';
}

bool Lexico::esAdicion()
{
    return c == '+' || c == '-';
}

bool Lexico::esMultiplicacion()
{
    return c == '*' || c == '/';
}

bool Lexico::esAsignacion()
{
    return c == '=';
}

bool Lexico::esRelacional()
{
    return c == '<' || c == '>';
}

bool Lexico::esAnd()
{
    return c == '&';
}

bool Lexico::esOr()
{
    return c == '|';
}

bool Lexico::esNot()
{
    return c == '!';
}

bool Lexico::esLlave()
{
    return c == '(' || c == ')' || c == '{' || c == '}';
}

bool Lexico::esPuntoComa()
{
    return c == ';';
}

bool Lexico::esEspacio()
{
    return c == ' ';
}

bool Lexico::esPesos(){
    return c == '$';
}

bool Lexico::terminado()
{
    return ind >= fuente.length();
}

Lexico::Lexico(string fuente)
{
    ind = 0;
    estado = -1;
    this->fuente = fuente;
}

Lexico::Lexico()
{
    estado = -1;
    ind = 0;
}

void Lexico::entrada(string fuente)
{
    this->fuente = fuente;
}

void Lexico::analizar()
{

}

string Lexico::getFuente()
{
    return fuente;
}

string Lexico::resultado()
{
    pila.muestra();
}
