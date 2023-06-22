#include "SpawnZone.hpp"

SpawnZone::SpawnZone(SDL_Rect z, vector<EnemyType*> e) {
	zone = z;
	enemies = e;
}

// THIS IS WHERE ENEMIES GET DELETED
void SpawnZone::spawnEnemies(RenderWindow* window, Player* player, vector<GameObject*>& entities) {
	SDL_Rect a = player->getRect();
	SDL_Rect b;	
	if (spawned < 3 && random() > 0.99 && SDL_IntersectRect(&zone, &a, &b) != SDL_TRUE) {
		spawned++;
		EnemyType* et = enemies[(int) (random() * enemies.size())];
		int x = (int) (random() * zone.w + zone.x);
		int y = (int) (random() * zone.h + zone.y);
		Enemy* e = new Enemy(window, et, x, y, player);
		e->zone = this;
		entities.push_back(e);
		dudes.push_back(e);
	}
}