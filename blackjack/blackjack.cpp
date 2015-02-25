#include "blackjack.h"

Blackjack::Blackjack()
{
    humanPoints = 0;
    computerPoints = 0;
}

int Blackjack::getPoints(Card c)
{
    int points;

    if(c.getValor() > 0 && c.getValor() < 11)
        points = c.getValor();
    else if(c.getValor() > 10)
        points = 10;

    return points;
}

void Blackjack::test7()
{
    Card c0(0,1);
    Card c1(0,7);
    Card c2(1,10);
    Card c3(2,11);
    Card c4(3,13);
    Blackjack bj;
    cout << bj.getPoints(c0) << endl;
    cout << bj.getPoints(c1) << endl;
    cout << bj.getPoints(c2) << endl;
    cout << bj.getPoints(c3) << endl;
    cout << bj.getPoints(c4) << endl;
}

int Blackjack::getScore(list<Card> l)
{
    int sum = 0;
    Card aux(-1, -1);
    list<Card>::iterator it;
    for (it=l.begin(); it!=l.end(); ++it){
        aux = *it;
        sum += getPoints(aux);
    }
    return sum;
}

void Blackjack::test8(){
    list<Card> l;
    Card c0(0,1);
    l.push_back(c0);
    Card c1(1,10);
    l.push_back(c1);
    Card c2(2,11);
    l.push_back(c2);
    Card c3(3,13);
    l.push_back(c3);
    Blackjack bj;
    cout << bj.getScore(l) << endl;
}
char Blackjack::getCommand(){
    char c;
    do{
        cout << "Enter d for draw or s for stand: ";
        cin >> c;
    } while(c != 'd' && c != 's');
return c;
}

list<Card> Blackjack::humanPlayer(Deck &d)
{
    list<Card> hand;
    list<Card>::iterator it;
    char getChar;
    int sum = 0;

    while(sum < 21) {
        getChar = getCommand();
        if (getChar == 's')
            break;
        hand.push_back(d.draw());
        sum = getScore(hand);
        cout << "[";
        for (it=hand.begin(); it!=hand.end(); ++it)
            cout << ' ' << it->toString();
        cout << " ]" << " -- Score: " << sum;
        cout << endl;
    }
    if(sum > 21){
        cout << "You lost, your score is above 21, noob " << endl;
        computerPoints++;
    }
    return hand;
}

list<Card> Blackjack::computerPlayer(Deck d, int humanScore)
{
    list<Card> roboticHand;
    int sum = 0;
    list<Card>::iterator it;

    cout << "Computer: " << endl;
    while(sum <= humanScore && sum < 21) {
        roboticHand.push_back(d.draw());
        sum = getScore(roboticHand);
        cout << "[";
        for (it=roboticHand.begin(); it!=roboticHand.end(); ++it)
            cout << ' ' << it->toString();
        cout << " ]" << " -- Score: " << sum;
        cout << endl;
    }

    return roboticHand;

}

void Blackjack::game()
{
    cout << string(50, '\n');
    Deck d;
    int humanScore, computerScore;
    char playAgain;

    d.riffleShuffle(7);

    cout << "======= BLACKJACK =======\n== powered by TEAM OCD ==\n";
    cout << "GAME POINTS\nYOU: " << humanPoints << "\nCOMPUTER: " << computerPoints << endl;

    humanScore = getScore(humanPlayer(d));

    if (humanScore < 22){

        computerScore = getScore (computerPlayer(d, humanScore));

        if(computerScore > 21){
            cout << "You won! Your score was " << humanScore << ", while the computer scored " << computerScore << endl;
            humanPoints++;
        }
        else if (humanScore == computerScore) {
            cout << "It's a draw! Both of you scored " << humanScore << endl;
        }
        else {
            cout << "You lost, noob! Your score was " << humanScore << ", while the computer scored " << computerScore << endl;
            computerPoints++;
        }
    }
    cout << "Do you wanna play again? [y or n] ";
    while(playAgain != 'y' && playAgain != 'n'){
        cin >> playAgain;
    }
    if (playAgain == 'y')
        game();
}
