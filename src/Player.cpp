#include "Player.hpp"
#include "World.hpp"

Player::Player(RenderWindow* window, vector<Move*> m) {
	stats = Stats(60, 20, 40, 10, 30, 20);

	speed = 2;
	traction = 0.7;

	sheets["overworld"] = SpriteSheet(window->loadTexture("res/gfx/Overworld/Keyboard.png"), 4, 5, 10);
	sheets["battleidle"] = SpriteSheet(window->loadTexture("res/gfx/Battle/KeyboardIdle.png"), 6, 1, 10);

	changeSpriteSheet("overworld");
	
	row = 0;
	column = 3;

	moves = m;
}

bool Player::draw(RenderWindow* window, World* world, vector<GameObject*>& entities) {
	Collideable::draw(window, world, entities);

	if (window->playerInput) {
		double diagDirect = (input.diagonal()) ? 1 / sqrt(2) : 1;

		if (input.up) {
			yvel -= speed * diagDirect;
		}
		if (input.down) {
			yvel += speed * diagDirect;
		}
		if (input.left) {
			xvel -= speed * diagDirect;
		}
		if (input.right) {
			xvel += speed * diagDirect;
		}

		xvel *= traction;
		yvel *= traction;

		if (input.noMovement()) {
			if (row != 0) {
				column = row - 1;
				row = 0;
			}
		}
		else {
			if (!previnput.right == input.right) {
				if (input.right) {
					row = 1;
				}
				else {
					changeDirection(input);
				}
				column = 0;
			}
			if (!previnput.up == input.up) {
				if (input.up) {
					row = 2;
				}
				else {
					changeDirection(input);
				}
				column = 0;
			}
			if (!previnput.left == input.left) {
				if (input.left) {
					row = 3;
				}
				else {
					changeDirection(input);
				}
				column = 0;
			}
			if (!previnput.down == input.down) {
				if (input.down) {
					row = 4;
				}
				else {
					changeDirection(input);
				}
				column = 0;
			}
		}
	}

	float currSpeed = sqrt(pow(xvel, 2) + pow(yvel, 2));
	float ch = currSpeed / (speed * traction / (1 - traction));
	frames += ch;
	while (frames >= next->frames) {
		frames -= next->frames;
		if (row != 0) {
			column++;
			if (column == 4) {
				column = 0;
			}
		}
	}

	GameObject::draw(window, world, entities);
	world->current->collision(*window, this);

	previnput = input;

	setRect();
	window->render(this);

	return false;
}

void Player::changeDirection(Input& input) {
	if (input.right) {
		row = 1;
	}
	if (input.up) {
		row = 2;
	}
	if (input.left) {
		row = 3;
	}
	if (input.down) {
		row = 4;
	}
}