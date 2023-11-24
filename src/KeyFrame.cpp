#include "KeyFrame.hpp"

KeyFrame::KeyFrame(int f, string a, int ro, int xTemp, int yTemp, ReferenceFrame r, Interpolation i, bool d) : frame(f), animation(a), row(ro), x(xTemp), y(yTemp), rf(r), inter(i), damage(d) {
	
}

void KeyFrame::applyKeyframe(Fightable* attacker, KeyFrame* previous, int curFrame, Fightable* defender) {
	double change = 0;
	double p = 1.0 * curFrame / frame;
	if (inter == CONSTANT) {
		change = (int) round(p);
	}
	else if (inter == LINEAR) {
		change = p;
	}
	else if (inter == EXPONENTIAL) {
		change = pow(2, p);
	}
	else if (inter == LOGARITHMIC) {
		change = log2(p);
	}
	else if (inter == SQUARE_ROOT) {
		change = sqrt(p);
	}

	pair<int, int> p1 = previous->base(attacker, defender);
	pair<int, int> p2 = base(attacker, defender);

	p1.first += previous->x;
	p1.second += previous->y;
	p2.first += x;
	p2.second += y;

	attacker->battleX = change * (p1.first - p2.first) + p2.first;
	attacker->battleY = change * (p1.second - p2.second) + p2.second;
}

pair<int, int> KeyFrame::base(Fightable* attacker, Fightable* defender) {
	if (rf == STARTINGCOORDS) {
		return {0, 0};
	}
	else if (rf == ENEMYCOORDS) {
		return {defender->battleX + (defender->show_width * defender->sizeIncrease - attacker->show_width * attacker->sizeIncrease) / 2, defender->battleY + (defender->show_height * defender->sizeIncrease - attacker->show_height * attacker->sizeIncrease) / 2};		
	}
	else if (rf == INFRONTENEMY) {
		return {defender->battleX - attacker->show_width * attacker->sizeIncrease / 2, defender->battleY + (defender->show_height * defender->sizeIncrease - attacker->show_height * attacker->sizeIncrease) / 2};				
	}
	return {0, 0};
}