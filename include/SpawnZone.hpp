#pragma once

#include "Enemy.hpp"
#include "utils.hpp"

struct SpawnZone {
	int spawned = 0;
	SDL_Rect zone;
	vector<EnemyType*> enemies;
	vector<Enemy*> dudes;

	SpawnZone(SDL_Rect z, vector<EnemyType*> e);
	void spawnEnemies(RenderWindow* window, Player* player, vector<GameObject*>& entities);
};