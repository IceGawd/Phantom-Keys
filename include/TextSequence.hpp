#pragma once

#include "TextBox.hpp"

using namespace std;

struct TextSequence {
	vector<TextBox> text;
	int curIndex = 0;

	TextSequence(vector<TextBox> t);
	bool draw(RenderWindow& window);
};