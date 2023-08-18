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
	int actualWidth = WIDTH;
	int actualHeight = HEIGHT;
	double scaleMultiplier = 1;
	int xOrigin = 0;
	int yOrigin = 0;

	const Uint8* keyboard;

	bool temp = false;
	bool playerInput = true;
	Gamestate gamestate = OVERWORLD;
	Turnstate turnstate = CHOOSEMOVE;
	vector<Fightable*> playerTeam;
	vector<Enemy*> enemyTeam;
	queue<Fightable*> turnOrder;

	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* zephyrea;
	int x = 0;
	int y = 0;
	float zoom = 1.0;

	int savedX = 0;
	int savedY = 0;
	float savedZoom = 1.0;

	RenderWindow(const char* title);
	void resizeWindow();
	SDL_Texture* loadTexture(const char* filePath);
	void cleanUp();
	void clear();
	SDL_Rect getDestRect(Entity* entity, bool stationary = false);
	void scaleDestRect(SDL_Rect& dest);
	void render(Entity* entity, bool stationary = false, int centerx = -1, int centery = -1);
	void display();
	void setColor(int r, int g, int b, int a);
	void drawLine(int x1, int y1, int x2, int y2, bool stationary = true);
	void drawCircle(int x, int y, int radius);
	SDL_Surface* getTextSurface(string text, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	void drawScaledTextInBox(string text, unsigned char r, unsigned char g, unsigned char b, unsigned char a, int x, int y, int w, int h, bool centered);
	void textRect(SDL_Surface* surfaceMessage, SDL_Texture* Message, SDL_Rect Message_rect);
	void drawText(string text, unsigned char r, unsigned char g, unsigned char b, unsigned char a, int x, int y, int w, int h);
	SDL_Texture* getAreaTexture(SDL_Rect& rect, SDL_Texture* source);
};