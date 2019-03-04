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

/*
 * Needs:
 *
 * Make it use Binary
 */

class card
{
public:
    card() = default;
    card(rank r, suit s)
            : data(static_cast<unsigned>(s) << 4 | static_cast<unsigned>(r));

    rank return_rank() const {return static_cast<rank>(data & 0xf);}
    suit return_suit() const {return static_cast<suit>(data >> 4);}

private:
    unsigned char data;
}

class deck
{
public:
    deck();
    deck(int playernum); //now I can just make this a multipurpose class instead of making a player deck class
    card deal();
    void shuffle();
    int size();
    void seat_card(card bounce);
    int playernum();

private:
    std::vector<card> deckstack;
    int decksize;
    int player;
};

deck::deck()
{
    decksize = 0;
    player = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            deckstack.push_back(card(j, i));
            decksize++;
        }
    }
    shuffle();
}

deck::deck(int playernum)
{
    decksize = 0;
    player = playernum;
}

void deck::shuffle()
{
    auto rng = std::default_random_engine {};
    std::shuffle(deckstack.begin(), deckstack.end(), rng);
}

int deck::size()
{
    return decksize;
}

card deck::deal()
{
    card bounce(deckstack[1].return_face(), deckstack[1].return_suit());
    deckstack.erase(deckstack.begin());
    decksize--;
    return bounce;
}

void deck::seat_card(card bounce)
{
    deckstack.push_back(bounce);
    decksize++;
}

int deck::playernum()
{
    return player;
}

#endif //P1_WAR_DECK_H
