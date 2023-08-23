#pragma once

#include "Entity.hpp"

struct Selector {
	Entity* note;
	float angle = 0;
	bool snap = true;
	int selection = 0;
	int radius = 0;
	int xCenter = 0;
	int yCenter = 0;
	int radiusAim = 0;
	int xCenterAim = 0;
	int yCenterAim = 0;

	bool prevUp = true;
	bool prevLeft = true;
	bool prevDown = true;
	bool prevRight = true;
	bool prevEnter = true;

	bool enemyPoint = true;

	Selector(RenderWindow& window);
	void render(RenderWindow* window);
	Fightable* getSelected(RenderWindow* window);
};

void sIncrement(vector<void*> passingArgument);
void sDecrement(vector<void*> passingArgument);
void sEnter(vector<void*> passingArgument);
void sParty(vector<void*> passingArgument);
void sEnemy(vector<void*> passingArgument);