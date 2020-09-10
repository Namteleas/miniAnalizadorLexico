/** Juan Jose Flores Vega
    09/09/2020
**/

#include "lexico.h"

Lexico::Lexico(string fuente){
    ind = 0;
    estado = 0;
    this->fuente = fuente;
}

Lexico::Lexico(){
    estado = 0;
    ind = 0;
}

char Lexico::sigCaracter()
{
    return fuente[ind++];
}

void Lexico::analizar(){
    int car;
    estado = 0;
    /// Inicio del automata

    while(!terminado() && estado != 5){
        c = sigCaracter();
        car = tipoCaracter();
        sigEstado(car);
    }

}

int Lexico::tipoCaracter(){
    if(esLetra())
        return LETRA;
    else if(esNumero())
        return NUMERO;
    else if(esPunto())
        return PUNTO;
    else
        return ERROR;
}

void Lexico::sigEstado(int entrada)
{
    /// Reglas de producción del automata

    switch(estado){
    case 0:{
        if(entrada == LETRA)
            estado = 1;
        else if(entrada == NUMERO)
            estado = 2;
        else
            estado = 5;
    }
        break;
    case 1:{
        if(entrada == ERROR || entrada == PUNTO)
            estado = 5;
        else
            estado = 1;
    }
        break;
    case 2:{
        if(entrada == NUMERO)
            estado = 2;
        else if(entrada == PUNTO)
            estado = 3;
        else
            estado = 5;
    }
        break;
    case 3:{
        if(entrada == NUMERO)
            estado = 4;
        else
            estado = 5;
    }
        break;
    case 4:{
        if(entrada == NUMERO)
            estado = 4;
        else
            estado = 5;
    }
        break;
    default:
        break;
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

bool Lexico::terminado(){
    return ind >= fuente.length();
}

void Lexico::entrada(string fuente)
{
    ind = 0;
    this->fuente = fuente;
}

string Lexico::getFuente(){
    return fuente;
}

string Lexico::resultado()
{
    string cad;

    if(estado == 1)
        cad = "Identificador";
    /**
    else if(estado == 2)    //Este else if valida enteros
        cad = "Entero";
    **/
    else if(estado == 4)
        cad = "Real";
    else
        cad = "No valido";

    return cad;
}
