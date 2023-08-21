#include "PartyMember.hpp"
#include "Move.hpp"

void PartyMember::battle(RenderWindow* window, Fightable* turn) {
	if (turn == this) {
		if (moveEntered != nullptr) {
			// cout << "PM\n";
			if (moveEntered->selectEnemy) {
				window->turnstate = SELECTENEMY;
			}
			else {
				doAttack(window, (Fightable*) window->enemyTeam.at((int) (window->enemyTeam.size() * random())));
			}
		}
	}
	Fightable::battle(window, turn);
}

void PartyMember::doAttack(RenderWindow* window, Fightable* enemy) {
	moveEntered->dealDamage(window, this, enemy);
	moveEntered = nullptr;
	window->turnstate = ENDTURN;
}