#include "Buff.hpp"

Buff::Buff(int l, int t, BuffType b) : bufftype(b) {
	max_level = l;
	actualmaxlevel = l;
	turns = t;
	actualturns = t;
}

Buff::Buff(const Buff &t) : bufftype(t.bufftype) {
	max_level = t.max_level;
	actualmaxlevel = t.actualmaxlevel;
	turns = t.turns;
	actualturns = t.actualturns;
}

void Buff::infoUpdate() {
	if (max_level > MAXLEVEL){
		max_level = MAXLEVEL;
		actualmaxlevel = MAXLEVEL;
	}
	if (max_level < -MAXLEVEL){
		max_level = -MAXLEVEL;
		actualmaxlevel = -MAXLEVEL;
	}
	if (turns > MAXTURNS){
		turns = MAXTURNS;
		actualturns = -MAXTURNS;
	}
	if (turns < 0){
		turns = 0;
		actualturns = 0;
	}

	if (abs(level) > abs(max_level)){
		level = max_level;
	}
	if (abs(actuallevel) > abs(actualmaxlevel)){
		actuallevel = actualmaxlevel;
	}
}

void Buff::changeBuff(Buff b, double (*op)(double, double)) {
	if (b.bufftype == bufftype) {
		double myval = actualmaxlevel * actualturns;
		double myratio = actualmaxlevel / actualturns;
		double buffval = b.actualmaxlevel * b.actualturns;
		double buffratio = b.actualmaxlevel / b.actualturns;
		double total = op(myval, buffval);

		double v = exp(op(myval * log(myratio), buffval * log(buffratio)) / total);
		actualmaxlevel = sqrt(v * total);
		actualturns = sqrt(total / v);

		int levels[2] = {(int) floor(actualmaxlevel), (int) ceil(actualmaxlevel)};
		int turnss[2] = {(int) floor(actualturns), (int) ceil(actualturns)};

		actuallevel = actuallevel * myval / total;
		level = (int) round(actuallevel);

		for (int levelss : levels){
			for (int turn : turnss){
				if (abs(levelss * turn - total) <= abs(max_level * turns - total)){
					max_level = levelss;
					turns = turn;
				}
			}
		}
		infoUpdate();
	}
	else {
		cout << "why and how the fuck do you expect to merge buffs with two different types???\n";
		return;
	}

}

double Add(double a, double b) {
	return a + b;
}
double Subtract(double a, double b) {
	return a - b;
}


void Buff::merge(Buff b){
	changeBuff(b, Add);
}

void Buff::remove(Buff b) {
	changeBuff(b, Subtract);
}

void Buff::effect(Fightable character) {
	bufftype.effect(level, character);
}

void Buff::turnOver(Fightable f) {
	if (turns <= 0){
		for (int x = 0; x < f.activeBuffs.size(); x++) {
			if (f.activeBuffs[x]->bufftype == bufftype) {
				f.activeBuffs.erase(f.activeBuffs.begin() + x);
				break;
			}
		}
	}
	else{
		actuallevel += (actualmaxlevel - actuallevel) / actualturns;
		level = (int) ceil(actuallevel);
		turns--;
		actualturns--;
	}
}