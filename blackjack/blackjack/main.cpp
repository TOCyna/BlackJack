#include <iostream>
#include <card.h>
#include <deck.h>

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
    for (int i=0; i<52; i++)
    cout << d.draw().toString() << " ";
    cout << endl;
    return 0;
}

