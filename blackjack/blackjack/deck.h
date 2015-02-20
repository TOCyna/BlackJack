#ifndef DECK_H
#define DECK_H

#include <list>
#include <card.h>


class Deck
{
private:
    list<Card> c1;
public:
    Deck();
    string toString();
    Card draw();
};

#endif // DECK_H
