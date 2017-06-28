#ifndef _GAME_
#define _GAME_

#include <vector>
#include <memory>
#include "Player.h"

/**
 * Class to hold all overall game logic-related attributes such as players, rounds, the deck
 */
class Game {
private:
	std::vector<std::shared_ptr<Player>> players;
	void initPlayers();
	void addHumanPlayer();
	void addComputerPlayer();
public:
	void startGame();
	std::shared_ptr<Player> GetPlayer(int playerNum);
};

#endif