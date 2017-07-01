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


Command Controller::queryCommand(Round roundInstance, std::shared_ptr<Player> player, std::vector<Card> legalPlays) {
	// prints round status
	roundInstance.printStatus();
	// prints player hand and legal plays
	std::vector<Card> playerHand = player->getHand();
	std::cout << "Your hand:"; printCards(playerHand); std::cout << std::endl
		<< "Legal plays:"; printCards(legalPlays); std::cout << std::endl;
	// waits for user input command
	Command c;
	std::cin >> c;

	return c;
}

