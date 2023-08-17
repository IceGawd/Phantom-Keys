#pragma once

#include "RenderWindow.hpp"
#include "PartyMember.hpp"

struct BattleOptions : public Entity {
	Entity* select;
	PartyMember* pm;
	
	int selection = 0;
	int topY = 0;
	double scalingSize = 1;

	vector<string> options;

	bool prevUp = false;
	bool prevDown = false;
	bool prevEnter = false;

	BattleOptions(RenderWindow& window);
	virtual void customDraw(RenderWindow* window);
};

void boIncrement(void* passingArgument);
void boDecrement(void* passingArgument);
void boSelect(void* passingArgument);