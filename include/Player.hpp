#pragma once

#include "PartyMember.hpp"
#include "Input.hpp"

using namespace tmx;

struct Player : public PartyMember {
	int speed;
	float traction;
	Input previnput;
	Input input;

	Player(RenderWindow* window, vector<Move*> m);
	virtual bool draw(RenderWindow* window, World* world, vector<GameObject*>& entities);
	void changeDirection(Input& input);
};