#include <iostream>
#include <string>
#include "Deck.h"

void playStraights()
{	
	Deck deck;
	deck.shuffle();
	deck.print();
	std::string p1n, p2n, p3n, p4n;
	std::cout << "Is player 1 a human(h) or a computer(c)?"<<std::endl;
	std::cin >> p1n;
	std::cout << "Is player 2 a human(h) or a computer(c)?" << std::endl;
	std::cin >> p2n;
	std::cout << "Is player 3 a human(h) or a computer(c)?" << std::endl;
	std::cin >> p3n;
	std::cout << "Is player 4 a human(h) or a computer(c)?" << std::endl;
	std::cin >> p4n;

}

int main(int argc, char* argv[]) 
{
	playStraights();
}