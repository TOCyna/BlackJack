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
    //list<Card> c1;
    Deck();
    Deck(char e);
    string toString();
    Card draw();
    int cut(int n);
    list<Card> split(list<Card> &l, int c);
    void test4();
    list<Card> riffle(list<Card> l1, list<Card> l2);
    void test5();
    void riffleShuffle(int n);
    void test6();
};

#endif // DECK_H
