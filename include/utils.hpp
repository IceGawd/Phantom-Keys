#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <random>
#include <vector>

using namespace std;

float random();
float rand(float std, float m);
float invNorm(float x);
float RationalApproximation(float t);

template <typename T>
float weighted(vector<T> levels);

template <typename T>
float average(vector<T> levels);

float quadratic(float a, float b, float c);
float increase(float initial, float percent);

float distanceFrom(float x, float y);
float angleFromCoords(float x, float y);

enum Gamestate {
	OVERWORLD, 
	BATTLE, 
	CUTSCENE
};

enum Tag {
	PIERCING, 
	BLUDGEONING, 
	SLASHING, 
	UPWARD, 
	FORWARD, 
	FIRE, 
	ICE, 
	FORCE, 
	ELECTRICITY, 
	DARK, 
	LIGHT, 
	VIBRATING, 
};