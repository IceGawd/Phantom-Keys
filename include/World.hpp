#pragma once

#include "Area.hpp"

struct World {
	Area* current;
	map<string, Area*> areas;

	World(RenderWindow& window, Player* player);
	void switchArea(string s, Player* player);
};