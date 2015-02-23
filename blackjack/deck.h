#ifndef DECK_H
#define DECK_H

#include <list>
#include <card.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

class Deck
{
private:
    list<Card> c1;
public:
    Deck();
    string toString();
    Card draw();
    int cut(int n);
};

#endif // DECK_H
