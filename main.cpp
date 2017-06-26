#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include <random>

class Deck {
private:
	std::vector<Card*> cards_;
public:
	Deck();
	Card* GetCardAt(int index);
	void shuffle();
	void print();
};

Card* Deck::GetCardAt(int index) {
	return cards_[index];
}

int seed = 0;
const int CARD_COUNT = 52;

void Deck::shuffle() {
	static std::mt19937 rng(seed);

	int n = CARD_COUNT;

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
			std::cout << *cards_[i*13+j] << " ";
		}
		std::cout << *cards_[i*13+12] << std::endl;
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

class Player {
public:
	Player();
	std::vector<Card*> LegalPlays();
	void GetCards(int i, Deck deck);
	virtual void Discard(Card card)=0; //ComputerPlayer will always discard first card, HumanPlayer can choose which card to discard
	virtual void PlayCard(Card card)=0; //ComputerPlayer will always play first legal card, HumanPlayer can choose among legal plays
protected:
	std::vector<Card*> hand;
};

void Player::GetCards(int player, Deck deck) {
	for (int i = 0; i < 13; i++) {
		hand.push_back(deck.GetCardAt(player*13+i));
	}
}

class HumanPlayer : public Player {
public:
	HumanPlayer();
	void Discard(Card card) override;
	void PlayCard(Card card) override;
};

void HumanPlayer::Discard(Card card) {
	for (int i = 0; i < hand.size(); i++) {
		if (*hand[i] == card) {
			hand.erase(hand.begin() + i);
		}
	}
}

class ComputerPlayer : public Player {
public:
	ComputerPlayer();
	void Discard(Card cardName) override;
	void PlayCard(Card cardName) override;
};

void ComputerPlayer::Discard(Card cardName) {
	//ComputerPlayer must always discard first card in hand
	hand.erase(hand.begin() + 0);
}

void playStraights()
{	
	Deck deck;
	deck.shuffle();
	deck.print();
	std::string p1n, p2n, p3n, p4n;
	std::cout << "Is player 1 a human(h) or a computer(c)?"<<std::endl;
	std::cin >> p1n;
	std::cout << "Is player 2 a human(h) or a computer(c)?" << std::endl;
	std::cin >> p2n;
	std::cout << "Is player 3 a human(h) or a computer(c)?" << std::endl;
	std::cin >> p3n;
	std::cout << "Is player 4 a human(h) or a computer(c)?" << std::endl;
	std::cin >> p4n;

}

int main(int argc, char* argv[]) 
{
	playStraights();
}