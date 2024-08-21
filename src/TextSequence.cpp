#include "TextSequence.hpp"

TextSequence::TextSequence(vector<TextBox> t, map<char, Mix_Chunk*>* s) : text(t) {
	for (TextBox& tb : text) {
		for (TextSlice& ts : tb.text) {
			if (ts.sounds == nullptr) {
				ts.sounds = s;
			}
		}
	}
}

bool TextSequence::draw(RenderWindow& window) {
	bool next = text[curIndex].draw(window);
	if (next) {
		curIndex++;
	}
	return curIndex == text.size();
}

void TextSequence::reset() {
	curIndex = 0;
	for (TextBox& tb : text) {
		tb.reset();
	}
}