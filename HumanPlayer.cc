#include "HumanPlayer.h"

void HumanPlayer::Discard(Card card) {
	for (int i = 0; i < hand.size(); i++) {
		if (*hand[i] == card) {
			hand.erase(hand.begin() + i);
		}
	}
}

void HumanPlayer::PlayCard(Card card) {

}