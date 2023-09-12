#pragma once

#include "Fightable.hpp"

struct DamageNumber : public GameObject {
	const float FRICTION = 0.9;
	const int GRAVITY = 1;
	const int LIFEMAX = 60;
	int number;
	int life = LIFEMAX;

	DamageNumber(RenderWindow* window, int n, Fightable* gotHit);
	virtual bool draw(RenderWindow* window, World* world, vector<GameObject*>& entities);
};
