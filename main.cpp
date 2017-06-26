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
	void shuffle();
	void print();
};

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
	std::vector<Card> LegalPlays();
	virtual void Discard(Card cardName)=0; //ComputerPlayer will always discard first card, HumanPlayer can choose which card to discard
	virtual void PlayCard(Card cardName)=0; //ComputerPlayer will always play first legal card, HumanPlayer can choose among legal plays
private:
	std::vector<Card> hand;
};

class HumanPlayer : public Player {
public:
	HumanPlayer();
	void Discard(Card cardName) override;
	void PlayCard(Card cardName) override;
};

class ComputerPlayer : public Player {
public:
	ComputerPlayer();
	void Discard(Card cardName) override;
	void PlayCard(Card cardName) override;
};

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