// This file is written by Alireza Kamyab
// Answer to projecteuler.net/problem=54
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Card Model
class Card {
    int _v;
    char _t;
public:
    Card() {_v = 0; _t = 0;};
    Card(const int& value, const char& type) : _v(value), _t(type) {};

    int value(void) const {return _v;}
    int type(void) const {return _t;}

    void setValue(const int& value) { _v = value; }
    void setType(const char& type) { _t = type; }
};

// Function prototypes
bool playerOneWinner(const Card* p1, const Card* p2);
void convertStringToHands(string text, Card* player1, Card* player2);
void sortHand(Card* hand);

int main() {
    int counter = 0;
    Card player1 [5];
    Card player2 [5];

    fstream stream;
    stream.open("PokerHands.txt", ios::in);
    
    if(stream.is_open()) {
        string str;
        while(getline(stream, str)){
            convertStringToHands(str, player1, player2);

            sortHand(player1);
            sortHand(player2);

            if(playerOneWinner(player1, player2)) counter++;
        }

        stream.close();
    }

    cout << counter << endl;
    return 0;
}

void convertStringToHands(string text, Card* player1, Card* player2) {
    text += ' ';
    string temp;
    int counter = 0;
    int i = 0;
    for(; i <= text.size() / 2; i++) {
        if(text[i] == ' ') {
            if(temp[0] != 'T' && temp[0] != 'J' && temp[0] != 'Q' && temp[0] != 'K' && temp[0] != 'A') {
                player1[counter].setValue(temp[0] - '0');
            }
            else {
                if(temp[0] == 'T') player1[counter].setValue(10);
                else if(temp[0] == 'J') player1[counter].setValue(11);
                else if(temp[0] == 'Q') player1[counter].setValue(12);
                else if(temp[0] == 'K') player1[counter].setValue(13);
                else player1[counter].setValue(14);
            }

            player1[counter].setType(temp[1]);
            counter++;
            temp = "";
            continue;
        }

        temp += text[i]; 
    }

    temp = "";
    counter = 0;

    for(i--; i < text.size(); i++) {
        if(text[i] == ' ') {
            if(temp[0] != 'T' && temp[0] != 'J' && temp[0] != 'Q' && temp[0] != 'K' && temp[0] != 'A') {
                player2[counter].setValue(temp[0] - '0');
            }
            else {
                if(temp[0] == 'T') player2[counter].setValue(10);
                else if(temp[0] == 'J') player2[counter].setValue(11);
                else if(temp[0] == 'Q') player2[counter].setValue(12);
                else if(temp[0] == 'K') player2[counter].setValue(13);
                else player2[counter].setValue(14);
            }

            player2[counter].setType(temp[1]);
            counter++;
            temp = "";
            continue;
        }

        temp += text[i]; 
    }
}

void sortHand(Card* hand) {
    for(int i = 0; i < 5; i++) {
        Card min = hand[i];
        int index = i;
        for(int j = i + 1; j < 5; j++) {
            if(min.value() > hand[j].value()) {
                min = hand[j];
                index = j;
            }
        }
        Card temp = hand[i];
        hand[i] = min;
        hand[index] = temp;
    }
}

// Returns true if hand is more valuable than otherHand
bool isMoreValuable(const Card* hand, const Card* otherHand) {
    for(int i = 4; i >= 0; i--) {
        if(hand[i].value() > otherHand[i].value()) return true;
        else if(hand[i].value() < otherHand[i].value()) return false;
    }

    return false;
}

int countCardNumberInHand(const Card* hand, const int& value) {
    int count = 0;
    for(int i = 0; i < 5; i++) if(hand[i].value() == value) count++;

    return count;
}

int countCardTypeInHand(const Card* hand, const char& type) {
    int count = 0;
    for(int i = 0; i < 5; i++) if(hand[i].type() == type) count++;
    return count;
}

int onePair(const Card* hand) {
    for(int i = 0; i < 4; i++) {
        if(hand[i].value() == hand[i + 1].value()) return hand[i].value();
    }

    return -1;
}

