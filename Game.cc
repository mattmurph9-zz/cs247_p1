#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

void Game::addHumanPlayer() {
	players.push_back(std::make_shared<HumanPlayer>());
}

void Game::addComputerPlayer() {
	players.push_back(std::make_shared<ComputerPlayer>());
}

std::shared_ptr<Player> Game::GetPlayer(int playerNum)
{
	return players[playerNum];
}
