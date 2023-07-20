#pragma once

#include "Fightable.hpp"

struct PartyMember : public Fightable {
	virtual bool battle(RenderWindow* window, Fightable* turn);
};
