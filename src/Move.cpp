#include "Move.hpp"
#include "TextObject.hpp"

Move::Move(string n, float d, int m, bool p, bool se, int a, vector<Tag> t, vector<KeyFrame> k, vector<pair<int, NoteType>> sn, bool tet, int h) : ap(a), name(n), physical(p), damage(d), mana(m), selectEnemy(se), tags(t), animation(k), targetEnemyTeam(tet), hits(h), stingerNotes(sn) {

}

bool Move::getHitting(Fightable* attacker, Fightable* defender) {
	double agilityBased = diffSum(attacker->stats.agility, defender->stats.agility); // x is 2000
	double bonusBased = diffSum(attacker->stats.accuracybonus, defender->stats.evasionbonus); // x is 2000 (although could be anything)
	double weightedSpeedDiff = agilityBased + bonusBased; // -2 to 2
	double basePercent = pow(weightedSpeedDiff + 2, 0.5) - 1.0; // -1 to 1
	double luckPercent = 0.6 * basePercent + 0.4 * pow(0.5 + (attacker->stats.luck - defender->stats.luck) / 4000.0, 1.5); // -1 to 1

	double percent = 0.15 * luckPercent + 0.85; // 0.7 to 1
	return random() < percent;
	// return random() < 0.5;
}

bool Move::getCrit(Fightable* attacker) {
	double actualCritChance = increase(0.04 * attacker->stats.critchancebonus, attacker->stats.luck / 2000.0);
	return random() < actualCritChance;
	// return random() < 0.5;
}


void Move::dealDamage(RenderWindow* window, Fightable* attacker, Fightable* defender, vector<GameObject*>& battleEntities, bool hitting, bool crit, float howGoodYouDoIt) {
	window->revert = ENDTURN;
	cout << name << endl;
	
	attacker->stats.ap -= ap;
	
	if (hitting) {
		double index = (weighted(window->playerTeam) - weighted(window->enemyTeam) + 196) / 1571;
		double bonus = howGoodYouDoIt / 4.0;
		int critAccountedDamage = damage;
		// crit = true;
		if (crit) {
			cout << "Critical hit!\n";
			battleEntities.push_back(new TextObject(window, "CRITICAL HIT!", attacker, {255, 150, 0}));
			critAccountedDamage *= attacker->stats.critincrease;
		}

		double power = attacker->stats.magic;
		if (physical) {
			power = attacker->stats.strength;
		}

		double mean = (bonus + (attacker->stats.luck / 2000.0)) * power * critAccountedDamage;
		// cout << "mean: " << mean << endl;

		int damagedone = (int) (rand(index * attacker->stats.rangebonus, mean * attacker->stats.damagebonus) * defender->stats.damagetaken + 1);
		cout << "Damage done: " << damagedone << endl;
		if (damagedone > 0) {
			defender->stats.hp -= damagedone;
			battleEntities.push_back(new TextObject(window, damagedone, defender, crit));
			if (physical) { // NOTE: Not true, ranged weapons dont recoil, ranged is technically physical
				int recoil = (int) (damagedone * defender->stats.vitality / 9.0);
				cout << "Recoil: " << recoil << endl;
				attacker->stats.hp -= recoil;
				battleEntities.push_back(new TextObject(window, recoil, attacker, crit));
			}
		}
		else {
			battleEntities.push_back(new TextObject(window, "NO DAMAGE!", attacker, {150, 150, 150}));
		}
	}
	else {
		cout << "MISS!\n";
		battleEntities.push_back(new TextObject(window, "MISS!", attacker, {150, 150, 150}));
	}
}