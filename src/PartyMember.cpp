#include "PartyMember.hpp"
#include "Move.hpp"

void PartyMember::battle(RenderWindow* window, Fightable* turn) {
	if (turn == this) {
		if (moveEntered != nullptr) {
			cout << "PM\n";
			moveEntered->dealDamage(window, this, (Fightable*) window->enemyTeam.at((int) (window->enemyTeam.size() * random())));
			moveEntered = nullptr;
			window->turnstate = ENDTURN;

		}
	}
	Fightable::battle(window, turn);
}