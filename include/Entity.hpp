#pragma once

#include <memory>

#include "utils.hpp"

class RenderWindow;

using namespace std;

struct sdl_deleter
{
	void operator()(SDL_Texture *p) const {
		SDL_DestroyTexture(p);
	}
};

class Entity {
public:
	Entity();
	// ~Entity();
	// NOTE: All destructors NEED to be virtual for it to be overrided
	Entity(float px, float py, SDL_Texture* ptexture);
	Entity(float px, float py, SDL_Texture* ptexture, int pw, int ph);
	// Entity(const Entity& e);
	void setRect();
	void fullPicSize();
	SDL_Point getsize();
	SDL_Rect getRect();
	void setTexture(SDL_Texture* ptexture);
	float distance(Entity* e);
	float angleBetween(Entity* e);
	virtual void customDraw(RenderWindow* window);

	float x = 0;
	float y = 0;
	int width;
	int height;
	int show_width;
	int show_height;
	bool textureDraw = true;
	float angle = 0;
	int flip = 0;
	
	int row = 0;
	int column = 0;
	SDL_Rect currentFrame;
	shared_ptr<SDL_Texture> texture;
};