#include "RhythmNote.hpp"

RhythmNote::RhythmNote(RenderWindow* window, pair<int, int> note, chrono::steady_clock::time_point* s) {
	frame = note.first;
	nt = note.second;
	start = s;

	SDL_Texture* ptexture;
	
	if (NOTE_TYPE_MAP["UP"] == nt) {
		y = RenderWindow::HEIGHT - 4 * KEYSIZE - NOTEY;
		ptexture = window->loadTexture("res/gfx/Battle/RhythmUI/up.png");
	}
	else if (NOTE_TYPE_MAP["LEFT"] == nt) {
		y = RenderWindow::HEIGHT - 2 * KEYSIZE - NOTEY;
		ptexture = window->loadTexture("res/gfx/Battle/RhythmUI/left.png");
	}
	else if (NOTE_TYPE_MAP["RIGHT"] == nt) {
		y = RenderWindow::HEIGHT - 3 * KEYSIZE - NOTEY;
		ptexture = window->loadTexture("res/gfx/Battle/RhythmUI/right.png");
	}
	else if (NOTE_TYPE_MAP["DOWN"] == nt) {
		y = RenderWindow::HEIGHT - KEYSIZE - NOTEY;
		ptexture = window->loadTexture("res/gfx/Battle/RhythmUI/down.png");
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