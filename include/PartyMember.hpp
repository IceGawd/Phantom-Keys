#pragma once

#include "Fightable.hpp"

struct PartyMember : public Fightable {
	Move* moveEntered = nullptr;
	virtual void battle(RenderWindow* window, Fightable* turn);
	void doAttack(RenderWindow* window, Fightable* enemy);
};
