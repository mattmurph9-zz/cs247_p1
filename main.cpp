#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

class Deck {
private:
	std::vector<Card> deck;
public:
	Deck();
};

Deck::Deck() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			Card::Rank rank = j;
			Card::Suit suit = i;
			Card newCard = Card(rank, suit);
			this->deck.push_back(newCard);
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
	std::string p1n, p2n, p3n, p4n;
	std::cout << "Is player 1 a human(h) or a computer(c)?"<<std::endl;
	std::cin >> p1n;
	if (p1n == "h") {
		HumanPlayer p1;
	}
	else if (p1n == "c") {
		ComputerPlayer p1;
	}
	std::cout << "Is player 2 a human(h) or a computer(c)?" << std::endl;
	std::cin >> p2n;
	if (p2n == "h") {
		HumanPlayer p2;
	}
	else if (p1n == "c") {
		ComputerPlayer p2;
	}
	std::cout << "Is player 3 a human(h) or a computer(c)?" << std::endl;
	std::cin >> p3n;
	if (p3n == "h") {
		HumanPlayer p3;
	}
	else if (p1n == "c") {
		ComputerPlayer p3;
	}
	std::cout << "Is player 4 a human(h) or a computer(c)?" << std::endl;
	std::cin >> p4n;
	if (p4n == "h") {
		HumanPlayer p4;
	}
	else if (p4n == "c") {
		ComputerPlayer p4;
	}

}

int main(int argc, char* argv[]) 
{
	playStraights();
}