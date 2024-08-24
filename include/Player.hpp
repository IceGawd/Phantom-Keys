#pragma once

#include "PartyMember.hpp"
#include "Input.hpp"

using namespace tmx;

void interactCheck(vector<void*> vv);

struct InputLinkedList {
	int input;
	InputLinkedList* next = nullptr;
	InputLinkedList* prev = nullptr;

	InputLinkedList(int i);
	~InputLinkedList();
};

InputLinkedList* pushBack(InputLinkedList* ill, int i);
InputLinkedList* find(InputLinkedList* ill, int i);
InputLinkedList* pullForward(InputLinkedList* ill, int i);
InputLinkedList* addInput(InputLinkedList* ill, int i);

struct Player : public PartyMember {
	int speed;
	float traction;
	Input previnput;
	Input input;
	InputLinkedList* ill = nullptr;

	Player(RenderWindow* window, vector<Move*> m);
	virtual bool draw(RenderWindow* window, World* world, vector<GameObject*>& entities);
	void changeDirection();
};