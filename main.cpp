#include "Game.h"

void playStraights()
{	
	Game gameInstance;
	gameInstance.startGame();
}

int main(int argc, char* argv[]) 
{
	// optional integer for seeding the rng
	if (argc == 2) {
		setSeed(atoi(argv[1]));
	}
	playStraights();
}