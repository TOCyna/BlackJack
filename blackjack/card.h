#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <sstream>

using namespace std;

class Card
{
friend class Blackjack;
private:
    char naipe;
    int valor;
public:
    Card(int naipe, int valor);
    string toString();
};

#endif // CARD_H
