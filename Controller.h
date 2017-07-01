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
	static Command queryCommand(Round roundInstance, std::shared_ptr<Player> player, std::vector<Card> legalPlays);
};

#endif