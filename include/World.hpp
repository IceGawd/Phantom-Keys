#pragma once

#include "Area.hpp"

struct World {
	Area* current;
	map<string, Area*> areas;

	World(RenderWindow& window, Player* player, vector<EnemyType*> enemyTypes);
	void switchArea(string s, Player* player);
};