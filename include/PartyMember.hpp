#pragma once

#include "Fightable.hpp"

struct PartyMember : public Fightable {
	virtual void battle(RenderWindow* window, Fightable* turn, vector<GameObject*>& battleEntities);
	void doAttack(RenderWindow* window, Fightable* enemy, vector<GameObject*>& battleEntities);
};