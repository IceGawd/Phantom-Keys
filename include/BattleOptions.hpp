#pragma once

#include "RenderWindow.hpp"

struct BattleOptions : public Entity {
	Entity* select;

	BattleOptions(RenderWindow& window);
};
