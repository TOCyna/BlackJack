#include <iostream>
#include <blackjack.h>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    Card card(3, 13);
    cout << card.toString() << endl;
    Card c0(0,1);
    Card c1(1,10);
    Card c2(2,11);
    Card c3(3,13);
    cout << "" << c0.toString() << " " << c1.toString() << " "
    << c2.toString() << " " << c3.toString() << endl;

    Deck d;
    cout << d.toString() << endl;
    //d.toString();

    cout << "6." << endl;
    cout << "Drawn cards: " << endl;
    for (int i=0; i<53; i++)
    cout << d.draw().toString() << " ";
    cout << endl;

    cout << d.cut(52) << endl;

    list<Card> l1;
    list<Card> l2;
    list<Card>::iterator it;

    l1.push_back(c0);
    l1.push_back(c1);
    l1.push_back(c2);
    l1.push_back(c3);

    it = l1.begin();
    it++;

    l1.splice(l2.begin(), l1, it, l1.end());

    cout << "mylist1 contains:";
      for (it=l1.begin(); it!=l1.end(); ++it)
        cout << ' ' << it->toString();
      cout << '\n';
    cout << "mylist2 contains:";
        for (it=l2.begin(); it!=l2.end(); ++it)
          cout << ' ' << it->toString();
        cout << '\n';
    cout << endl;
    d.test4();
    cout << endl;
    cout << endl;
    cout << "teste 5" << endl;
    d.test5();
    //cout << "teste 6" << endl;
    //d.test6();
    cout << "teste 7: "<< endl;
    Blackjack b;
    b.test7();
    cout << "teste 8:" << endl;
    b.test8();
    cout << "Human: " << endl;
    Deck s;
    cout << "teste 6" << endl;
    s.test6();
    //b.humanPlayer(s);
    //b.computerPlayer(s, 20);
    //b.game();
}

