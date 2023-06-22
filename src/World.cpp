#include "World.hpp"

World::World(RenderWindow& window, Player* player, vector<EnemyType*> enemyTypes) {
	areas["ruins"] = new Area(window, "./res/Ruins/Ruins.tmx", enemyTypes, "res/gfx/Backgrounds/Ruins.png");

	switchArea("ruins", player);
}

void World::switchArea(string s, Player* player) {
	current = areas[s];
	current->placePlayer(player);
};