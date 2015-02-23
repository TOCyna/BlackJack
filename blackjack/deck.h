#ifndef DECK_H
#define DECK_H

#include <list>
#include <card.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

class Deck
{
//private:
//    list<Card> c1;
public:
    list<Card> c1;
    Deck();
    Deck(char e);
    string toString();
    Card draw();
    int cut(int n);
    Deck split(int c);
    void test4();
    Deck riffle(Deck l1);
    void test5();
};

#endif // DECK_H
