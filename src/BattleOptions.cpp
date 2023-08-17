#include "BattleOptions.hpp"

BattleOptions::BattleOptions(RenderWindow& window) {
	setTexture(window.loadTexture("res/gfx/Battle/BattleOptions.png"));
	fullPicSize();

	scalingSize = 1.0 * RenderWindow::WIDTH / width;
	show_width = RenderWindow::WIDTH;
	show_height = height * scalingSize;
	x = 0;
	y = RenderWindow::HEIGHT - show_height;
	setRect();
	cout << "width: " << width << " height: " << height << endl;
	cout << "show_width: " << show_width << " show_height: " << show_height << endl;

	topY = y + 175 * scalingSize;
	select = new Entity(0, topY, window.loadTexture("res/gfx/Battle/note.png"));
	double noteScale = (15.0 / select->width) * scalingSize;
	select->show_width = select->width * noteScale;
	select->show_height = select->height * noteScale;
}

void BattleOptions::customDraw(RenderWindow* window) {	
	arrowChange(window, SDL_SCANCODE_W, &prevUp, &boDecrement, this);
	arrowChange(window, SDL_SCANCODE_S, &prevDown, &boIncrement, this);
	arrowChange(window, SDL_SCANCODE_RETURN, &prevEnter, &boSelect, this);
	if (selection < 0) {
		selection = 0;
	}
	if (selection == options.size()) {
		selection = options.size() - 1;
	}

	select->y = topY + selection * 22 * scalingSize;
	// cout << select->y << endl;
	window->render(select);
	for (int x = 0; x < options.size(); x++) {
		window->drawScaledTextInBox(options[x], 255, 255, 255, 255, 31 * scalingSize, y + (175 + 24 * x) * scalingSize, 156 * scalingSize, 20 * scalingSize);
	}
}

void boIncrement(void* passingArgument) {
	BattleOptions* bo = (BattleOptions*) passingArgument;
	bo->selection++;
}

void boDecrement(void* passingArgument) {
	BattleOptions* bo = (BattleOptions*) passingArgument;
	bo->selection--;
}

void boSelect(void* passingArgument) {
	BattleOptions* bo = (BattleOptions*) passingArgument;
	bo->pm->moveEntered = bo->pm->moves.at(bo->selection);
}