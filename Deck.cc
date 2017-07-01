#include <random>
#include "Deck.h"

Card* Deck::GetCardAt(int index) {
	return cards_[index];
}

int seed = 0;

void Deck::shuffle() {
	static std::mt19937 rng(seed);

	int n = Deck::CARD_COUNT;

	while (n > 1) {
		int k = (int)(rng() % n);
		--n;
		Card *c = cards_[n];
		cards_[n] = cards_[k];
		cards_[k] = c;
	} // while
} // shuffle

void Deck::print() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 12; j++) {
			std::cout << *cards_[i * 13 + j] << " ";
		}
		std::cout << *cards_[i * 13 + 12] << std::endl;
	}
}

Deck::Deck() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			Card::Rank rank = j;
			Card::Suit suit = i;
			Card* newCard = new Card(rank, suit);
			this->cards_.push_back(newCard);
		}
	}
}

void setSeed(int s) {
	seed = s;
}