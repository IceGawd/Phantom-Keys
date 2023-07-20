#include "PartyMember.hpp"
#include "Move.hpp"

bool PartyMember::battle(RenderWindow* window, Fightable* turn) {
	if (turn == this) {
		
	}

	return Fightable::battle(window, turn);
}