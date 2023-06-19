#include "Collideable.hpp"

bool Collideable::draw(RenderWindow* window, World* world, vector<GameObject*>& entities) {
	prevx = x;
	prevy = y;

	return false;
}

SDL_Rect Collideable::getHitbox() {
	return {(int) x, (int) (y + 2 * show_height / 3), show_width, show_height / 3};
}

vector<Vector2f> Collideable::getPoints() {
	SDL_Rect rect = getHitbox();
	vector<Vector2f> points;
	points.push_back({float(rect.x), float(rect.y)});
	points.push_back({float(rect.x + rect.w), float(rect.y)});
	points.push_back({float(rect.x + rect.w), float(rect.y + rect.h)});
	points.push_back({float(rect.x), float(rect.y + rect.h)});
	return points;
}