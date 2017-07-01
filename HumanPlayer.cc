#include <algorithm>
#include <ostream>
#include "HumanPlayer.h"
#include "Round.h"
#include "Command.h"
#include "Controller.h"

/**
 *Lets the user decide what play to make
 *@Return true if turn completed, else false (ragequit)
 */
bool HumanPlayer::queryTurn(Round roundInstance, std::vector<Card> legalPlays) {
	bool validPlayMade = false;
	while (!validPlayMade) {
	// request UI for command input
		Command playerCommand = Controller::queryCommand();
		std::vector<Card> playerHand = getHand();

		switch (playerCommand.type) {
		case Command::Type::PLAY:
			// if the play card is legal
			if (std::find(legalPlays.begin(), legalPlays.end(), playerCommand.card) != legalPlays.end()) {
				play(roundInstance, playerCommand.card);
				validPlayMade = true;
			} else {
				std::cout << "This is not a legal play." << std::endl;
			}
			break;
		case Command::Type::DISCARD:
			// can only discard if there are no legal moves to play and they have the card
			if (legalPlays.empty() &&
				std::find(playerHand.begin(), playerHand.end(), playerCommand.card) != playerHand.end()) {
				Discard(playerCommand.card);
				validPlayMade = true;
			} else {
				std::cout << "You have a legal play. You may not discard." << std::endl;
			}
			break;
		case Command::Type::RAGEQUIT:
			return false;
		}
	}
	return true;
}
