#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <sstream>

using namespace std;

class Card
{
private:
    char naipe;
    int valor;
public:
    int getValor();
    Card(int naipe, int valor);
    string toString();
};

#endif // CARD_H
