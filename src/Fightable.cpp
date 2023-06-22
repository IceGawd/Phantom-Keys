#include "Fightable.hpp"

Fightable::Fightable() {
	
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

	x = battleX;
	y = battleY;

	setRect();
	window->render(this, true);

	x = tempx;
	y = tempy;
}