#pragma once

#include "tmxlite/Types.hpp"

#include "GameObject.hpp"

using namespace tmx;

struct Collideable : public GameObject {
	float prevx;
	float prevy;

	virtual bool draw(RenderWindow* window, World* world, vector<GameObject*>& entities);

	virtual SDL_Rect getHitbox();
	virtual vector<Vector2f> getPoints();
};