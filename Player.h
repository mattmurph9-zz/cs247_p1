#ifndef _PLAYER_
#define _PLAYER_
#include <vector>
#include "Card.h"
#include "Deck.h"

class Round;

class Player {
private:
	int id;
	int score = 0;
	bool sevenSpade_ = false;
	void removeFromHand(Card card);
public:
	int oldScore = 0;
	Player(int id_);
	bool sevenSpade() { return sevenSpade_; }
	void GetCards(int i, Deck deck);
	void SetScore(int i) { score = i; }
	int GetScore() { return score; }
	void SetDiscards(std::vector<Card> d) { discards = d; }
	std::vector<Card> getDiscards();
	void printDiscards();
	virtual bool queryTurn(Round &roundInstance, std::vector<Card> legalPlays) = 0;	// returns false if the turn did not complete (ragequit)
	std::vector<Card> getHand();
	void SetHand(std::vector<Card> h) { hand = h; }
	int GetID() { return id; }
protected:
	std::vector<Card> hand;
	std::vector<Card> discards;
	void Discard(Card card);
	void play(Round &roundInstance, Card card);
};

#endif
