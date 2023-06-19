#pragma once

#include "Player.hpp"
#include "EnemyType.hpp"

struct Enemy : public Fightable {
	Player* player; // Player to chase
	EnemyType* et;
	bool passive = true;
	float speed = 0;
	float angle = 0;
	float angle_speed = 0;
	float homex;
	float homey;
};