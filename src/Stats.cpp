#include "Stats.hpp"

Stats::Stats() {

}

Stats::Stats(int s, int v, int m, int a, int l) : st(s), vi(v), ma(m), ag(a), lu(l) {
	setStats(true);
	hp = hpMax;
	mana = manaMax;
	resetStats();
}

int Stats::giveEXP() {
	return st + 1.5 * vi + ma + 1.5 * ag + 3 * lu;
}

int Stats::getStatTotal() {
	return st + vi + ma + ag + lu;
}

int Stats::getLevel() {
	return round(quadratic(1, 1, 4 - getStatTotal() / 2));
}

void Stats::resetStats() {
	strength = st;
	vitality = vi;
	magic = ma;
	agility = ag;
	luck = lu;	
}

void Stats::setStats(bool override) {
	int h = 13 * vi + 24;
	int m = 8 * ma + 21;
	if (!override) {
		hp = ceil(1.0 * hp * h / hpMax);
		mana = ceil(1.0 * mana * m / manaMax);
	}
	hpMax = h;
	manaMax = m;
}