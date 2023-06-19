#include "EnemyType.hpp"

EnemyType::EnemyType(string n, Stats s, vector<Move*> m, float ms, float ps, float mas, float pas, MOVEMENT_TYPE movementtype, int sr, int hr, bool h) {
	name = n;
	stats = s;
	moves = m;
	max_speed = ms;
	passive_speed = ps;
	max_angle_speed = mas;
	passive_angle_speed = pas;
	mt = movementtype;
	sightradius = sr;
	homeradius = hr;
	homeloyalty = h;
}