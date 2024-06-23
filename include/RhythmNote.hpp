#pragma once

#include <chrono>
#include "GameObject.hpp"

struct RhythmNote : public GameObject {
	const static int KEYSIZE = 40;
	const static int NOTEX = 200;
	const static int FRAMESADVANCE = 60;
	const static int NOTEY = 50;
	constexpr static double SPEED = 1.0 * (RenderWindow::WIDTH - NOTEX) / FRAMESADVANCE;

	int frame;
	NoteType nt;
	chrono::steady_clock::time_point* start;
	// int curFrames = 0;

	RhythmNote(RenderWindow* window, pair<int, NoteType> note, chrono::steady_clock::time_point* s);
	virtual bool draw(RenderWindow* window, World* world, vector<GameObject*>& entities);
};
