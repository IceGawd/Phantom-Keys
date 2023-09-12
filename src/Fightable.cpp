#include "Fightable.hpp"

Fightable::Fightable() {
	sizeIncrease = 2.15;
}

void Fightable::battle(RenderWindow* window, Fightable* turn) {
	frames += 1;
	if (frames >= next->frames) {
		frames = 0;
		column += 1;
		if (column >= next->xFrames) {
			column = 0;
		}
	}

	int tempx = x;
	int tempy = y;
	int sw = show_width;
	int sh = show_height;

	x = battleX;
	y = battleY;
	show_width *= sizeIncrease;
	show_height *= sizeIncrease;

	setRect();
	window->render(this);

	x = tempx;
	y = tempy;
	show_width = sw;
	show_height = sh;
}