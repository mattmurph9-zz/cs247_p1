#include <iostream>
#include <string>
#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Round.h"

void Game::startGame() {
	initPlayers();

	// deck is preserved throughout rounds. the shuffled deck from a round
	// is the starting deck for the next
	Deck deck;
	bool gameOver = false;
	while (!gameOver) {
		deck.shuffle();
		// deal
		for (int i = 0; i < 4; i++) {
			players[i]->GetCards(i, deck);
		}
		Round roundInstance(players, deck);
		roundInstance.startRound();
		for (int i = 0; i < 4; i++) {
			if (players[i]->GetScore() >= 80) {
				gameOver = true;
			}
		}
	}
	std::vector<int> winners = FindWinners();
	for (int i = 0; i < winners.size(); i++) {
		std::cout << "Player " << winners[i] + 1 << " wins!" << std::endl;
	}
}

void Game::initPlayers() {
	// instantiating players
	for (int i = 0; i < 4; i++) {
		std::string in;
		std::cout << "Is player " << i+1 << " a human(h) or a computer(c)?" << std::endl;
		std::cin >> in;
		if (in.compare("h") == 0) {
			addHumanPlayer();
		} else if (in.compare("c") == 0) {
			addComputerPlayer();
		}
	}
}

std::vector<int> Game::FindWinners()
{
	std::vector<int> winners;
	int min = 200;
	for (int i = 0; i < 4; i++) {
		if (players[i]->GetScore() <= min) {
			min = players[i]->GetScore();
		}
	}
	for (int i = 0; i < 4; i++) {
		if (players[i]->GetScore() == min) {
			winners.push_back(i);
		}
	}
	return winners;
}

void Game::addHumanPlayer() {
	int id = players.size();
	players.push_back(std::make_shared<HumanPlayer>(id));
}

void Game::addComputerPlayer() {
	int id = players.size();
	players.push_back(std::make_shared<ComputerPlayer>(id));
}

std::shared_ptr<Player> Game::GetPlayer(int playerNum)
{
	return players[playerNum];
}
