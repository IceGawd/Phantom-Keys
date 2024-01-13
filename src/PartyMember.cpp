#include "PartyMember.hpp"
#include "Move.hpp"

void PartyMember::battle(RenderWindow* window, Fightable* turn, vector<GameObject*>& battleEntities) {
	if (turn == this) {
		if (moveEntered != nullptr && window->turnstate != ANIMATION && window->turnstate != RHYTHM) {
			// cout << "PM\n";
			if (moveEntered->selectEnemy) {
				window->turnstate = SELECTENEMY;
			}
			else {
				doAttack(window, (Fightable*) window->enemyTeam.at((int) (window->enemyTeam.size() * random())), battleEntities);
			}
		}
	}
	Fightable::battle(window, turn, battleEntities);
}

void PartyMember::doAttack(RenderWindow* window, Fightable* enemy, vector<GameObject*>& battleEntities) {
	// moveEntered->dealDamage(window, this, enemy, battleEntities);
	// moveEntered = nullptr;
	target = enemy;
	if (moveEntered->physical) {
		window->turnstate = ANIMATION;
	}
	else {
		// cout << "RHYTHM\n";
		window->turnstate = RHYTHM;
	}
}