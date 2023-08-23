#include "HealthBar.hpp"
#include "RenderWindow.hpp"

HealthBar::HealthBar(RenderWindow* window, int x, int y, int w, int h) {
	base = new Entity(x, y, window->loadTexture("res/gfx/Battle/Health/HealthBracket.png"));
	double scalingSize = min(1.0 * w / base->width, 1.0 * h / base->height);
	base->show_width = base->width * scalingSize;
	base->show_height = base->height * scalingSize;
	base->x += (w - base->show_width) / 2;
	base->y += (h - base->show_height) / 2;

	fullHealth = new Entity(x + 12 * scalingSize, y, window->loadTexture("res/gfx/Battle/Health/HealthBarFull.png"));
	noHealth = new Entity(x + 12 * scalingSize, y, window->loadTexture("res/gfx/Battle/Health/HealthBarEmpty.png"));

	// assert((fullHealth->width == noHealth->width));

	internalScaling = scalingSize * min(169.0 / fullHealth->width, 21.0 / fullHealth->height);
	fullHealth->show_width = fullHealth->width * internalScaling;
	fullHealth->show_height = fullHealth->height * internalScaling;
	fullHealth->x += (scalingSize * 169.0 - fullHealth->show_width) / 2;
	fullHealth->y += (scalingSize * 21.0 - fullHealth->show_height) / 2;

	noHealth->show_width = fullHealth->show_width; 
	noHealth->show_height = fullHealth->show_height; 
	noHealth->x = fullHealth->x;
	noHealth->y = fullHealth->y;
}

HealthBar::~HealthBar() {
	delete base;
	delete fullHealth;
	delete noHealth;
}

void HealthBar::represent(RenderWindow* window, Fightable* fighter) {
	window->render(base);

	fullHealth->currentFrame.w = fullHealth->width * fighter->stats.hp / fighter->stats.hpMax;
	noHealth->currentFrame.w = noHealth->width - fullHealth->currentFrame.w;
	noHealth->currentFrame.x = fullHealth->currentFrame.w;
	fullHealth->show_width = fullHealth->currentFrame.w * internalScaling;
	noHealth->show_width = noHealth->currentFrame.w * internalScaling;
	noHealth->x = fullHealth->x + fullHealth->show_width;

	window->render(noHealth);
	window->render(fullHealth);
}