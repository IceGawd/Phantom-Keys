#include "BuffMove.hpp"

BuffMove::BuffMove(string n, float d, int m, bool p, bool se, int a, vector<Tag> t, vector<KeyFrame> k, vector<pair<int, NoteType>> sn, vector<Buff> ta, bool tet, int h) : Move(n, d, m, p, se, a, t, k, sn, tet, h) {
	toAttackers = ta;
}