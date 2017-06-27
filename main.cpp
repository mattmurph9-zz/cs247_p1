#include <iostream>
#include <string>
#include <vector>
#include "Deck.h"
#include "Game.h"

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

	//dealing cards
	deck.deal(gameInstance.players());

}

int main(int argc, char* argv[]) 
{
	playStraights();
}