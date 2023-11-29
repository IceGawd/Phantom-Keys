#include "KeyFrame.hpp"

KeyFrame::KeyFrame(int f, string a, int ro, int xTemp, int yTemp, ReferenceFrame r, Interpolation i, bool d, int fd) : frame(f), animation(a), row(ro), x(xTemp), y(yTemp), rf(r), inter(i), damage(d), framedelay(fd) {
	
}

void KeyFrame::applyKeyframe(Fightable* attacker, KeyFrame& previous, int curFrame, Fightable* defender, bool reverse) {
	// cout << "c1\n";
	if (attacker->current != animation) {
		attacker->changeSpriteSheet(animation);
		if (attacker->next->yFrames <= row) {
			attacker->row = 0;
		}
		attacker->row = row;
	}

	double change = 0;
	double p = 1.0 * curFrame / frame;
	if (inter == CONSTANT) {
		change = (int) round(p);
	}
	else if (inter == LINEAR) {
		change = p;
	}
	else if (inter == EXPONENTIAL) {
		change = pow(2, p) - 1;
	}
	else if (inter == LOGARITHMIC) {
		change = log2(p + 1);
	}
	else if (inter == SQUARE_ROOT) {
		change = sqrt(p);
	}

	pair<int, int> p1 = previous.base(attacker, defender, reverse);
	pair<int, int> p2 = base(attacker, defender, reverse);

	if (reverse) {
		p1.first -= previous.x;
		p1.second -= previous.y;
		p2.first -= x;
		p2.second -= y;
	}
	else {
		p1.first += previous.x;
		p1.second += previous.y;
		p2.first += x;
		p2.second += y;
	}

	attacker->battleX = change * (p2.first - p1.first) + p1.first;
	attacker->battleY = change * (p2.second - p1.second) + p1.second;
	// cout << "c2\n";
}

pair<int, int> KeyFrame::base(Fightable* attacker, Fightable* defender, bool reverse) {
	if (rf == STARTINGCOORDS) {
		return {attacker->battleOriginX, attacker->battleOriginY};
	}
	else if (rf == ENEMYCOORDS) {
		return {defender->battleX + (defender->show_width * defender->sizeIncrease - attacker->show_width * attacker->sizeIncrease) / 2, defender->battleY + (defender->show_height * defender->sizeIncrease - attacker->show_height * attacker->sizeIncrease) / 2};		
	}
	else if (rf == INFRONTENEMY) {
		if (reverse) {
			return {defender->battleX + defender->show_width * defender->sizeIncrease / 2, defender->battleY + (defender->show_height * defender->sizeIncrease - attacker->show_height * attacker->sizeIncrease) / 2};
		}
		return {defender->battleX - attacker->show_width * attacker->sizeIncrease / 2, defender->battleY + (defender->show_height * defender->sizeIncrease - attacker->show_height * attacker->sizeIncrease) / 2};				
	}
	return {0, 0};
}