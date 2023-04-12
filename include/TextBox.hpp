#pragma once

#include <vector>

#include "TextSlice.hpp"

using namespace std;

struct TextBox {
	vector<TextSlice> text;
	int curIndex = 0;
	bool prevHeld = true;

	TextBox(vector<TextSlice> t);
	bool draw(RenderWindow& window);
};