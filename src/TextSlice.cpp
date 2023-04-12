#include "TextSlice.hpp"

TextSlice::TextSlice(RenderWindow& window, string t) : text(t) {
	shownText = TTF_RenderText_Solid(window.sans, text.c_str(), color);
	setTexture(SDL_CreateTextureFromSurface(window.renderer, shownText));
}

bool TextSlice::draw(RenderWindow& window) {
	
	return false;
}