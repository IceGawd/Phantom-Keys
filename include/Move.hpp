#pragma once

#include <vector>

#include "Fightable.hpp"
#include "utils.hpp"

using namespace std;

struct Move {
	string name;
	bool physical;
	float damage;
	int mana;
	int ap;
	bool selectEnemy;
	vector<Tag> tags;

	bool targetEnemyTeam;
	int hits;

	Move(string n, float d, int m, bool p, bool se, int a, vector<Tag> t, bool tet = true, int h = 1);

	virtual void dealDamage(RenderWindow* window, Fightable* attacker, Fightable* defender);
}; 