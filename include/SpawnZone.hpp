#pragma once

#include "Enemy.hpp"

struct SpawnZone {
	int spawned = 0;
	vector<EnemyType*> enemies;

	SpawnZone(vector<EnemyType*> e);
	void spawnEnemies(vector<GameObject*>& entities);
};