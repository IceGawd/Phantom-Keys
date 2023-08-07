#include "Move.hpp"

Move::Move(string n, float d, int m, bool p, bool se, int a, vector<Tag> t, bool tet, int h) : ap(a), name(n), physical(p), damage(d), mana(m), selectEnemy(se), tags(t), targetEnemyTeam(tet), hits(h) {

}

void Move::dealDamage(RenderWindow* window, Fightable* attacker, Fightable* defender) {
	attacker->stats.ap -= ap;
	
	double agilityBased = diffSum(attacker->stats.agility, defender->stats.agility); // x is 2000
	double bonusBased = diffSum(attacker->stats.accuracybonus, defender->stats.evasionbonus); // x is 2000 (although could be anything)
	double weightedSpeedDiff = agilityBased + bonusBased; // -2 to 2
	double basePercent = pow(weightedSpeedDiff + 2, 0.5) - 1.0; // -1 to 1
	double luckPercent = 0.6 * basePercent + 0.4 * pow(0.5 + (attacker->stats.luck - defender->stats.luck) / 4000.0, 1.5); // -1 to 1

	double percent = 0.15 * luckPercent + 0.85; // 0.7 to 1
	bool hitting = random() < percent;

	if (hitting) {
		double index = (weighted(window->playerTeam) - weighted(window->enemyTeam) + 196) / 1571;
		double bonus = 0.2;
		int critAccountedDamage = damage;
		double actualCritChance = increase(0.04 * attacker->stats.critchancebonus, attacker->stats.luck / 2000.0);
		if (random() < actualCritChance) {
			cout << "Critical hit!\n";
			critAccountedDamage *= attacker->stats.critincrease;
		}


		double power = attacker->stats.magic;
		if (physical) {
			power = attacker->stats.strength;
		}

		double deviation = (bonus + (attacker->stats.luck / 2000.0)) * power * critAccountedDamage;
		cout << "deviation: " << deviation << endl;

		int damagedone = (int) (rand(index * attacker->stats.damagebonus, deviation * attacker->stats.rangebonus) * defender->stats.damagetaken + 1);
		cout << "Damage done: " << damagedone << endl;
		defender->stats.hp -= damagedone;
		if (physical) { // Not true, ranged weapons dont recoil
			int recoil = (int) (critAccountedDamage * defender->stats.vitality / 9.0);
			cout << "Recoil: " << recoil << endl;
			attacker->stats.hp -= recoil;
		}
	}
	else {
		cout << "Miss!\n";
	} 
}