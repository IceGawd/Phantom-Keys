#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <random>
#include <vector>

using namespace std;

class Fightable;
class Enemy;
class RenderWindow;

float random();
float rand(float std, float m);
float invNorm(float x);
float RationalApproximation(float t);
float weighted(vector<Fightable*> levels);
float weighted(vector<Enemy*> levels);
float average(vector<Fightable*> levels);

int diffSum(int a, int b);

float quadratic(float a, float b, float c);
float increase(float initial, float percent);

float distanceFrom(float x, float y);
float angleFromCoords(float x, float y);

void arrowChange(RenderWindow* window, vector<SDL_Scancode>& keys, bool* direction, void (*foo)(vector<void*>), vector<void*> passingArgument);

enum Gamestate {
	OVERWORLD, 
	BATTLE, 
	CUTSCENE
};

enum Turnstate {
	HEALTHCHECK, 
	CHOOSEOPTION, 
	CHOOSEMOVE, 
	SELECTENEMY, 
	ANIMATION, 
	DAMAGE, 
	ENDTURN
};

enum Tag {
	PIERCING, 
	BLUDGEONING, 
	SLASHING, 
	UPWARD, 
	FORWARD, 
	FIRE, // Maybe call Incendiary?
	ICE, 
	FORCE, 
	ELECTRICITY, 
	DARK, 
	LIGHT, 
	VIBRATING, 
};