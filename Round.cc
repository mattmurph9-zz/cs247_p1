#include "Round.h"
#include "Deck.h"
#include <ostream>

Round::Round(std::vector<std::shared_ptr<Player>> gamePlayers) :players(gamePlayers) {}

void Round::startRound() {
	// general play begins
	//find who has 7S
	int playerToStart;
	for (int i = 0; i < players.size(); i++) {
		if (players[i]->sevenSpade() == true) {
			playerToStart = i;
		}
	}
	std::cout << "A new round begins. It's player " << playerToStart << "'s turn to play." << std::endl;
	// game ends when all 52 cards are played, ie 13 passes of four plays
	for (int i = 0; i < 13; i++) {
		for (int j = 0, z = players.size(); j < z; j++) {
			int currentPlayerI = (playerToStart + j) % z;
			std::shared_ptr<Player> currentPlayer = players[currentPlayerI];
			//assume player is human: print current state of round
			printStatus();
			// find out what player wants to do
			std::vector<Card> legalPlays;
			if (currentPlayerI == playerToStart) {
				legalPlays.push_back(Card(Card::Rank::SEVEN, Card::Suit::SPADE));
			} else {
				legalPlays = computeLegalPlays(currentPlayer->getHand());
			}
			currentPlayer->queryTurn(legalPlays);
		}
	}
	// the round is over

}

/**
 * Checks hand for legal plays *NOT* including 7S
 */
std::vector<Card> Round::computeLegalPlays(std::vector<Card> hand) {
	std::vector<Card> legalPlays;
	for (int i = 0; i < hand.size(); i++) {
		// take the card's suit, check if the -+ 1 rank has been played
		int suit = hand[i].suit().suit();
		std::vector<Card> suitsPlayed = cardsPlayed[suit];
		for (int j = 0; j < suitsPlayed.size(); j++) {
			if (abs(suitsPlayed[j].rank().rank() - hand[i].rank().rank()) == 1) {
				addUniqueCard(legalPlays, hand[i]);
			}
		}
		// check if other suits of the rank have been played
		if (checkRankPlayed(hand[i])) {
			addUniqueCard(legalPlays, hand[i]);
		}
	}
	return legalPlays;
}

void Round::addUniqueCard(std::vector<Card>& cards, Card card) {
	bool hasCard = false;
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i] == card) {
			hasCard = true;
			break;
		}
	}
	if (!hasCard) {
		cards.push_back(card);
	}
}

/**
 * Checks if other suits of the rank have been played
 */
bool Round::checkRankPlayed(Card card) {
	int suit = card.suit().suit();
	int rank = card.rank().rank();
	for (int i = 0; i < Card::Suit::MAX_SUIT; i++) {
		if (suit != i) {
			std::vector<Card> suitsPlayed = cardsPlayed[i];
			for (int j = 0; j < suitsPlayed.size(); j++) {
				if (suitsPlayed[j].rank().rank() == rank) {
					return true;
				}
			}
		}
	}
	return false;
}

/**
 * Prints ordered sequence of all the ranks in that suit (e.g., 6 7 8 9 T J Q) that have already been
 * played.
 */
void Round::printSuitPlayed(int suit) {
	if (cardsPlayed.size() > 0) {
		std::vector<Card> toPrint = cardsPlayed[suit];
		for (int i = 0; i < toPrint.size(); i++) {
			std::cout << " " << toPrint[i].rank().rank();
		}
	}
}

void Round::printStatus() {
	std::cout << "Cards on the table:" << std::endl
		<< "Clubs:"; printSuitPlayed(0); std::cout << std::endl
		<< "Diamonds:"; printSuitPlayed(1); std::cout << std::endl
		<< "Hearts:"; printSuitPlayed(2); std::cout << std::endl
		<< "Spades:"; printSuitPlayed(3); std::cout << std::endl;
}