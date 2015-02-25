#include "card.h"

int Card::getValor()
{
    int valor;

    valor = this->valor;

    return valor;
}

Card::Card(int naipe, int valor)
{
    if (valor < 0)
        this->valor = -1;
    else if(valor > 0 && valor < 14)
        this->valor = valor;
    else
        cout << "\nInvalid 'valor' value\n";

    if (naipe < 0)
        this->naipe = 'N';
    else if(naipe == 0)
        this->naipe = 'H';
    else if(naipe == 1)
        this->naipe = 'D';
    else if(naipe == 2)
        this->naipe = 'S';
    else if(naipe == 3)
        this->naipe = 'C';
    else
        cout << "\nInvalid 'naipe' value\n";

}

string Card::toString()
{
    string name;
    name = naipe;

    //convert int to string and append to name

    ostringstream convert;
    convert << valor;
    name += convert.str();

    return name;
}
