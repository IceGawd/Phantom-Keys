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

	bool prevUp = false;
	bool prevLeft = false;
	bool prevDown = false;
	bool prevRight = false;
	bool prevEnter = false;

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