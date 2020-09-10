/** Juan Jose Flores Vega
    09/09/2020
**/

#include <iostream>
#include "lexico.h"

using namespace std;

int main()
{
    Lexico lex;

    lex.entrada("num_Aux");
    lex.analizar();
    cout<< lex.getFuente() << "\t\t" << lex.resultado() << endl;
    lex.entrada("80.763");
    lex.analizar();
    cout<< lex.getFuente() << "\t\t" << lex.resultado() << endl;
    lex.entrada("8hmd");
    lex.analizar();
    cout<< lex.getFuente() << "\t\t" << lex.resultado() << endl;
    lex.entrada("numero2");
    lex.analizar();
    cout<< lex.getFuente() << "\t\t" << lex.resultado() << endl;
    lex.entrada("num.dos");
    lex.analizar();
    cout<< lex.getFuente() << "\t\t" << lex.resultado() << endl;
    return 0;
}
