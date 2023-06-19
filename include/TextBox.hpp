#pragma once

#include <vector>

#include "TextSlice.hpp"

using namespace std;

struct TextBox : public Entity {
	const float zoom = 4;
	vector<TextSlice> text;
	int curIndex = 1;
	bool prevHeld = true;

	TextBox(RenderWindow& window, vector<TextSlice> t);
	bool draw(RenderWindow& window);
};