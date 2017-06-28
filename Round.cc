#include "Round.h"
#include "Deck.h"
#include <ostream>

Round::Round(std::vector<std::shared_ptr<Player>> gamePlayers) :players(gamePlayers) {}

void Round::startRound() {
	// general play begins
	//find who has 7S
	int playerToStart;
	for (int i = 0; i < 4; i++) {
		if (players[i]->sevenSpade() == true) {
			playerToStart = i;
		}
	}
	std::cout << "A new round begins. It's player " << playerToStart << "'s turn to play." << std::endl;
	// the round is over

}