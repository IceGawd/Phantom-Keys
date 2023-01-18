#pragma once

#include "tmxlite/Types.hpp"

#include "GameObject.hpp"
#include "Input.hpp"

using namespace tmx;

struct Player : public GameObject {
	int speed;
	float traction;
	Input previnput;
	Input input;

	Player(RenderWindow* window);
	virtual bool draw(RenderWindow* window, World* world, vector<GameObject*>& entities);
	void changeDirection(Input& input);
	SDL_Rect getHitbox();
	vector<Vector2f> getPoints();
};