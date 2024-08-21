#pragma once

#include <chrono>
#include "GameObject.hpp"

struct RhythmNote : public GameObject {
	const static int KEYSIZE = 40;
	const static int NOTEX = 200;
	const static int FRAMESADVANCESPELL = 60;
	const static int FRAMESADVANCEDEFEND = 30;
	const static int NOTEY = 50;
	constexpr static double SPEEDSPELL = 1.0 * (RenderWindow::WIDTH - NOTEX) / FRAMESADVANCESPELL;
	constexpr static double SPEEDDEFEND = 1.0 * (RenderWindow::WIDTH - NOTEX) / FRAMESADVANCEDEFEND;

	int frame;
	NoteType nt;
	chrono::steady_clock::time_point* start;
	// int curFrames = 0;

	RhythmNote(RenderWindow* window, pair<int, NoteType> note, chrono::steady_clock::time_point* s);
	virtual bool draw(RenderWindow* window, World* world, vector<GameObject*>& entities);
};
