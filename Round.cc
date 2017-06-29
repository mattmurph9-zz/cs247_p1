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

/**
 * Prints ordered sequence of all the ranks in that suit (e.g., 6 7 8 9 T J Q) that have already been
 * played.
 */
void Round::printSuitPlayed(int suit) {
	std::vector<Card> toPrint;
	switch (suit) {
	case 0:
		toPrint = clubsPlayed;
		break;
	case 1:
		toPrint = diamondsPlayed;
		break;
	case 2:
		toPrint = heartsPlayed;
		break;
	case 3:
		toPrint = spadesPlayed;
		break;
	}
	for (int i = 0; i < toPrint.size(); i++) {
		std::cout << " " << toPrint[i].rank().rank();
	}
}

void Round::printStatus() {
	std::cout << "Cards on the table:" << std::endl
		<< "Clubs:"; printSuitPlayed(0); std::cout << std::endl
		<< "Diamonds:"; printSuitPlayed(1); std::cout << std::endl
		<< "Hearts:"; printSuitPlayed(2); std::cout << std::endl
		<< "Spades:"; printSuitPlayed(3); std::cout << std::endl;
}