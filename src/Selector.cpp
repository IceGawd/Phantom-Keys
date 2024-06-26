#include "Selector.hpp"
#include "RenderWindow.hpp"
#include "utils.hpp"

/**
 * Creates a Selector
 * @param {window} Window used to load the selector texture
 * @return Selector
 */
Selector::Selector(RenderWindow& window) {
	note = new Entity(0, 0, window.loadTexture("res/gfx/Battle/rotatingIndicator.png"));
}

void Selector::render(RenderWindow* window, vector<GameObject*>& entities) {
	arrowChange(window, window->cc.up, &prevUp, &sDecrement, {this});
	arrowChange(window, window->cc.down, &prevDown, &sIncrement, {this});
	if (window->turnstate == HEALTHCHECK) {
		arrowChange(window, window->cc.left, &prevLeft, &sParty, {this});
		arrowChange(window, window->cc.right, &prevRight, &sEnemy, {this});
	}
	else {
		arrowChange(window, window->cc.okay, &prevEnter, &sEnter, {this, window, &entities});
		enemyPoint = true;
	}

	if (selection < 0) {
		selection = 0;
	}


	Fightable* selected = getSelected(window);

	xCenterAim = selected->battleX + (selected->sizeIncrease * selected->show_width - note->show_width) / 2;
	yCenterAim = selected->battleY + (selected->sizeIncrease * selected->show_height - note->show_height) / 2;
	radiusAim = (int) sqrt(pow((selected->sizeIncrease * selected->show_width) / 2, 2) + pow((selected->sizeIncrease * selected->show_height) / 2, 2));
	// radiusAim = (int) sqrt(pow((selected->sizeIncrease * selected->show_width + note->show_width) / 2, 2) + pow((selected->sizeIncrease * selected->show_height + note->show_height) / 2, 2));

	angle += 0.05;
	if (snap) {
		snap = false;
		radius = radiusAim;
		xCenter = xCenterAim;
		yCenter = yCenterAim;
	}
	else {
		radius = (radius + radiusAim) / 2;
		xCenter = (xCenter + xCenterAim) / 2;
		yCenter = (yCenter + yCenterAim) / 2;
	}

	// xCenter = 100;
	// yCenter = 100;
	// radius = 100;

	angle = angle - M_PI * int(2 * angle / M_PI) / 2;
	// cout << "angle: " << angle << endl;
	for (double temp = angle; temp <= 2 * M_PI; temp += M_PI / 2) {
		note->x = xCenter + radius * cos(temp);
		note->y = yCenter - radius * sin(temp);
		// cout << "x: " << note->x << " y: " << note->y << endl;
		window->render(note);
	}
}

/**
 * Gets the selected enemy the cursor is hovering over
 * @param {window} Window used to get the teams
 * @return Fighter that is selected
 */
Fightable* Selector::getSelected(RenderWindow* window) {
	if (enemyPoint) {
		if (selection >= window->enemyTeam.size()) {
			selection = window->enemyTeam.size() - 1;
		}
		return window->enemyTeam.at(selection);
	}
	else {
		if (selection >= window->playerTeam.size()) {
			selection = window->playerTeam.size() - 1;
		}
		return window->playerTeam.at(selection);
	}
}

void sDecrement(vector<void*> passingArgument) {
	Selector* selector = (Selector*) (passingArgument[0]);
	selector->selection--;
}

void sIncrement(vector<void*> passingArgument) {
	Selector* selector = (Selector*) (passingArgument[0]);
	selector->selection++;
}

void sEnter(vector<void*> passingArgument) {
	Selector* selector = (Selector*) (passingArgument[0]);	
	RenderWindow* window = (RenderWindow*) (passingArgument[1]);
	PartyMember* pm = (PartyMember*) (window->turnOrder.front());
	vector<GameObject*>* entities = (vector<GameObject*>*) (passingArgument[2]);
	pm->doAttack(window, window->enemyTeam.at(selector->selection), *entities);
	// window->turnstate = ENDTURN;
	selector->selection = 0;
}

void sParty(vector<void*> passingArgument) {
	Selector* selector = (Selector*) (passingArgument[0]);
	selector->enemyPoint = false;
}

void sEnemy(vector<void*> passingArgument) {
	Selector* selector = (Selector*) (passingArgument[0]);
	selector->enemyPoint = true;
}