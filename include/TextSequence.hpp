#pragma once

#include "TextBox.hpp"

using namespace std;

struct TextSequence {
	vector<TextBox> text;
	int curIndex = 0;

	TextSequence(vector<TextBox> t, map<char, Mix_Chunk*>* s);
	bool draw(RenderWindow& window);
	void reset();
};