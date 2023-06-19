#pragma once

#include <string>

#include "Fightable.hpp"

using namespace std;

struct BuffType {
	string name;
	string description;
	bool buff;

	BuffType(string n, string d, bool b);
	bool operator==(BuffType& bt);
	virtual void effect(int level, Fightable c); // called every turn
};