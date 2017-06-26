#include "ComputerPlayer.h"

void ComputerPlayer::Discard(Card cardName) {
	//ComputerPlayer must always discard first card in hand
	hand.erase(hand.begin() + 0);
}