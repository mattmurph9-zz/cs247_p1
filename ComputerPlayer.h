#ifndef _COMPUTERPLAYER_
#define _COMPUTERPLAYER_
#include "Player.h"
#include "Card.h"

class ComputerPlayer : public Player {
public:
	ComputerPlayer();
	void Discard(Card cardName) override;
	void PlayCard(Card cardName) override;
};

#endif