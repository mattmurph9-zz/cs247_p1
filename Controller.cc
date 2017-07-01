#include <iostream>
#include "Controller.h"
#include "Round.h"
#include "Player.h"

//0->c, 1->d, 2->h, 3->s
char Controller::getSuitChar(int suit) {
	switch (suit) {
	case 0:
		return 'C';
	case 1:
		return 'D';
	case 2:
		return 'H';
	case 3:
		return 'S';
	}
}

void Controller::printCards(std::vector<Card> cards) {
	for (int i = 0; i < cards.size(); i++) {
		std::cout << " " << cards[i].rank().rank() << getSuitChar(cards[i].suit().suit());
	}
}

void Controller::printRanks(std::vector<Card> cards) {
	for (int i = 0; i < cards.size(); i++) {
		std::cout << " " << cards[i].rank().rank();
	}
}

void Controller::printStartTurn(Round roundInstance, std::vector<Card> hand, std::vector<Card> legalPlays) {
	// prints round status
	roundInstance.printStatus();
	// prints player hand and legal plays
	std::cout << "Your hand:"; printCards(hand); std::cout << std::endl
		<< "Legal plays:"; printCards(legalPlays); std::cout << std::endl;
}

Command Controller::queryCommand(Round roundInstance) {
	// waits for user input command
	Command c;
	std::cin >> c;
	switch (c.type) {
	case Command::Type::DECK:
		roundInstance.getDeck().print();
		break;
	case Command::Type::QUIT:
		exit(0);
		break;
	case Command::Type::RAGEQUIT:
		break;
	}
	return c;
}

