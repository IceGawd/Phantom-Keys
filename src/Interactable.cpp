#include "Interactable.hpp"

Interactable::Interactable(SDL_Rect r, TextSequence* i) : rect(r), interactText(i) {

}
Interactable::~Interactable() {
	delete interactText;
}