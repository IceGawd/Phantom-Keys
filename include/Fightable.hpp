#pragma once

#include "Stats.hpp"
#include "Collideable.hpp"

class Move;
class Buff;

struct Fightable : public Collideable {
	Stats stats;
	vector<Move*> moves;
	vector<Buff*> activeBuffs;

	int battleX;
	int battleY;
	int battleOriginX;
	int battleOriginY;
	float sizeIncrease;

	Fightable();

	virtual void battle(RenderWindow* window, Fightable* turn, vector<GameObject*>& battleEntities);
};