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

//class card
//{
//public:
//    card();
//    card(int face, int suit);
//    int return_face();
//    int return_suit();
//
//private:
//    int face; //0-3, hearts-spades-diamonds-clubs
//    int suit; //0-13, 2-3-4-5-6-7-8-9-10-jack-queen-king-ace
//};
//
//card::card()
//{}
//
//card::card(int inface, int insuit)
//{
//    face = inface;
//    suit = insuit;
//}
//
//int card::return_face()
//{
//    return face;
//}
//
//int card::return_suit()
//{
//    return suit;
//}
//
//class deck
//{
//public:
//    deck();
//    deck(int playernum); //now I can just make this a multipurpose class instead of making a player deck class
//    card deal();
//    void shuffle();
//    int size();
//    void seat_card(card bounce);
//    int playernum();
//
//private:
//    std::vector<card> deckstack;
//    int decksize;
//    int player;
//};

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

//deck::deck()
//{
//    decksize = 0;
//    player = 0;
//    for (int i = 0; i < 4; i++)
//    {
//        for (int j = 0; j < 13; j++)
//        {
//            deckstack.push_back(card(j, i));
//            decksize++;
//        }
//    }
//    shuffle();
//}
//
//deck::deck(int playernum)
//{
//    decksize = 0;
//    player = playernum;
//}
//
//void deck::shuffle()
//{
//    auto rng = std::default_random_engine {};
//    std::shuffle(deckstack.begin(), deckstack.end(), rng);
//}
//
//int deck::size()
//{
//    return decksize;
//}
//
//card deck::deal()
//{
//    card bounce(deckstack[1].return_face(), deckstack[1].return_suit());
//    deckstack.erase(deckstack.begin());
//    decksize--;
//    return bounce;
//}
//
//void deck::seat_card(card bounce)
//{
//    deckstack.push_back(bounce);
//    decksize++;
//}
//
//int deck::playernum()
//{
//    return player;
//}

#endif //P1_WAR_DECK_H
