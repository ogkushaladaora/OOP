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
    standardcard(Rank r, Suit s)
    : rank(r), suit(s) {}

    Rank getrank const {return rank;}
    Suit getsuit const {return suit;}

private:
    Rank rank;
    Suit suit;
};

class jokercard {
    jokercard(Color c)
    : color(c) {}

    Color getcolor const {retrun color}

private:
    Color color;
};

union card {
    card(Rank r, Suit s)
    : standard(r, s) {}

    card(Color C)
    : joker(c) {}

    standardcard standard;
    jokercard joker;
};



#endif //P1_WAR_DECK_H
