#ifndef _PLAYER_
#define _PLAYER_
#include <vector>
#include "Card.h"
#include "Deck.h"

class Player {
private:
	int score = 0;
	bool sevenSpade_ = false;
	//void Discard(Card card);
public:
	//Player();
	bool sevenSpade() { return sevenSpade_; }
	void GetCards(int i, Deck deck);
	std::vector<Card> getDiscards();
	void queryTurn(std::vector<Card> legalPlays);
	virtual void Discard(Card card) = 0; //ComputerPlayer will always discard first card, HumanPlayer can choose which card to discard
	virtual void PlayCard(Card card) = 0; //ComputerPlayer will always play first legal card, HumanPlayer can choose among legal plays
	std::vector<Card> getHand();
protected:
	std::vector<Card*> hand;
	std::vector<Card> discards;
	//virtual void queryDiscard();
};

#endif
