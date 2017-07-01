#ifndef _ROUND_
#define _ROUND_

#include <vector>
#include <memory>
#include "Card.h"
#include "Deck.h"

class Player;

class Round {
private:
	Deck deck;
	std::vector<std::shared_ptr<Player>> players;
	// cards played are stored in order (A 2 3 4). first ind is suit: 0->c, 1->d, 2->h, 3->s
	std::vector<std::vector<Card>> cardsPlayed;
	void printSuitPlayed(int suit);
	std::vector<Card> computeLegalPlays(std::vector<Card> hand);
	void addUniqueCard(std::vector<Card> & cards, Card card);
	bool checkRankPlayed(Card card);
public:
	Round(std::vector<std::shared_ptr<Player>> players, Deck deck);
	void startRound();
	void printStatus();
	void playCard(Card card);
	Deck getDeck();
};

#endif