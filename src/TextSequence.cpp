#include "TextSequence.hpp"

TextSequence::TextSequence(vector<TextBox> t) : text(t) {

}

bool TextSequence::draw(RenderWindow& window) {
	bool next = text[curIndex].draw(window);
	if (next) {
		curIndex++;
	}
	return curIndex == text.size();
}