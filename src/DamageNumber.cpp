#include "DamageNumber.hpp"

DamageNumber::DamageNumber(RenderWindow* window, int n, Fightable* gotHit) : number(n) {
	SDL_Surface* surfaceMessage = window->getTextSurface(to_string(number), 255, 0, 0, 255);
	setTexture(SDL_CreateTextureFromSurface(window->renderer, surfaceMessage));
	SDL_FreeSurface(surfaceMessage);

	double radius = gotHit->sizeIncrease * gotHit->show_width;
	xvel = radius * (random() * 2 - 1);
	xvel /= sqrt(abs(xvel));
	yvel = sqrt(pow(radius, 2) - pow(xvel, 2));
}

bool DamageNumber::draw(RenderWindow* window, World* world, vector<GameObject*>& entities) {
	xvel *= FRICTION;
	yvel *= FRICTION;
	yvel += GRAVITY;

	double lifespan = 1.0 * life / LIFEMAX; 
	SDL_Surface* surfaceMessage = window->getTextSurface(to_string(number), 255, 0, 0, (int) (lifespan * 255));
	setTexture(SDL_CreateTextureFromSurface(window->renderer, surfaceMessage));
	SDL_FreeSurface(surfaceMessage);

	life--;

	GameObject::draw(window, world, entities);

	if (life <= 0) {
		window->turnstate = window->revert;
		return true;
	}
	return false;
}