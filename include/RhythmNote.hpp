#pragma once

#include <chrono>
#include "GameObject.hpp"

struct RhythmNote : public GameObject {
	const static int KEYSIZE = 40;
	const static int NOTEX = 200;
	const static int FRAMESADVANCESPELL = 60;
	const static int NOTEY = 50;
	const static int LENIENCY = 75;
	constexpr static double SPEEDSPELL = 1.0 * (RenderWindow::WIDTH - NOTEX) / FRAMESADVANCESPELL;

	bool missed = false;
	int millisecond;
	double milliDist;
	int nt;
	chrono::steady_clock::time_point* start;
	// int curFrames = 0;

	RhythmNote(RenderWindow* window, pair<int, int> note, chrono::steady_clock::time_point* s);
	virtual bool draw(RenderWindow* window, World* world, vector<GameObject*>& entities);
};
