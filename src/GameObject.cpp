#include <iostream>

#include "GameObject.hpp"

using namespace std;

GameObject::GameObject() {
	
}

GameObject::GameObject(float px, float py, SDL_Texture* ptexture, int pw, int ph) : Entity(px, py, ptexture, pw, ph) {

}

bool GameObject::draw(RenderWindow* window, World* world, vector<GameObject*>& entities) {
	x += xvel;
	y += yvel;
	
	return false;
}

void GameObject::changeSpriteSheet(string newSheet) {
	current = newSheet;
	next = &(sheets[current]);

	row = 0;
	column = 0;
	angle = 0;

	texture = next->texture;
	SDL_Point p = getsize();

	width = p.x / next->xFrames;
	height = p.y / next->yFrames;
	show_width = width;
	show_height = height;

	setRect();
}

GameObject* GameObject::createObject() {
	return new GameObject(*this);
}