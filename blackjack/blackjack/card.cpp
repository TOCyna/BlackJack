#include "card.h"

Card::Card(int naipe, int valor)
{
        if(valor > 0 && valor < 14)
            this->valor = valor;
        else
            cout << "\nInvalid 'valor' value\n";

        if(naipe == 0)
            this->naipe = 'H';
        else if(naipe == 1)
            this->naipe = 'D';
        else if(naipe == 2)
            this->naipe = 'S';
        else if(naipe == 3)
            this->naipe = 'C';
        else
            cout << "\nInvalid 'naipe' value\n";

        //Test
        //cout << this->naipe << endl;
        //cout << this->valor << endl;
}

string Card::toString()
{
    string name;
    name = naipe;

    //convert int to string and append to name

    ostringstream convert;
    convert << valor;
    name += convert.str();

    //Test
    //cout << name << endl;

    return name;
}
