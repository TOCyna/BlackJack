#include "deck.h"

Deck::Deck()
{
    //set a seed to cut
    srand((unsigned)time(NULL));

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

list<Card> Deck::split(list<Card> &l, int c)
{
    list<Card> r;
    for(int i = 0; i < c; i++){
        r.push_back(l.front());
        l.pop_front();
    }
    return r;
}

list<Card> Deck::riffle(list<Card> l1, list<Card> l2)
{
    list<Card> cat;
    int bigger;

    if(l1.size() > l2.size())
        bigger = l1.size();
    else
        bigger = l2.size();

    for(int i = 0; i < bigger; i++)
    {
        if(!l1.empty())
            cat.push_back(l1.front());
            l1.pop_front();
        if(!l2.empty())
            cat.push_back(l2.front());
            l2.pop_front();
    }
    return cat;
}

/*void Deck::test4(){
    int c[3] = {0,26,52};
    for (int i = 0; i < 3; i++){
        cout << "Cut = " << c[i] << endl;
        Deck d;
        list<Card>::iterator it;
        list<Card> first = d.split(d.c1, c[i]);
        cout << "First heap: " << endl << "[";
        for (it=first.begin(); it!=first.end(); ++it)
          cout << " " << it->toString();
        cout << "] \n";
        cout << "Second heap: " << endl << "[";
        for (it=d.c1.begin(); it!=d.c1.end(); ++it)
                  cout << " " << it->toString();
                cout << "] \n";
    }
}*/

void Deck::test4(){
    int c[3] = {0,26,52};

    for(int i = 0; i<3; i++){
        cout << "Cut = " << c[i] << endl;
        Deck d;
        list<Card> l = split(d.c1,c[i]);
        list<Card>::iterator it = l.begin();
        list<Card>::iterator itl = d.c1.begin();

        cout << "First heap: ";
        while(it != l.end()){
            cout << (*it).toString() << " ";
            it++;
        }
        cout << endl;

        cout << "Second heap: ";
        while(itl != d.c1.end()){
            cout << (*itl).toString() << " ";
            itl++;
        }
        cout << endl;
    }
}

void Deck::test5(){
    Deck d;
    list<Card>::iterator it;
    list<Card> aux;
    list<Card> l = d.split(d.c1, 26);
    cout << "First heap: " << endl << "[";
    for (it=l.begin(); it!=l.end(); ++it)
      cout << " " << it->toString();
    cout << "] \n";
    cout << "Second heap: " << endl << "[";
    for (it=d.c1.begin(); it!=d.c1.end(); ++it)
              cout << " " << it->toString();
            cout << "] \n";
    aux = d.riffle(l, d.c1);
    cout<< "Riffle result: " << endl << "[";
    for (it=aux.begin(); it!=aux.end(); ++it)
              cout << " " << it->toString();
    cout << "] \n";
}

void Deck::riffleShuffle(int n)
{
    int c;
    list<Card> l;
    for (int i = 0; i < n; i++){
        c = cut(52);

        cout << "\n\n C:" << c << "\n\n";

        l = split(c1, c);

        //cout << "\n\n C:" << c << "\n\n";

        //c1 = riffle(l, c1);
    }
}

void Deck::test6(){
    //Deck d;
    cout << toString() << endl;
    //cout << c1.riffleShuffle(7) << endl;
    //cout << endl;
    riffleShuffle(7);
    //cout << toString() << endl;
}


