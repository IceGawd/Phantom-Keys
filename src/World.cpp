#include "World.hpp"

World::World(RenderWindow& window, Player* player, vector<EnemyType*> enemyTypes, map<string, map<char, Mix_Chunk*>>& textNoise) {
	areas["ruins"] = new Area(window, "./res/Ruins/Ruins.tmx", enemyTypes, "res/gfx/Backgrounds/Ruins.png", textNoise);

	switchArea("ruins", player);
}

void World::switchArea(string s, Player* player) {
	current = areas[s];
	// cout << "preplace\n";
	current->placePlayer(player);
	// cout << "postplace\n";
};