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
	float sizeIncrease;

	Fightable();

	virtual void battle(RenderWindow* window, Fightable* turn);
};