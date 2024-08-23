#include "Player.hpp"
#include "World.hpp"

// Player Init
Player::Player(RenderWindow* window, vector<Move*> m) {
	stats = Stats(12, 4, 8, 2, 4, 4);

	speed = 2;
	traction = 0.7;

	sheets["overworld"] = SpriteSheet(window->loadTexture("res/gfx/Overworld/Keyboard.png"), 4, 5, 10);
	sheets["buff"] = SpriteSheet(window->loadTexture("res/gfx/Battle/KeyboardBuff.png"), 7, 1, 1);
	sheets["swords"] = SpriteSheet(window->loadTexture("res/gfx/Battle/KeyboardSwords.png"), 12, 1, 1);
	sheets["battleidle"] = SpriteSheet(window->loadTexture("res/gfx/Battle/KeyboardIdle.png"), 6, 1, 10);

	changeSpriteSheet("overworld");
	
	row = 0;
	column = 3;

	moves = m;
}

void interactCheck(vector<void*> vv) {
	// cout << "INTERACTCHECK! <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";

	Player* player = (Player*) vv[0];
	World* world = (World*) vv[1];
	RenderWindow* window = (RenderWindow*) vv[2];

	float facingAngle;
	if (player->row == 0) {
		facingAngle = M_PI * player->column / 2;
	}
	else {
		facingAngle = M_PI * (player->row - 1) / 2;
	}

	Interactable* closest = nullptr;
	float diff = 0;

	for (Interactable* i : world->current->interactables) {
		float x = i->rect.x + i->rect.w / 2.0 - player->getHitbox().x - player->getHitbox().w / 2.0;
		float y = i->rect.y + i->rect.h / 2.0 - player->getHitbox().y - player->getHitbox().h / 2.0;

		// cout << "x: " << x << " y: " << y << endl;

		float angle = angleFromCoords(x, y);
		// cout << "facingAngle: " << facingAngle << " angle: " << angle << endl;
		// cout << "angleDiff(angle, facingAngle): " << angleDiff(angle, facingAngle) << endl;
		if (angleDiff(angle, facingAngle) < M_PI / 4) {
			// cout << "gettingDist\n";
			float dist = distanceFrom(x, y);
			// cout << "dist: " << dist << endl;
			if (dist < distanceFrom((i->rect.w + player->getHitbox().w) / 2.0, (i->rect.h + player->getHitbox().h) / 2.0)) {
				if (closest == nullptr || diff > dist * angle) {
					closest = i;
					diff = dist * angle;
				}
			}
		}
	}

	// cout << "checking\n";

	if (closest != nullptr) {
		// cout << "resetting\n";
		// cout << "PLAY THIS TEXT: " << closest << endl;
		// cout << "PLAY THIS TEXT: " << closest->interactText << endl;
		// cout << "PLAY THIS TEXT: " << closest->interactText->text.size() << endl;
		// cout << "PLAY THIS TEXT: " << closest->interactText->text[0].text.size() << endl;
		// cout << "PLAY THIS TEXT: " << closest->interactText->text[0].text[0].text << endl;
		closest->interactText->reset();
		window->ts = closest->interactText;
	}
}

bool Player::draw(RenderWindow* window, World* world, vector<GameObject*>& entities) {
	Collideable::draw(window, world, entities);

	if (window->playerInput) {
		arrowChange(window, window->cc.up, &input.up, nullptr, {});
		arrowChange(window, window->cc.left, &input.left, nullptr, {});
		arrowChange(window, window->cc.right, &input.right, nullptr, {});
		arrowChange(window, window->cc.down, &input.down, nullptr, {});
		arrowChange(window, window->cc.okay, &input.okay, interactCheck, {this, world, window});

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
	}
	else {
		xvel = 0;
		yvel = 0;
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