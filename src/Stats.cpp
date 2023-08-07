#include "Stats.hpp"

Stats::Stats() {

}

Stats::Stats(int s, int v, int m, int a, int l, int ap) : st(s), vi(v), ma(m), ag(a), lu(l), ap_max(ap) {
	setStats(true);
	hp = hpMax;
	mana = manaMax;
	apMax = ap_max;
	resetStats();
}

int Stats::giveEXP() {
	return st + 1.5 * vi + ma + 1.5 * ag + 3 * lu;
}

int Stats::getStatTotal() {
	return st + vi + ma + ag + lu;
}

int Stats::getLevel() {
	return round(quadratic(1, 1, (4 - getStatTotal()) / 2));
}

void Stats::resetStats() {
	strength = st;
	vitality = vi;
	magic = ma;
	agility = ag;
	luck = lu;

	accuracybonus = 1000;
	evasionbonus = 1000;
	damagebonus = 1;
	rangebonus = 1;
	damagetaken = 1;
	critchancebonus = 1;
	critincrease = 2;
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