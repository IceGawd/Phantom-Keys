#include "TextBox.hpp"

TextBox::TextBox(RenderWindow& window, vector<TextSlice> t) : text(t) {
	setTexture(window.loadTexture("res/gfx/TextBox.png"));
	fullPicSize();
	// cout << zoom << endl;
	show_width = zoom * width;
	show_height = zoom * height;
	// cout << show_width << endl;
	x = (window.WIDTH - show_width) / 2;
	y = window.HEIGHT - show_height - 35;
	// cout << x << endl;
	setRect();
	reset();
}

void TextBox::reset() {
	curIndex = 1;
	prevHeld = true;

	for (TextSlice& ts : text) {
		ts.XMIN = x + ADJUSTMENT;
		ts.XMAX = x + show_width - ADJUSTMENT;
		ts.x = ts.XMIN;
		ts.y = y + 15;

		for (SDL_Surface* s : ts.surfaces) {
			// cout << "FREEING: " << s << endl;
			SDL_FreeSurface(s);
		}
		for (Entity* e : ts.letters) {
			// cout << "FREEING: " << e << endl;
			delete e;
		}

		ts.surfaces.clear();
		ts.letters.clear();

		ts.frames = 0;
		ts.sound = 0;
		ts.waveMod = 0;
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