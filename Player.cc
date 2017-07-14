#include "Player.h"
#include "Round.h"

Player::Player(int id_): id(id_) {}

void Player::GetCards(int player, Deck deck) {
	for (int i = 0; i < 13; i++) {
		Card* card = deck.GetCardAt(player * 13 + i);
		int rank = card->rank().rank();
		int suit = card->suit().suit();
		if (rank==6&&suit==3) {
			sevenSpade_ = true;
		}
		hand.push_back(*card);
	}
}

void Player::Discard(Card card) {
	discards.push_back(card);
	// rank indexing starts at zero, but points start at 1
	score += card.rank().rank() + 1;
	// remove from hand
	removeFromHand(card);
}

void Player::play(Round &roundInstance, Card card) {
	// plays to round
	roundInstance.playCard(card);
	// remove from hand
	removeFromHand(card);
}

void Player::removeFromHand(Card card) {
	for (int i = 0; i < hand.size(); i++) {
		if (hand[i] == card) {
			hand.erase(hand.begin() + i);
		}
	}
}

std::vector<Card> Player::getDiscards() {
	return discards;
}

void Player::printDiscards(){
	for (int i = 0; i < discards.size(); i++) {
		std::cout << " " << discards[i];
	}
	std::cout << std::endl;
}


std::vector<Card> Player::getHand() {
	std::vector<Card> ret;
	for (int i = 0; i < hand.size(); i++) {
		ret.push_back(hand[i]);
	}
	return ret;
}