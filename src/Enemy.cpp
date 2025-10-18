#include "Enemy.hpp"
#include "World.hpp"
#include "Move.hpp"

#include <algorithm>

Enemy::Enemy(RenderWindow* window, EnemyType* e, int x, int y, Player* p) : et(e), homex(x), homey(y), player(p) {
	this->x = x;
	this->y = y;

	// cout << "i live\n";
	// cout << "x: " << x << endl;
	// cout << "y: " << y << endl;

	sheets["overworld"] = SpriteSheet(window->loadTexture(et->path.c_str()), et->width, et->height, 10);
	changeSpriteSheet("overworld");

	this->y -= show_height;
	stats = e->stats;
	moves = e->moves;
}

// TODO: Don't draw when player is not near the entity
bool Enemy::draw(RenderWindow* window, World* world, vector<GameObject*>& entities) {
	// cout << "drawn\n";
	// /*
	Collideable::draw(window, world, entities);

	float playerDist = player->distance(this);
	float homeDist = distanceFrom(homex - x - show_width / 2, homey - y - show_height / 2);

	// cout << "x: " << x << " y: " << y << endl;
	// cout << "movement_angle: " << movement_angle << endl;

	float targetX = player->x + player->show_width / 2;
	float targetY = player->y + player->show_height / 2;

	if (et->lead_enabled) {
		// estimate intercept time: distance / (enemy max speed + eps)
		float ex = (player->x - (x + show_width / 2));
		float ey = (player->y - (y + show_height / 2));
		float dist = sqrt(ex * ex + ey * ey);
		float estTime = dist / max(0.001f, et->max_speed);
		estTime = min(estTime, et->max_intercept_time);

		// if player has velocity fields, use them; else assume 0
		targetX += player->xvel * estTime;
		targetY += player->yvel * estTime;
	}

	float dx = targetX - (x + show_width / 2);
	float dy = targetY - (y + show_height / 2);
	float angleTo = angleFromCoords(dx, dy); // same convention you used elsewhere

	float angleDiff = angleTo - movement_angle;
	// wrap to [-PI, PI]
	while (angleDiff > M_PI) angleDiff -= 2.0f * M_PI;
	while (angleDiff < -M_PI) angleDiff += 2.0f * M_PI;

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
	float desiredSpeed = et->passive_speed;
	float desiredAngleSpeed = et->turn_kp * angle_speed;
	if (passive) {
		desiredSpeed = (speed + et->passive_speed) / 2;
		if (random() < pow(homeDist / et->homeradius, 2)) {
			// cout << "take me home: " << angleFromCoords(homex - x - show_width / 2, homey - y - show_height / 2) << endl;

			if (angleFromCoords(homex - x - show_width / 2, homey - y - show_height / 2) > movement_angle) {
				desiredAngleSpeed = et->max_angle_speed;
			}
			else {				
				desiredAngleSpeed = -et->max_angle_speed;
			}
		}
	}
	else {
		// base desire on chosen movement type (retain your mt logic if you want)
		// but factor in facing: when angleDiff is small, allow max speed
		float faceFactor = 1.0 - (abs(angleDiff) / M_PI); // 1 when facing, 0 when opposite
		faceFactor = max(faceFactor, et->min_face_speed_factor); // never fully stop sideways

		// distance factor (closer => maybe slow down so it doesn't overshoot)
		float closeFactor = 1.0f;
		float closeValue = sqrt(pow(player->show_width + show_width, 2) + pow(player->show_height + show_height, 2));
		if (playerDist < closeValue) { // tweak the 64 threshold to your collision size
			closeFactor = playerDist / closeValue; // 0..1
		}

		// combine: prefer sprint behavior if aligned and not too close
		if (et->mt == SPRINT) {
			desiredSpeed = et->passive_speed + (et->max_speed - et->passive_speed) * faceFactor * closeFactor;
		} else if (et->mt == ACCELERATING) {
			// give a smooth acceleration curve
			float pct = clamp((playerDist / (et->homeradius + 1.0f)), 0.0f, 1.0f);
			desiredSpeed = et->passive_speed + (et->max_speed - et->passive_speed) * (1.0f - pow(1.0f - pct, 2.0f)) * faceFactor;
		} else {
			desiredSpeed = et->max_speed * faceFactor * closeFactor;
			desiredSpeed = max(desiredSpeed, et->passive_speed);
		}

		// --- angle speed control: proportional + clamp ---
		desiredAngleSpeed = et->turn_kp * angleDiff; // P controller
		// clamp
		if (desiredAngleSpeed > et->max_angle_speed) desiredAngleSpeed = et->max_angle_speed;
		if (desiredAngleSpeed < -et->max_angle_speed) desiredAngleSpeed = -et->max_angle_speed;
	}

	if (desiredSpeed < 0) {
		desiredSpeed = 0;
	}
	speed = speed + (desiredSpeed - speed) * et->speed_lerp;
	angle_speed = angle_speed * et->turn_damp + desiredAngleSpeed * (1.0 - et->turn_damp);

	// /*
	// Fun randomness to spice up the AI
	speed += (float) ((random() - 0.5) / (et->max_speed * et->chaos));
	angle_speed += (float) ((random() - 0.5) / (et->max_angle_speed * et->chaos));
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

	float movement_angle_cos = cos(movement_angle);

	if (movement_angle_cos < -0.1) {
		flip = 0;
	}
	if (movement_angle_cos > 0.1) {
		flip = 8;
	}
	
	xvel = movement_angle_cos * speed;
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

	SDL_Rect a = getRect();
	SDL_Rect b = player->getRect();
	SDL_Rect i;

	// cout << "final checks\n";

	if (SDL_IntersectRect(&a, &b, &i) == SDL_TRUE && playerDist < (min(player->show_height, player->show_width) + min(show_height, show_width)) / 2) {
		window->gamestate = BATTLETRANSITION;
		return true;
	}

	return false;
}

void Enemy::changeSpriteSheet(string newSheet) {
	GameObject::changeSpriteSheet("overworld");
	/*
	if (newSheet == "battleidle") {
		GameObject::changeSpriteSheet("overworld");		
	}
	else {
		GameObject::changeSpriteSheet(newSheet);
	}
	*/
}

void Enemy::battle(RenderWindow* window, Fightable* turn, vector<GameObject*>& battleEntities) {
	if (turn == this && window->turnstate == CHOOSEOPTION) {
		// cout << "Enemy Attacks!\n";
		moveEntered = moves.at((int) (moves.size() * random()));
		target = window->playerTeam.at((int) (window->playerTeam.size() * random()));
		// cout << "donemove\n";
		window->revert = ENDTURN;
		window->turnstate = ANIMATION;
	}

	Fightable::battle(window, turn, battleEntities);
}