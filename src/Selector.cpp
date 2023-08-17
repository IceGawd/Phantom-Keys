#include "Selector.hpp"
#include "RenderWindow.hpp"

Selector::Selector(RenderWindow& window) {
	note = new Entity(0, 0, window.loadTexture("res/gfx/Battle/rotatingIndicator.png"));
}

void Selector::render(RenderWindow* window) {
	angle += 0.05;	
	radius = (radius + radiusAim) / 2;
	xCenter = (xCenter + xCenterAim) / 2;
	yCenter = (yCenter + yCenterAim) / 2;

	angle = angle - int(2 * angle / M_PI);
	for (double temp = angle; temp < 2 * M_PI; temp += M_PI / 2) {
		note->x = xCenter + radius * cos(temp);
		note->y = yCenter - radius * sin(temp);
		window->render(note);
	}
}