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

void Fightable::battleInit(RenderWindow& window, int index) {
	battleOriginX = (index == 0 && window.playerTeam.size() != 2) ? 300 : 175;
	battleOriginY = (window.playerTeam.size() == 2) ? 115 + index * 230 : ((1.5 * index - 2.5) * index + 2) * 115;
	battleX = battleOriginX;
	battleY = battleOriginY;

	exhaustQueue.clear();
}

/**
 * Adds a move to the exhaust queue
 * @param {move} The move that is being added to the exhaust queue
 */
void Fightable::addToExhaustQueue(Move* move) {
	exhaustQueue.push_back(move);
	if (exhaustQueue.size() > moves.size() / 2.0) {
		exhaustQueue.erase(exhaustQueue.begin());
	}
}

/**
 * Gets the moves exhaust multiplier via the staling queue
 * @param {move} The move that is being checked for its exhaust
 * @return The exhaust multiplier to the move
 */
float Fightable::getExhaust(Move* move) {
	float answer = 0;
	for (int x = 0; x < exhaustQueue.size(); x++) {
		if (exhaustQueue[x] == move) {
			answer += round(5 * (moves.size() - 2 * x) / (moves.size() + 2) - 0.1) / 20.0;
		}
	}
	return 1 - answer;
}