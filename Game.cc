#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

void Game::addHumanPlayer() {
	players_.push_back(std::shared_ptr<HumanPlayer>());
}

void Game::addComputerPlayer() {
	players_.push_back(std::shared_ptr<ComputerPlayer>());
}

std::vector<std::shared_ptr<Player>> Game::players()
{
	return players_;
}
