#include "Selector.hpp"
#include "RenderWindow.hpp"
#include "utils.hpp"
#include "Enemy.hpp"

Selector::Selector(RenderWindow& window) {
	note = new Entity(0, 0, window.loadTexture("res/gfx/Battle/rotatingIndicator.png"));
}

void Selector::render(RenderWindow* window) {
	arrowChange(window, SDL_SCANCODE_W, &prevLeft, &sDecrement, {this});
	arrowChange(window, SDL_SCANCODE_S, &prevRight, &sIncrement, {this});
	arrowChange(window, SDL_SCANCODE_RETURN, &prevEnter, &sEnter, {this, window});

	if (selection < 0) {
		selection = 0;
	}
	if (selection >= window->enemyTeam.size()) {
		selection = window->enemyTeam.size() - 1;
	}

	Enemy* selected = window->enemyTeam.at(selection);
	xCenterAim = selected->battleX + (selected->show_width - note->show_width) / 2;
	yCenterAim = selected->battleY + (selected->show_height - note->show_height) / 2;
	radiusAim = (int) sqrt(pow((selected->show_width + note->show_width) / 2, 2) + pow((selected->show_height + note->show_height) / 2, 2));

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
	pm->doAttack(window, window->enemyTeam.at(selector->selection));
	window->turnstate = ENDTURN;
	selector->selection = 0;
}