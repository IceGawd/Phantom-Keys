#include "BuffType.hpp"

BuffType::BuffType(string n, string d, bool b) {
	name = n;
	description = d;
	buff = b;
}

void BuffType::effect(int level, Fightable c) {

}

bool BuffType::operator==(BuffType& bt) {
	return name == bt.name;
}