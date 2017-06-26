#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

void Game::addHumanPlayer() {
	players.push_back(std::shared_ptr<HumanPlayer>());
}

void Game::addComputerPlayer() {
	players.push_back(std::shared_ptr<ComputerPlayer>());
}