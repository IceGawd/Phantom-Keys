#pragma once

#include <map>

#include "Area.hpp"

using namespace std;

struct World {
	Area* current;
	map<string, Area*> areas;

	World(RenderWindow& window, Player* player, vector<EnemyType*> enemyTypes, map<string, map<char, Mix_Chunk*>>& textNoise);
	void switchArea(string s, Player* player);
};