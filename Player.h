#ifndef _PLAYER_
#define _PLAYER_
#include <vector>
#include "Card.h"
#include "Deck.h"

class Round;

class Player {
private:
	int score = 0;
	bool sevenSpade_ = false;
	void removeFromHand(Card card);
public:
	//Player();
	bool sevenSpade() { return sevenSpade_; }
	void GetCards(int i, Deck deck);
	std::vector<Card> getDiscards();
	virtual bool queryTurn(Round roundInstance, std::vector<Card> legalPlays) = 0;	// returns false if the turn did not complete (ragequit)
	std::vector<Card> getHand();
protected:
	std::vector<Card*> hand;
	std::vector<Card> discards;
	void Discard(Card card);
	void play(Round roundInstance, Card card);
};

#endif
