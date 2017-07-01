#include "ComputerPlayer.h"
#include "Round.h"

/**
 * Handles player logic to decide what to do. always returns true since computers don't quit
 */
bool ComputerPlayer::queryTurn(Round roundInstance, std::vector<Card> legalPlays) {
	if (legalPlays.empty()) {
		Discard(*hand.front());
	} else {
		play(roundInstance, legalPlays.front());
	}
	return true;
}