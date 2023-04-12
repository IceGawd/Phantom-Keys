#pragma once

#include <string>
#include "Entity.hpp"
#include "RenderWindow.hpp"

struct TextSlice : public Entity {
	string text;
	SDL_Surface* shownText;
	SDL_Color color = {0, 0, 0, 255};

	TextSlice(RenderWindow& window, string t);
	bool draw(RenderWindow& window);
};