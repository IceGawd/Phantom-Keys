#pragma once

#include "utils.hpp"
#include "Player.hpp"
#include "EnemyType.hpp"

class SpawnZone;

struct Enemy : public Fightable {
	Player* player; // Player to chase
	EnemyType* et;
	SpawnZone* zone;
	bool passive = true;
	float speed = 0;
	float movement_angle = 0;
	float angle_speed = 0;
	float homex = 0;
	float homey = 0;

	Enemy(RenderWindow* window, EnemyType* e, int x, int y, Player* p);
	virtual bool draw(RenderWindow* window, World* world, vector<GameObject*>& entities);
	virtual void battle(RenderWindow* window, Fightable* turn);
};