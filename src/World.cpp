#include "World.hpp"

World::World(RenderWindow& window, Player* player) {
	areas["ruins"] = new Area(window, "./res/Ruins/Ruins.tmx");

	switchArea("ruins", player);
}

void World::switchArea(string s, Player* player) {
	current = areas[s];
	current->placePlayer(player);
};