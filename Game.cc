#include <iostream>
#include <string>
#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Round.h"

void Game::startGame() {
	initPlayers();

	Round roundInstance(players);
	roundInstance.startRound();
}

void Game::initPlayers() {
	// instantiating players
	for (int i = 0; i < 4; i++) {
		std::string in;
		std::cout << "Is player " << i << " a human(h) or a computer(c)?" << std::endl;
		std::cin >> in;
		if (in.compare("h") == 0) {
			addHumanPlayer();
		} else if (in.compare("c") == 0) {
			addComputerPlayer();
		}
	}
}

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
