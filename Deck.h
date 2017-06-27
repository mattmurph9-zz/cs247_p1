#ifndef _DECK_
#define _DECK_
#include <vector>
#include <memory>
#include "Card.h"
#include "Player.h"

class Deck {
private:
	const int CARD_COUNT = 52;
	std::vector<Card*> cards_;
public:
	Deck();
	Card* GetCardAt(int index);
	void shuffle();
	void print();
	void deal(std::vector<std::shared_ptr<Player>> players);
};

#endif