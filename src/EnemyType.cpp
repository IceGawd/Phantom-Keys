#include "EnemyType.hpp"

EnemyType::EnemyType(string n, map<string, Move*>& allMoves, const json& j) : name(n) {
	stats = Stats(
		j["stats"]["hp"], j["stats"]["atk"], j["stats"]["def"],
		j["stats"]["spd"], j["stats"]["mag"], j["stats"]["res"]
	);

	vector<string> moveNames = j["moves"].get<vector<string>>();
	for (string moveName : moveNames) {
		moves.push_back(allMoves[moveName]);
	}

	max_speed = j["max_speed"];
	passive_speed = j["passive_speed"];
	max_angle_speed = j["max_angle_speed"];
	passive_angle_speed = j["passive_angle_speed"];
	mt = (j["movement_type"] == "ACCELERATING") ? ACCELERATING : SPRINT;
	sightradius = j["sightradius"];
	homeradius = j["homeradius"];
	homeloyalty = j["homeloyalty"];
	turn_kp = j["turn_kp"];
	turn_damp = j["turn_damp"];
	speed_lerp = j["speed_lerp"];
	chaos = j["chaos"];
	path = j["sprite"];
	width = j["width"];
	height = j["height"];
}