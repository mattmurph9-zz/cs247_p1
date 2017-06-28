#include "Player.h"

void Player::GetCards(int player, Deck deck) {
	for (int i = 0; i < 13; i++) {
		Card* card = deck.GetCardAt(player * 13 + i);
		int rank = card->rank().rank();
		int suit = card->suit().suit();
		if (rank==6&&suit==3) {
			sevenSpade_ = true;
		}
		hand.push_back(card);
	}
}

std::vector<Card> Player::getDiscards() {
	return discards;
}