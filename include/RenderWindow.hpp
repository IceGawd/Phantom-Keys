#pragma once

#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <queue>

#include "Entity.hpp"
#include "utils.hpp"

class Fightable;
class Enemy;

using namespace std;

class RenderWindow {
public:
	const static int WIDTH = 1280;
	const static int HEIGHT = 720;

	const Uint8* keyboard;

	bool temp = false;
	bool playerInput = true;
	Gamestate gamestate = OVERWORLD;
	vector<Fightable*> playerTeam;
	vector<Enemy*> enemyTeam;
	queue<Fightable*> turnOrder;

	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* zephyrea;
	int x = 0;
	int y = 0;
	float zoom = 1.0;

	RenderWindow(const char* title); 
	SDL_Texture* loadTexture(const char* filePath);
	void cleanUp();
	void clear();
	SDL_Rect getDestRect(Entity* entity, bool stationary = false);
	void render(Entity* entity, bool stationary = false, int centerx = -1, int centery = -1);
	void display();
	void setColor(int r, int g, int b, int a);
	void drawLine(int x1, int y1, int x2, int y2, bool stationary = true);
	void drawCircle(int x, int y, int radius);
	void drawText(string text, unsigned char r, unsigned char g, unsigned char b, unsigned char a, int x, int y, int w, int h);
	SDL_Texture* getAreaTexture(SDL_Rect& rect, SDL_Texture* source);
};