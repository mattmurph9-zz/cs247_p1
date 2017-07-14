#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_
#include "Player.h"
#include "Card.h"

class HumanPlayer : public Player {
public:
	HumanPlayer(int id_);
	bool queryTurn(Round &roundInstance, std::vector<Card> legalPlays) override;
};

#endif