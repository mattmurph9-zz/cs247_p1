#ifndef _ROUND_
#define _ROUND_

#include <vector>
#include <memory>
#include "Player.h"

class Round {
private:
	std::vector<std::shared_ptr<Player>> players;
public:
	Round(std::vector<std::shared_ptr<Player>> players);
	void startRound();
};

#endif