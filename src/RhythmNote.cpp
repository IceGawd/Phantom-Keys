#include "RhythmNote.hpp"

RhythmNote::RhythmNote(RenderWindow* window, pair<int, NoteType> note, chrono::steady_clock::time_point* s) {
	frame = note.first;
	nt = note.second;
	start = s;

	SDL_Texture* ptexture;
	switch (nt) {
		case UP:
			y = RenderWindow::HEIGHT - 4 * KEYSIZE - NOTEY;
			ptexture = window->loadTexture("res/gfx/Battle/RhythmUI/up.png");
			break;
		case LEFT:
			y = RenderWindow::HEIGHT - 2 * KEYSIZE - NOTEY;
			ptexture = window->loadTexture("res/gfx/Battle/RhythmUI/left.png");
			break;
		case RIGHT:
			y = RenderWindow::HEIGHT - 3 * KEYSIZE - NOTEY;
			ptexture = window->loadTexture("res/gfx/Battle/RhythmUI/right.png");
			break;
		case DOWN:
			y = RenderWindow::HEIGHT - KEYSIZE - NOTEY;
			ptexture = window->loadTexture("res/gfx/Battle/RhythmUI/down.png");
			break;
		case A:
			y = RenderWindow::HEIGHT - KEYSIZE - 4 * NOTEY;
			ptexture = window->loadTexture("res/gfx/Battle/RhythmUI/up.png");   // REPLACE WITH ACTUAL SPRITE
			break;
		case B:
			y = RenderWindow::HEIGHT - KEYSIZE - 2 * NOTEY;
			ptexture = window->loadTexture("res/gfx/Battle/RhythmUI/down.png"); // REPLACE WITH ACTUAL SPRITE
			break;
	}

	setTexture(ptexture);
	fullPicSize();
	show_width = KEYSIZE;
	show_height = KEYSIZE;
	setRect();
}

bool RhythmNote::draw(RenderWindow* window, World* world, vector<GameObject*>& entities) {
	// /*
	auto end = chrono::steady_clock().now();
	chrono::duration<double> len = end - *start;
	// cout << "count: " << len.count() << endl;
	double frameDone = len.count() * 60.0; // POTENTIAL ERROR: ASSUMES 60 FPS
	double frameDist = frame + FRAMESADVANCESPELL - frameDone;
	// cout << "frameDist1: " << frameDist << endl;
	// */

	/*
	frameDist = frame + FRAMESADVANCESPELL - curFrames;
	cout << "frameDist2: " << frameDist << endl;
	curFrames++;
	*/

	x = NOTEX + frameDist * SPEEDSPELL;

	// cout << "x: " << x << endl;

	if (x > 0 && x < RenderWindow::WIDTH) {
		setRect();
		window->render(this);
	}

	return GameObject::draw(window, world, entities);
}