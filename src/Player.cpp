#include "Player.hpp"
#include "World.hpp"

InputLinkedList::InputLinkedList(int i) {
	input = i;
}

InputLinkedList::~InputLinkedList() {
	if (prev != nullptr) {
		prev->next = next;
	}
	if (next != nullptr) {
		next->prev = prev;
	}
}

InputLinkedList* pushBack(InputLinkedList* ill, int i) {
	InputLinkedList* ret = ill->next;
	InputLinkedList* val = find(ill, i);

	if (val != ill) {
		ret = ill;		
	}
	delete val;

	InputLinkedList* last = ill;

	while (last->next != nullptr) {
		last = last->next;
	}

	last->next = new InputLinkedList(i);
	last->next->prev = last;

	return ret;
}

InputLinkedList* find(InputLinkedList* ill, int i) {
	InputLinkedList* val = ill;

	while (val->input != i) {
		val = val->next;
	}

	return val;
}

InputLinkedList* pullForward(InputLinkedList* ill, int i) {
	InputLinkedList* val = find(ill, i);

	if (ill == val) {
		ill = val->next;
	}

	delete val;
	return addInput(ill, i);
}

InputLinkedList* addInput(InputLinkedList* ill, int i) {
	InputLinkedList* val = new InputLinkedList(i);

	val->next = ill;

	if (ill != nullptr) {
		ill->prev = val;
	}

	return val;
}

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

	ill = addInput(ill, 2);
	ill = addInput(ill, 1);
	ill = addInput(ill, 4);
	ill = addInput(ill, 3);
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

void Player::act(RenderWindow* window, World* world, vector<GameObject*>& entities) {
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

		if (!previnput.right == input.right) {
			if (input.right) {
				// cout << "pressed right\n";
				ill = pullForward(ill, 1);
				if (input.left) {
					ill = pushBack(ill, 3);
				}
			}
			else {
				// cout << "released right\n";
				// ill = pushBack(ill, 1);
				if (input.left) {
					ill = pullForward(ill, 3);
				}
			}
			changeDirection();
			column = 0;
		}
		if (!previnput.up == input.up) {
			if (input.up) {
				// cout << "pressed up\n";
				ill = pullForward(ill, 2);
				if (input.down) {
					ill = pushBack(ill, 4);
				}
			}
			else {
				// cout << "released up\n";
				// ill = pushBack(ill, 2);
				if (input.down) {
					ill = pullForward(ill, 4);
				}
			}
			changeDirection();
			column = 0;
		}
		if (!previnput.left == input.left) {
			if (input.left) {
				// cout << "pressed left\n";
				ill = pullForward(ill, 3);
				if (input.right) {
					ill = pushBack(ill, 1);
				}
			}
			else {
				// cout << "released left\n";
				// ill = pushBack(ill, 3);
				if (input.right) {
					ill = pullForward(ill, 1);
				}
			}
			changeDirection();
			column = 0;
		}
		if (!previnput.down == input.down) {
			if (input.down) {
				// cout << "pressed down\n";
				ill = pullForward(ill, 4);
				if (input.up) {
					ill = pushBack(ill, 2);
				}
			}
			else {
				// cout << "released down\n";
				// ill = pushBack(ill, 4);
				if (input.up) {
					ill = pullForward(ill, 2);
				}
			}
			changeDirection();
			column = 0;
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

	window->x = x - (RenderWindow::WIDTH - show_width) / 2;
	window->y = y - (RenderWindow::HEIGHT - show_height) / 2;

	previnput = input;

	setRect();
}

bool Player::draw(RenderWindow* window, World* world, vector<GameObject*>& entities) {
	window->render(this);

	// Check properties lol
	/*
	InputLinkedList* temp = ill;
	cout << "Forward check\n";
	while (temp->next != nullptr) {
		cout << temp->input << " ";
		temp = temp->next;
	}
	cout << temp->input << endl;

	cout << "Backwards check\n";
	while (temp->prev != nullptr) {
		cout << temp->input << " ";
		temp = temp->prev;
	}
	cout << temp->input << endl;
	// */

	return false;
}

void Player::changeDirection() {
	bool noVert = (input.right && input.left);
	bool noHori = (input.up && input.down);

	if (noVert != noHori) {
		if (noVert) {
			if (input.up) {
				row = 2;
				return;
			}
			if (input.down) {
				row = 4;
				return;
			}
		}
		if (noHori) {
			if (input.right) {
				row = 1;
				return;
			}
			if (input.left) {
				row = 3;
				return;
			}
		}
	}
	// */

	// cout << "SET DIRECTION: " << ill->input << " <<<<<<<<<<<<<<<<<<<" << endl;

	row = ill->input;
}