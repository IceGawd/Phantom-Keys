#pragma once

#include <SDL2/SDL_mixer.h>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <random>

#include "Entity.hpp"
#include "RenderWindow.hpp"
#include "TextEffect.hpp"
#include "utils.hpp"

struct TextSlice {
	const int XMIN = 50;
	const int XMAX = 1200; 
	static constexpr float WAVEDELTA = M_PI / 20.0;
	const int MOVEMENTMOD = 5;
	const int GHOSTWAVE = 10;
	map<char, Mix_Chunk*>* sounds = nullptr;
	string text;
	SDL_Color color = {255, 255, 255, 255};
	vector<SDL_Surface*> surfaces;
	vector<Entity*> letters;
	float speed = 1;
	float frames = 0;
	int sound = 0;
	int x = XMIN;
	int y = 0;

	bool shaky = false;
	bool wavey = false;
	bool ghost = false;
	bool rainbow = false;
	bool diagonal_rainbow = false;


	float waveMod = 0;

	TextSlice(RenderWindow& window, string t);
	TextSlice(RenderWindow& window, string t, SDL_Color c);
	TextSlice(RenderWindow& window, string t, SDL_Color c, vector<TextEffect> e);
	bool draw(RenderWindow& window);
	void setEffects(vector<TextEffect> e);
};