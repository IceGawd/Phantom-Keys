#pragma once

#include "RenderWindow.hpp"
#include "PartyMember.hpp"

struct BattleOptions {
	Entity* mainMenu;
	Entity* fightOptions;
	Entity* select;
	PartyMember* pm;
	
	int selection = 0;
	double scalingSizeMain = 1.0;
	double scalingSizeFight = 1.0;

	vector<string> options;

	bool prevUp = true;
	bool prevLeft = true;
	bool prevDown = true;
	bool prevRight = true;
	bool prevEnter = true;

	BattleOptions(RenderWindow& window);
	void makeMaxWidth(Entity*& object, double& scalingSize, SDL_Texture* texture);
	void customDraw(RenderWindow* window);
	void selectionLimiting();
};

void boIncrement(vector<void*> passingArgument);
void boDecrement(vector<void*> passingArgument);
void boUp(vector<void*> passingArgument);
void boDown(vector<void*> passingArgument);
void boSelect(vector<void*> passingArgument);
void boMainOptionSelect(vector<void*> passingArgument);