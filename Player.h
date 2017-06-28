#ifndef _PLAYER_
#define _PLAYER_
#include <vector>
#include "Card.h"
#include "Deck.h"

class Player {
private:
	int score = 0;
	bool sevenSpade_ = false;
public:
	//Player();
	bool sevenSpade() { return sevenSpade_; }
	std::vector<Card*> LegalPlays();
	void GetCards(int i, Deck deck);
	std::vector<Card> getDiscards();
	virtual void Discard(Card card) = 0; //ComputerPlayer will always discard first card, HumanPlayer can choose which card to discard
	virtual void PlayCard(Card card) = 0; //ComputerPlayer will always play first legal card, HumanPlayer can choose among legal plays
protected:
	std::vector<Card*> hand;
	std::vector<Card> discards;
};

#endif