int twoPair(const Card* hand) {
    int p1 = 0;
    int p2 = 0;

    int i = 0;
    for(; i < 4; i++) {
        if(hand[i].value() == hand[i + 1].value()) {
            p1 = hand[i].value();
            i++;
            break;
        }
    }

    for(; i < 4; i++) {
        if(hand[i].value() == hand[i + 1].value()) {
            p2 = hand[i].value();
        }
    }

    if(p1 != 0 && p2 != 0) return p1 + p1 + p2 + p2;
    else return -1;
}

int threeOfAKind(const Card* hand) {
    for(int i = 0; i < 3; i++) {
        if(hand[i].value() == hand[i + 1].value() && hand[i].value() == hand[i + 2].value()) {
            return hand[i].value();
        }
    }

    return -1;
}

bool isStraight(const Card* hand) {
    int min = hand[0].value();
    for(int i = 0; i < 5; i++) {
        if(hand[i].value() != min++) return false;
    }
    
    return true;
}

bool isFlush(const Card* hand) {
    for(int i = 1; i < 5; i++) {
        if(hand[0].type() != hand[i].type()) return false;
    }

    return true;
}

bool isFullHouse(const Card* hand) {
    int toak = threeOfAKind(hand);
    if(toak <= 1) return false;
    int nextOne = -1;
    for(int i = 0; i < 5; i++) {
        if(hand[i].value() == toak) continue;
        if(nextOne == -1) {
            nextOne = hand[i].value();
            continue;
        }
        if(hand[i].value() != nextOne) return false;
    }

    return true;
}

int fourOfAKind(const Card* hand) {
    for(int i = 0; i < 2; i++) {
        if(hand[i].value() == hand[i + 1].value() && hand[i].value() == hand[i + 2].value() && hand[i].value() == hand[i + 3].value()) {
            return hand[i].value();
        }
    }

    return -1;
}

bool isStraighFlush(const Card* hand) {
    if(!isFlush(hand)) return false;
    if(!isStraight(hand)) return false;

    return true;
}

bool isRoyalFlush(const Card* hand) {
    if(!isFlush(hand)) return false;

    int min = hand[0].value();
    if(min != 10) return false;
    return true;
}

int levelOfHand(const Card* hand) {
    if(isRoyalFlush(hand)) return 10;
    if(isStraighFlush(hand)) return 9;
    if(fourOfAKind(hand) > 1) return 8;
    if(isFullHouse(hand)) return 7;
    if(isFlush(hand)) return 6;
    if(isStraight(hand)) return 5;
    if(threeOfAKind(hand) > 1) return 4;
    if(twoPair(hand) > 1) return 3;
    if(onePair(hand) > 1) return 2;
    else return 1;
}

bool playerOneWinner(const Card* p1, const Card* p2) {
    int level1 = levelOfHand(p1);
    int level2 = levelOfHand(p2);

    if(level1 > level2) return true;
    else if(level2 > level1) return false;

    if(level1 == level2 && level1 == 9) return isMoreValuable(p1, p2);
    if(level1 == level2 && level1 == 8) {
        int f1 = fourOfAKind(p1); 
        int f2 = fourOfAKind(p2);
        if(f1 > f2) return true;
        else if(f1 < f2) return false;
        else return isMoreValuable(p1, p2);
    }
    if(level1 == level2 && level1 == 7) return isMoreValuable(p1, p2);
    if(level1 == level2 && level1 == 6) return isMoreValuable(p1, p2);
    if(level1 == level2 && level1 == 5) return isMoreValuable(p1, p2);
    if(level1 == level2 && level1 == 4) {
        int tok1 = threeOfAKind(p1);
        int tok2 = threeOfAKind(p2);
        if(tok1 > tok2) return true;
        else if(tok1 < tok2) return false;
        else return isMoreValuable(p1, p2);
    }
    if(level1 == level2 && level1 == 3) {
        int pair1 = twoPair(p1);
        int pair2 = twoPair(p2);

        if(pair1 > pair2) return true;
        else if(pair2 > pair1) return false;
        else return isMoreValuable(p1, p2);
    }
    if(level1 == level2 && level1 == 2) {
        int pair1 = onePair(p1);
        int pair2 = onePair(p2);

        if(pair1 > pair2) return true;
        else if(pair1 < pair2) return false;
        else return isMoreValuable(p1, p2);
    }
    return isMoreValuable(p1, p2);
}