#pragma once

#include "utils.hpp"

class Stats {
	int st;
	int vi;
	int ma;
	int ag;
	int lu;

public:
	int hp;
	int hpMax;
	int mana;
	int manaMax;

	int strength;
	int vitality;
	int magic;
	int agility;
	int luck;

	Stats();
	Stats(int s, int v, int m, int a, int l);
	int giveEXP();
	int getStatTotal();
	int getLevel();
	void resetStats();
	void setStats(bool override = false);
};