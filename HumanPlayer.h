#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_
#include "Player.h"
#include "Card.h"

class HumanPlayer : public Player {
public:
	//HumanPlayer();
	//void Discard(Card card) override;
	//void PlayCard(Card card) override;
	void queryTurn(Round roundInstance, std::vector<Card> legalPlays) override;
};

#endif