#pragma once

#include "deck.h"
#include "game_of_war.h"

int main() {
    /*
     * Needs:
     *
     * declare the main deck
     * declare the two player decks
     * deal main deck to player decks
     * begin game loop
     */
    deck maindeck;
    deck player1(1);
    deck player2(2);
    int half = maindeck.size() /2;

    for (int k = 0; k < half; k++)
    {
        player1.seat_card(maindeck.deal());
        player2.seat_card(maindeck.deal());
    }

    //onward into the war
    int timeout = 0;
    do {
        war(player1, player2);
        timeout++;
    } while(player1.size() > 0 && player2.size() > 0 && timeout <= 1000);
    cout << "Player 1 deck size: " << player1.size() << " Player 2 deck size: " << player2.size() << endl;

    return 0;
}