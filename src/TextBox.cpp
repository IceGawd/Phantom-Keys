#include "TextBox.hpp"

TextBox::TextBox(RenderWindow& window, vector<TextSlice> t) : text(t) {
	setTexture(window.loadTexture("res/gfx/TextBox.png"));
	fullPicSize();
	show_width = window.WIDTH;
	show_height = height * window.WIDTH / width;
	x = 0;
	y = window.HEIGHT - show_height;
	curY = y + 50;
	setRect();
	for (TextSlice& ts : text) {
		ts.y = curY;
	}
}

bool TextBox::draw(RenderWindow& window) {
	// cout << "rowa\n";
	window.render(this, true);

	bool next;
	for (int x = 0; x < curIndex; x++) {
		next = text[x].draw(window);
	}

	if (next && curIndex < text.size()) {
		text[curIndex].x = text[curIndex - 1].x;
		text[curIndex].y = text[curIndex - 1].y;
		curIndex++;
	}
	bool sp = window.keyboard[SDL_SCANCODE_SPACE];
	bool done = sp && !prevHeld;
	prevHeld = sp;
	return done;
}