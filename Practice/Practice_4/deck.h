//
// Daniel Ulinski
// card and deck class for Game of War
//

#ifndef P1_WAR_DECK_H
#define P1_WAR_DECK_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

enum Suit {
    Spades,
    Clubs,
    Diamonds,
    Hearts,
};

enum Rank {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};

enum Color {
    Black,
    Red,
};
enum CardType {
    Standard,
    Joker,
};

class standardcard {
public:
    standardcard(Rank r, Suit s)
    : rank(r), suit(s) {}

    Rank getrank const {return rank;}
    Suit getsuit const {return suit;}

private:
    Rank rank;
    Suit suit;
};

class jokercard {
public:
    jokercard(Color c)
    : color(c) {}

    Color getcolor const {return color}

private:
    Color color;
};

union kind {
    kind(Rank r, Suit s)
    : standard(r, s) {}

    kind(Color C)
    : joker(c) {}

    standardcard standard;
    jokercard joker;
};

class card {
public:
    card(Rank r, Suit s)
    : cardtype(Standard), cardkind(r, s) {}

    card(Color c)
    : cardtype(Joker), cardkind(c) {}

private:
    CardType cardtype;
    kind cardkind;

public:
    //needs:
    //way to tell if standard or joker
    //way to return standard or joker elements

    //standard and joker card determinator
    Bool CardType() {
        if (cardtype == Standard) {return false};
        if (cardtype == Joker) {return true};
    }

    
};

#endif //P1_WAR_DECK_H
