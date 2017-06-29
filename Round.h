#ifndef _ROUND_
#define _ROUND_

#include <vector>
#include <memory>
#include "Player.h"
#include "Card.h"

class Round {
private:
	std::vector<std::shared_ptr<Player>> players;
	std::vector<Card> clubsPlayed;		// cards played are stored in order (A 2 3 4)
	std::vector<Card> diamondsPlayed;
	std::vector<Card> heartsPlayed;
	std::vector<Card> spadesPlayed;
	void queryPlayer(std::shared_ptr<Player> p);
	void printSuitPlayed(int suit);
public:
	Round(std::vector<std::shared_ptr<Player>> players);
	void startRound();
	void printStatus();
};

#endif