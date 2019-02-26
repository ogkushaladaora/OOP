//
// Daniel Ulinski
// war functions
// needs deck.h to work
//

#ifndef P1_WAR_GAME_OF_WAR_H
#define P1_WAR_GAME_OF_WAR_H

using std::cout;
using std::endl;

/*
 * Needs:
 *
 * take one card from each deck and compare face values
 * deck with higher value adds both cards to their deck
 * if there is a tie, recurse.
 */

void war(deck &player1, deck &player2)
{
    card p1(player1.deal());
    card p2(player2.deal());

    std::cout << p1.return_face() << " vs " << p2.return_face() << std::endl;

    if (p1.return_face() > p2.return_face()) {
        player1.seat_card(p1);
        player1.seat_card(p2);
        cout << "Player1 wins" << endl;
    }
    else if (p2.return_face() > p1.return_face()) {
        player2.seat_card(p1);
        player2.seat_card(p2);
        cout << "Player2 wins" << endl;
    }
    else {
        war(player1, player2);
        if (player1.size() > player2.size()) {
            player1.seat_card(p1);
            player1.seat_card(p2);
        }
        else if (player2.size() > player1.size()) {
            player2.seat_card(p1);
            player2.seat_card(p2);
        }
    }
}

#endif //P1_WAR_GAME_OF_WAR_H
