#include <iostream>

#include "Entity.hpp"

using namespace std;

/*
Entity::~Entity() {
	// cout << "lmao gone" << endl;
	SDL_DestroyTexture(texture.get());
}
*/

Entity::Entity() : x(0), y(0) {

}

Entity::Entity(float px, float py, SDL_Texture* ptexture, int pw, int ph) : x(px), y(py), width(pw), height(ph), show_width(pw), show_height(ph) {
	setTexture(ptexture);
	setRect();
}

Entity::Entity(float px, float py, SDL_Texture* ptexture) : x(px), y(py) {
	setTexture(ptexture);
	fullPicSize();
	setRect();
}

void Entity::setTexture(SDL_Texture* ptexture) {
	texture = shared_ptr<SDL_Texture>(ptexture, sdl_deleter());
	SDL_SetTextureBlendMode(ptexture, SDL_BLENDMODE_BLEND);
}

// COPY CONSTRUCTOR
/*
Entity::Entity(const Entity& e) {
	cout << "COPY" << endl;

	texture = new SDL_Texture();
	*texture = *(e.texture);
}
*/

void Entity::fullPicSize() {
	SDL_Point p = getsize();
	width = p.x;
	show_width = p.x;
	height = p.y;
	show_height = p.y;
}

void Entity::setRect() {
	currentFrame.x = column * width;
	currentFrame.y = row * height;
	currentFrame.w = width;
	currentFrame.h = height;
}

SDL_Point Entity::getsize() {
    SDL_Point size;
    SDL_QueryTexture(texture.get(), NULL, NULL, &size.x, &size.y);
    return size;
}

SDL_Rect Entity::getRect() {
	return {(int) x, (int) y, show_width, show_height};
}

float Entity::distance(Entity* e) {
	return distanceFrom(x - e->x + (show_width - e->show_width) / 2, y - e->y + (show_height - e->show_height) / 2);
}

float Entity::angleBetween(Entity* e) {
	return angleFromCoords(x - e->x + (show_width - e->show_width) / 2, y - e->y + (show_height - e->show_height) / 2);
}

void Entity::customDraw(RenderWindow* window) {
	
}