#pragma once

#include "GameObject.hpp"
#include "Input.hpp"

struct Player : public GameObject {
	int speed;
	float traction;
	Input previnput;
	Input input;

	Player(RenderWindow* window);
	virtual bool draw(RenderWindow* window, World* world, vector<GameObject*>& entities);
	void changeDirection(Input& input);
};