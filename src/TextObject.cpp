#include "TextObject.hpp"

TextObject::TextObject(RenderWindow* window, int n, Fightable* gotHit, bool crit) {
	text = to_string(n);

	setText(window);

	double radius = gotHit->sizeIncrease * gotHit->show_width;
	xvel = radius * (random() * 2 - 1);
	xvel /= sqrt(abs(xvel));
	yvel = -pow(pow(radius, 2) - pow(xvel, 2), 0.25);

	double ratio = 0.1 + 1.0 * n / gotHit->stats.hpMax;
	ratio = 1.414 * ratio / (ratio + 0.414);
	ratio = 50.0 * ratio / height;
	ratio *= crit ? 1.5 : 1;

	show_width = width * ratio;
	show_height = height * ratio;

	centerOn(gotHit);
	// cout << "n: " << n << endl;
}

TextObject::TextObject(RenderWindow* window, string t, Fightable* gotHit, SDL_Color c) : text(t), color(c) {
	arc = false;
	yvel = -5;

	setText(window);
	centerOn(gotHit);
}

void TextObject::setText(RenderWindow* window) {
	SDL_Surface* surfaceMessage = window->getTextSurface(text, 255, 0, 0, 255);
	setTexture(SDL_CreateTextureFromSurface(window->renderer, surfaceMessage));
	fullPicSize();
	SDL_FreeSurface(surfaceMessage);
}

void TextObject::centerOn(Fightable* gotHit) {
	x = gotHit->battleX + gotHit->sizeIncrease * (gotHit->show_width - show_width) / 2;
	y = gotHit->battleY + gotHit->sizeIncrease * (gotHit->show_height - show_height) / 2;
}

bool TextObject::draw(RenderWindow* window, World* world, vector<GameObject*>& entities) {
	// /*
	if (arc) {
		xvel *= FRICTION;
		yvel *= FRICTION;
		yvel += GRAVITY;
	}

	double lifespan = 1.0 * life / LIFEMAX; 
	// window->drawText(to_string(number), 255, 0, 0, (int) (lifespan * 255), x, y, 100, 100);

	// lifespan * 255
	SDL_Surface* surfaceMessage = window->getTextSurface(text, color.r, color.g, color.b, 255.0 * lifespan);
	setTexture(SDL_CreateTextureFromSurface(window->renderer, surfaceMessage));
	SDL_FreeSurface(surfaceMessage);

	life--;

	// cout << "BREH <<<<<<< life: " << life << " xvel: " << xvel << " yvel: " << yvel << endl;
	// cout << "x: " << x << cout << ""

	GameObject::draw(window, world, entities);
	setRect();
	window->render(this);

	if (life <= 0) {
		// cout << "revert back to " << window->revert << endl;
		// window->turnstate = window->revert;
		return true;
	}
	return false;
	// */

	/*
	life--;

	SDL_Surface* surfaceMessage = window->getTextSurface(to_string(number), 255, 0, 0, life * 4);
	setTexture(SDL_CreateTextureFromSurface(window->renderer, surfaceMessage));
	SDL_FreeSurface(surfaceMessage);
	setRect();
	window->render(this);
	return life <= 0;
	*/
}