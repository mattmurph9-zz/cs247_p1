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

//void Player::Discard(Card card) {
//	discards.push_back(card);
//	// rank indexing starts at zero, but points start at 1
//	score += card.rank().rank() + 1;
//	// remove from hand
//	for (int i = 0; i < hand.size(); i++) {
//		if (*hand[i] == card) {
//			hand.erase(hand.begin() + i);
//		}
//	}
//}

void Player::queryTurn(std::vector<Card> legalPlays) {

}

std::vector<Card> Player::getDiscards() {
	return discards;
}

std::vector<Card> Player::getHand() {
	std::vector<Card> ret;
	for (int i = 0; i < hand.size(); i++) {
		ret.push_back(*hand[i]);
	}
	return ret;
}