#include "BuffMove.hpp"

BuffMove::BuffMove(string n, float d, int m, bool p, bool se, int a, vector<Tag> t, vector<Buff> ta, bool tet, int h) : Move(n, d, m, p, se, a, t, tet, h) {
	toAttackers = ta;
}