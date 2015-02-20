#include "deck.h"

Deck::Deck()
{
    for (int i=0; i<4; i++){
        for (int j=1; j<14; j++){
            Card aux(i,j);
            c1.push_back(aux);
        }
    }
}

string Deck::toString()
{
    string str_deck;

    list<Card>::iterator i;
    str_deck = "[";
    for (i=c1.begin(); i!= --c1.end(); ++i)
        str_deck += i->toString() + ", ";
    i = --c1.end();
    string aux1 = i->toString();
    str_deck += aux1 + "]";

    return str_deck;
}

Card Deck::draw()
{
    //Card c;
    Card c = c1.front();
    c1.pop_front();
    return c;
}
