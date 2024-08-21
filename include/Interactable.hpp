#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


#include "TextSequence.hpp"

struct Interactable {
	SDL_Rect rect;
	TextSequence* interactText;

	Interactable(SDL_Rect r, TextSequence* i);
	~Interactable();
};
