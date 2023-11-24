#pragma once

#include "Buff.hpp"
#include "Move.hpp"

struct BuffMove : public Move {
	vector<Buff> toAttackers;
// 	vector<Buff> toSelf;
//	vector<Buff> inflicts;

	BuffMove(string n, float d, int m, bool p, bool se, int a, vector<Tag> t, vector<KeyFrame> k, vector<Buff> ta, bool tet = true, int h = 1);
};