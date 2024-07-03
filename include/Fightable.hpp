#pragma once

#include <vector>

#include "Stats.hpp"
#include "Collideable.hpp"

class Move;
class Buff;

struct Fightable : public Collideable {
	Stats stats;
	vector<Move*> moves;
	vector<Buff*> activeBuffs;
	Move* moveEntered = nullptr;
	Fightable* target = nullptr;

	int battleX;
	int battleY;
	int battleOriginX;
	int battleOriginY;
	float sizeIncrease;

	vector<Move*> exhaustQueue;

	Fightable();

	virtual void battle(RenderWindow* window, Fightable* turn, vector<GameObject*>& battleEntities);
	void addToExhaustQueue(Move* move);
	float getExhaust(Move* move);
};