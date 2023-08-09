#pragma once

#include "RenderWindow.hpp"

struct BattleOptions : public Entity {
	Entity* select;

	int selection = 0;
	int topY = 0;
	double scalingSize = 1;

	vector<string> options;

	bool prevUp = false;
	bool prevDown = false;

	BattleOptions(RenderWindow& window);
	void arrowChange(RenderWindow* window, SDL_Scancode key, bool* direction, int change);
	virtual void customDraw(RenderWindow* window);
};
