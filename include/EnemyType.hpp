#pragma once

#include "Stats.hpp"
#include "Move.hpp"

enum MOVEMENT_TYPE
{
	ACCELERATING, // Kinda like a SM64 Goomba
	SPRINT, // Quick start, speed decelerates to max speed
};

struct EnemyType {
	string name;
	Stats stats;
	vector<Move*> moves;
	float max_speed; // Maximum speed
	float passive_speed; // Passive speed
	float max_angle_speed; // Maximum change in angle per frame
	float passive_angle_speed; // Passive angle speed
	MOVEMENT_TYPE mt; // Type of Movement
	int sightradius; // Radius from home where player will get noticed
	int homeradius; // Radius from home where enemy is comfortable going
	bool homeloyalty; // Will the enemy change home after chasing player out of home zone or no?
	string path;
	int width;
	int height;

	EnemyType(string n, Stats s, vector<Move*> m, float ms, float ps, float mas, float pas, MOVEMENT_TYPE movementtype, int sr, int hr, bool h, string p, int wid, int hei);
};