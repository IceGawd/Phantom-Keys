#pragma once

#include "utils.hpp"

class Stats {
	int st;
	int vi;
	int ma;
	int ag;
	int lu;
	int ap_max;

public:
	int hp;
	int hpMax;
	int mana;
	int manaMax;
	int ap;
	int apMax;

	int strength;
	int vitality;
	int magic;
	int agility;
	int luck;

	int accuracybonus;
	int evasionbonus;
	double damagebonus;
	double rangebonus;
	double damagetaken;
	double critchancebonus;
	double critincrease;

	Stats();
	Stats(int s, int v, int m, int a, int l, int ap);
	int giveEXP();
	int getStatTotal();
	int getLevel();
	void resetStats();
	void setStats(bool override = false);
};