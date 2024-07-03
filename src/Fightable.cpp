#include "Fightable.hpp"

Fightable::Fightable() {
	sizeIncrease = 2.15;
}

void Fightable::battle(RenderWindow* window, Fightable* turn, vector<GameObject*>& battleEntities) {
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

/**
 * Adds a move to the exhaust queue
 * @param {move} The move that is being added to the exhaust queue
 */
void Fightable::addToExhaustQueue(Move* move) {
	exhaustQueue.push_back(move);
}

/**
 * Gets the moves exhaust multiplier via the staling queue
 * @param {move} The move that is being checked for its exhaust
 * @return The exhaust multiplier to the move
 */
float Fightable::getExhaust(Move* move) {
	for (int x = 0; x < exhaustQueue.size(); x++) {
		
	}
}