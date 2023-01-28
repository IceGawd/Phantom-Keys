#pragma once

#include "Stats.hpp"
#include "GameObject.hpp"
#include "Move.hpp"

struct Fightable : public GameObject {
	Stats stats;
	vector<Move> moves;

	Fightable();
};