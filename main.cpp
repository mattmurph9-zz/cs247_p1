#include <iostream>
#include <string>
#include <vector>
#include "Deck.h"
#include "Game.h"
#include "Player.h"

void playStraights()
{	
	Deck deck;
	deck.shuffle();
	deck.print();

	Game gameInstance;
	// instantiating players
	for (int i = 0; i < 4; i++) {
		std::string in;
		std::cout << "Is player " << i << " a human(h) or a computer(c)?" <<std::endl;
		std::cin >> in;
		if (in.compare("h") == 0) {
			gameInstance.addHumanPlayer();
		} else if (in.compare("c") == 0) {
			gameInstance.addComputerPlayer();
		}
	}
	for (int i = 0; i < 4; i++) {
		gameInstance.GetPlayer(i)->GetCards(i,deck);
	}
	//find who has 7S
	int playerToStart;
	for (int i = 0; i < 4; i++) {
		if (gameInstance.GetPlayer(i)->sevenSpade() == true) {
			playerToStart = i;
		}
	}
	std::cout << "A new round begins. It's player "<<playerToStart<<"'s turn to play."<<std::endl;
}

int main(int argc, char* argv[]) 
{
	// optional integer for seeding the rng
	if (argc == 2) {
		setSeed(atoi(argv[1]));
	}
	playStraights();
}