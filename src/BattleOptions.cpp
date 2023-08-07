#include "BattleOptions.hpp"

BattleOptions::BattleOptions(RenderWindow& window) {
	setTexture(window.loadTexture("res/gfx/Battle/BattleOptions.png"));
	fullPicSize();

	double scalingSize = RenderWindow::WIDTH / width;
	show_width = RenderWindow::WIDTH;
	show_height = height * scalingSize;
	x = 0;
	y = RenderWindow::HEIGHT - show_height;
	setRect();

//	select = new Entity();
}