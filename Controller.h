#ifndef _CONTROLLER_
#define _CONTROLLER_

#include <vector>
#include <memory>
#include "Command.h"
#include "Card.h"

class Round;
class Player;

class Controller {
private:
	static char getSuitChar(int suit);
public:
	static void printCards(std::vector<Card> cards);
	static void printRanks(std::vector<Card> cards);
	static void printStartTurn(Round roundInstance, std::vector<Card> hand, std::vector<Card> legalPlays);
	static Command queryCommand(Round roundInstance);
};

#endif