#include "Enemy.hpp"
#include "World.hpp"

Enemy::Enemy(RenderWindow* window, EnemyType* e, int x, int y, Player* p) : et(e), homex(x), homey(y), player(p) {
	this->x = x;
	this->y = y;

	cout << "i live\n";
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	sheets["overworld"] = SpriteSheet(window->loadTexture(et->path.c_str()), et->width, et->height, 10);
	changeSpriteSheet("overworld");

	y -= show_height;
}

bool Enemy::draw(RenderWindow* window, World* world, vector<GameObject*>& entities) {
	// cout << "drawn\n";
	// /*
	Collideable::draw(window, world, entities);

	float playerDist = distanceFrom(player->x - x - show_width / 2, player->y - y - show_height / 2);
	float homeDist = distanceFrom(homex - x - show_width / 2, homey - y - show_height / 2);

	// cout << "x: " << x << " y: " << y << endl;
	// cout << "movement_angle: " << movement_angle << endl;

	// Passive changes
	if (homeDist > et->homeradius) {
		passive = true;
		// cout << "im chillin\n";
		if (!et->homeloyalty) {
			homex = x;
			homey = y;
		}
	}
	if (playerDist < et->sightradius) {
		// cout << "im mad\n";
		passive = false;
	}

	// Passive or Active code
	if (passive) {
		speed = (speed + et->passive_speed) / 2;
		angle_speed = (angle_speed + et->passive_angle_speed) / 2;
		if (random() < pow(homeDist / et->homeradius, 2)) {
			// cout << "take me home: " << angleFromCoords(homex - x, homey - y) << endl;

			if (angleFromCoords(homex - x - show_width / 2, homey - y - show_height / 2) > movement_angle) {
				angle_speed = et->max_angle_speed;
			}
			else {				
				angle_speed = -et->max_angle_speed;
			}
		}
		if (speed < 0) {
			speed = 0;
		}
	}
	else {
		if (angleFromCoords(player->x - x - show_width / 2, player->y - y - show_height / 2) > movement_angle) {
			angle_speed += et->passive_angle_speed;
		}
		else {				
			angle_speed -= et->passive_angle_speed;
		}

		float percentile = (speed - et->passive_speed) / (et->max_speed - et->passive_speed);
		if (et->mt == ACCELERATING) {
			speed = (float) (pow(1.0 / (percentile - 0.5), 2));
		}
		if (et->mt == SPRINT) {
			speed = (float) ((et->max_speed - et->passive_speed) * pow(abs(percentile), 0.5) + et->passive_speed);
		}
		if (speed < et->passive_speed) {
			speed = et->passive_speed;
		}
	}

	// /*
	// Fun randomness to spice up the AI
	speed += (float) ((random() - 0.5) / (et->max_speed * 10));
	angle_speed += (float) ((random() - 0.5) / (et->max_angle_speed * 10));
	// */
	// Speed checks
	if (speed > et->max_speed) {
		speed = et->max_speed;
	}
	if (angle_speed > et->max_angle_speed) {
		angle_speed = et->max_angle_speed;
	}
	if (angle_speed < -et->max_angle_speed) {
		angle_speed = -et->max_angle_speed;
	}

	// Moving the enemy
	movement_angle += angle_speed;
	movement_angle = movement_angle - (2 * M_PI) * int(movement_angle / (2 * M_PI));
	if (movement_angle > M_PI / 2 && movement_angle < 3 * M_PI / 2) {
		flip = 0;
	}
	else {
		flip = 8;
	}

	xvel = cos(movement_angle) * speed;
	yvel = -sin(movement_angle) * speed;
	
	// cout << "PREV speed: " << speed << " angle: " << movement_angle << endl;

	frames++;
	if (frames > next->frames) {
		frames = 0;
		column++;
		if (column >= next->xFrames) {
			column = 0;
		}
	}

	GameObject::draw(window, world, entities);
	world->current->collision(*window, this);

	speed = distanceFrom(xvel, yvel);
	movement_angle = angleFromCoords(xvel, yvel);

	// cout << "AFTER speed: " << speed << " angle: " << movement_angle << endl;

	// */
	setRect();
	window->render(this);

	return false;
}