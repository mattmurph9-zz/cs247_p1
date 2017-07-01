#ifndef _COMPUTERPLAYER_
#define _COMPUTERPLAYER_
#include "Player.h"
#include "Card.h"

class ComputerPlayer : public Player {
public:
	ComputerPlayer(int id_);
	//void Discard(Card cardName) override;
	//void PlayCard(Card cardName) override;
	bool queryTurn(Round roundInstance, std::vector<Card> legalPlays) override;
};

#endif