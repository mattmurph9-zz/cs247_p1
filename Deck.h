#ifndef _DECK_
#define _DECK_
#include <vector>
#include "Card.h"

class Deck {
private:
	const int CARD_COUNT = 52;
	std::vector<Card*> cards_;
public:
	Deck();
	Card* GetCardAt(int index);
	void shuffle();
	void print();
};

void setSeed(int s);

#endif