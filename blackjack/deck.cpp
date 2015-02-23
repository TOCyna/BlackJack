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

Deck::Deck(char e)
{
    e = 'e';
    char x = e;
    e = x;
}

string Deck::toString()
{
    string str_deck = "[]";
    list<Card>::iterator i;
    if (!c1.empty()){
        str_deck = "[";
        for (i=c1.begin(); i!= --c1.end(); ++i)
            str_deck += i->toString() + ", ";
        i = --c1.end();
        string aux1 = i->toString();
        str_deck += aux1 + "]";
    }
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

/*Deck Deck::split(Deck l, int c)
{
    Deck head;
    list<Card>::iterator it;
    it = l.c1.begin();
    for(int i = 0; i < 52; i++){
        head.c1.pop_back();
    }
    for(int i = 0; i < c; i++)
        it++;
    l.c1.splice(head.c1.begin(), head.c1, it, l.c1.end());
    return head;
}*/

Deck Deck::split(int c)
{
    char e = 'e';
    Deck head(e);
    //for(int i = 0; i < 52; i++){
    //    head.c1.pop_back();
    //}
    for(int i = 0; i < c; i++){
        head.c1.push_back(c1.front());
        //head.c1.push_back(l.draw());
        c1.pop_front();
    }
    return head;
}

Deck Deck::riffle(Deck l1)
{
    char e = 'e';
    Deck d(e);
    int bigger;

    if(l1.c1.size() > c1.size())
        bigger = l1.c1.size();
    else
        bigger = c1.size();

    for(int i = 0; i < bigger; i++)
    {
        if(!l1.c1.empty())
            d.c1.push_back(l1.draw());
        if(!c1.empty())
            d.c1.push_back(draw());
    }
    return d;
}

void Deck::test4(){
    int c[3] = {0,26,52};
    for (int i = 0; i < 3; i++){
        cout << "Cut = " << c[i] << endl;
        Deck d;
        Deck first = d.split(c[i]);
        cout << "First heap: " << first.toString() << endl;
        cout << "Second heap: " << d.toString() << endl;
    }
}

void Deck::test5(){
    Deck d;
    Deck l = d.split(26);
    cout << "First heap: " << l.toString() << endl;
    cout << "Second heap: " << d.toString() << endl;
    cout<< "Riffle result: " << d.riffle(l).toString() << endl;
}
