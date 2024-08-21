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


// MEM LEAK
struct TextSlice {
	static constexpr float WAVEDELTA = M_PI / 18.0;
	const int MOVEMENTMOD = 3;
	const int GHOSTWAVE = 10;
	const float speed = 1;
	map<char, Mix_Chunk*>* sounds = nullptr;
	string text;
	SDL_Color color = {255, 255, 255, 255};
	vector<SDL_Surface*> surfaces;
	vector<Entity*> letters;
	float frames = 0;
	float sound = 0;
	int x = 0;
	int y = 0;
	int XMIN = 0;
	int XMAX = 900; 

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