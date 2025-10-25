#pragma once

#include "Buff.hpp"
#include "Move.hpp"

struct BuffMove : public Move {
	vector<Buff> toAttackers;
// 	vector<Buff> toSelf;
//	vector<Buff> inflicts;

	BuffMove(string n, float d, int m, bool p, bool se, int a, vector<int> t, vector<KeyFrame> k, vector<pair<int, int>> sn, vector<Buff> ta, bool tet = true, int h = 1);
};