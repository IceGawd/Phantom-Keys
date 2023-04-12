#include "TextBox.hpp"

TextBox::TextBox(vector<TextSlice> t) : text(t) {

}

bool TextBox::draw(RenderWindow& window) {
	bool next = text[curIndex].draw(window);
	if (next) {
		curIndex++;
	}
	bool sp = window.keyboard[SDL_SCANCODE_SPACE];
	bool done = sp && !prevHeld;
	prevHeld = sp;
	return done;
}