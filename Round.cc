#include <ostream>
#include "Round.h"
#include "Player.h"
#include "Controller.h"

Round::Round(std::vector<std::shared_ptr<Player>> &gamePlayers, Deck deck) :players(&gamePlayers), deck(deck) {
	// initialize each suit's cards played
	for (int i = 0; i < Card::Suit::MAX_SUIT; i++) {
		cardsPlayed.push_back(std::vector<Card>());
	}
}

void Round::startRound() {
	// general play begins
	//find who has 7S
	int playerToStart;
	for (int i = 0; i < players->size(); i++) {
		if (players->at(i)->sevenSpade() == true) {
			playerToStart = i;
		}
	}
	std::cout << "A new round begins. It's player " << playerToStart << "'s turn to play." << std::endl;
	// round ends when all 52 cards are played, ie 13 passes of four plays
	for (int i = 0; i < 13; i++) {
		for (int j = 0, z = players->size(); j < z; j++) {
			int currentPlayerI = (playerToStart + j) % z;
			std::shared_ptr<Player> currentPlayer = players->at(currentPlayerI);

			// find out what player wants to do
			std::vector<Card> legalPlays;
			if (i == 0 && j == 0) {
				legalPlays.push_back(Card(Card::Rank::SEVEN, Card::Suit::SPADE));
			}
			else {
				legalPlays = computeLegalPlays(currentPlayer->getHand());
			}
			bool turnComplete = currentPlayer->queryTurn(*this, legalPlays);
			// in case of ragequit
			if (!turnComplete) {
				currentPlayer = players->at(currentPlayerI);
				currentPlayer->queryTurn(*this, legalPlays);
			}
		}
	}
	//output end of round stats
	for (int i = 0; i < 4; i++) {
		std::cout << "Player " << i + 1 << "'s discards:";
		players->at(i)->printDiscards();
		std::cout << "Player "<<i+1<<"'s score: "<<players->at(i)->oldScore<<" + "<< players->at(i)->GetScore() - players->at(i)->oldScore
			<<" = "<<players->at(i)->GetScore()<<std::endl;
		players->at(i)->oldScore = players->at(i)->GetScore();
	}
	// the round is over

}


/**
 * Checks hand for legal plays *NOT* including 7S
 */
std::vector<Card> Round::computeLegalPlays(std::vector<Card> hand) {
	std::vector<Card> legalPlays;
	for (int i = 0; i < hand.size(); i++) {
		//if card is a 7 it is automatically playable
		if (hand[i].rank().rank() == 6) {
			addUniqueCard(legalPlays, hand[i]);
		}
		// else take the card's suit, check if the -+ 1 rank has been played
		else {
			int suit = hand[i].suit().suit();
			std::vector<Card> cardsOfSuitPlayed = cardsPlayed[suit]; //suitsPlayed doesn't make sense
			for (int j = 0; j < cardsOfSuitPlayed.size(); j++) {
				if (abs(cardsOfSuitPlayed[j].rank().rank() - hand[i].rank().rank()) == 1) {
					addUniqueCard(legalPlays, hand[i]);
				}
			}
		}
	}
	return legalPlays;
}

/**
 * Helper for creating the list of legal plays
 */
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

void Round::playCard(Card card) {
	int suit = card.suit().suit();
	int rank = card.rank().rank();
	std::vector<Card> suitsPlayed = cardsPlayed[suit];
	// add card to appropriate suit played in order (insertion sort)
	int i = 0;
	while (i < suitsPlayed.size() && suitsPlayed[i].rank().rank() < rank ) {
		i++;
	}
	suitsPlayed.insert(suitsPlayed.begin() + i, card);
	cardsPlayed[suit] = suitsPlayed;
}

Deck Round::getDeck() {
	return deck;
}

void Round::Ragequit(int playerNum)
{
	//convert Player playerNum to computer
	//first make new computer player
	std::shared_ptr<Player> newPlayer = std::make_shared<ComputerPlayer>(playerNum);
	newPlayer->oldScore = players->at(playerNum)->oldScore;
	newPlayer->SetScore(players->at(playerNum)->GetScore());
	newPlayer->SetDiscards(players->at(playerNum)->getDiscards());
	newPlayer->SetHand(players->at(playerNum)->getHand());
	players->at(playerNum) = newPlayer;
}

/**
 * Prints ordered sequence of all the ranks in that suit (e.g., 6 7 8 9 T J Q) that have already been
 * played.
 */
void Round::printSuitPlayed(int suit) {
	std::vector<Card> toPrint = cardsPlayed[suit];
	Controller::printRanks(toPrint);
}

void Round::printStatus() {
	std::cout << "Cards on the table:" << std::endl
		<< "Clubs:"; printSuitPlayed(0); std::cout << std::endl
		<< "Diamonds:"; printSuitPlayed(1); std::cout << std::endl
		<< "Hearts:"; printSuitPlayed(2); std::cout << std::endl
		<< "Spades:"; printSuitPlayed(3); std::cout << std::endl;
}
