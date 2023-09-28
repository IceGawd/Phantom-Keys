#pragma once
#include "Fightable.hpp"

struct TextObject : public GameObject {
	const float FRICTION = 0.9;
	const int GRAVITY = 1;
	const int LIFEMAX = 30;
	string text;
	int life = LIFEMAX;
	bool arc = true;
	SDL_Color color = {255, 0, 0};

	TextObject(RenderWindow* window, int n, Fightable* gotHit, bool crit);
	TextObject(RenderWindow* window, string t, Fightable* gotHit, SDL_Color c);
	void setText(RenderWindow* window);
	void centerOn(Fightable* gotHit);
	virtual bool draw(RenderWindow* window, World* world, vector<GameObject*>& entities);
};
