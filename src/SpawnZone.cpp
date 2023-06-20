#include "SpawnZone.hpp"

SpawnZone::SpawnZone(SDL_Rect z, vector<EnemyType*> e) {
	zone = z;
	enemies = e;
}

void SpawnZone::spawnEnemies(RenderWindow* window, Player* player, vector<GameObject*>& entities) {
	if (spawned < 3 && random() > 0.99) {
		spawned++;
		EnemyType* et = enemies[(int) (random() * enemies.size())];
		int x = (int) (random() * zone.w + zone.x);
		int y = (int) (random() * zone.h + zone.y);
		Enemy* e = new Enemy(window, et, x, y, player);
		entities.push_back(e);
		dudes.push_back(e);
	}
}