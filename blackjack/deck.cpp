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
    Card c(-1,-1);
    if (!c1.empty()){
        c = c1.front();
        c1.pop_front();
    }
    return c;
}

int Deck::cut(int n){
    int c;
    double aux_rand;
    srand(time(NULL));

    aux_rand = ((double)rand() / (RAND_MAX+1.0));
    double sum = 0;

    for(int i = 0; i < n; i++){
        double num = 1;
        double denom = 1;
        double mult;
        for(int j=0; j <= i; j++){
            num *= (n-j);
            denom *= (j+1);
            mult = num/denom;
        }
        mult /= pow(2,n);
        sum += mult;
        if (sum < aux_rand)
            c = i;
    }
    return c;
}

Deck Deck::split(Deck l, int c)
{
    Deck head;
    list<Card>::iterator it;
    it = head.c1.begin();
    for(int i = 0; i < c; i++, it++);
    l.c1.splice(head.c1.begin(), head.c1, it, l.c1.end());

    return head;
}

void Deck::test4(){
    int c[3] = {0,26,52};
    cout << "Cut = " << c[0] << endl;
    Deck d;
    Deck l = d.split(d, c[0]);
    cout << "First heap: " << l.toString() << endl;
    cout << "Second heap: " << d.toString() << endl;
}
