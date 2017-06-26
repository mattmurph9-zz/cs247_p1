#include "Player.h"

void Player::GetCards(int player, Deck deck) {
	for (int i = 0; i < 13; i++) {
		hand.push_back(deck.GetCardAt(player * 13 + i));
	}
}