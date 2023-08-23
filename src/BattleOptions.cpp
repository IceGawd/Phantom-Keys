#include "BattleOptions.hpp"
#include "Move.hpp"

BattleOptions::BattleOptions(RenderWindow& window) {
	makeMaxWidth(mainMenu, scalingSizeMain, window.loadTexture("res/gfx/Battle/BattleUIMainMenu.png"));
	makeMaxWidth(fightOptions, scalingSizeFight, window.loadTexture("res/gfx/Battle/BattleUIFightOptions.png"));

	select = new Entity(0, 0, window.loadTexture("res/gfx/Battle/note.png"));
	options.clear();
}

void BattleOptions::makeMaxWidth(Entity*& object, double& scalingSize, SDL_Texture* texture) {
	object = new Entity(0, 0, texture);

	scalingSize = 1.0 * RenderWindow::WIDTH / object->width;
	object->show_width = RenderWindow::WIDTH;
	object->show_height = object->height * scalingSize;
	object->y = RenderWindow::HEIGHT - object->show_height;
}

void BattleOptions::customDraw(RenderWindow* window) {
	if (window->turnstate == CHOOSEOPTION) {
		arrowChange(window, window->cc.left, &prevLeft, &boDecrement, {this});
		arrowChange(window, window->cc.right, &prevRight, &boIncrement, {this});
		arrowChange(window, window->cc.okay, &prevEnter, &boMainOptionSelect, {this, window});
		selectionLimiting();

		double noteScale = (22.0 / select->width) * scalingSizeMain;
		select->show_width = select->width * noteScale;
		select->show_height = select->height * noteScale;
		select->x = (45 + 134 * selection) * scalingSizeMain;
		select->y = mainMenu->y + 60 * scalingSizeMain;
		// cout << "x: " << select->x << " y: " << select->y << endl;
		window->render(mainMenu);
		for (int x = 0; x < options.size(); x++) {
			// cout << options[x] << " ";
			window->drawScaledTextInBox(options[x], 255, 255, 255, 255, (45 + 134 * x) * scalingSizeMain, mainMenu->y + 60 * scalingSizeMain, 130 * scalingSizeMain, 22 * scalingSizeMain, true);
		}
		// cout << endl;
	}
	if (window->turnstate == CHOOSEMOVE) {
		arrowChange(window, window->cc.up, &prevUp, &boUp, {this});
		arrowChange(window, window->cc.left, &prevLeft, &boDecrement, {this});
		arrowChange(window, window->cc.down, &prevDown, &boDown, {this});
		arrowChange(window, window->cc.right, &prevRight, &boIncrement, {this});
		arrowChange(window, window->cc.okay, &prevEnter, &boSelect, {this});
		selectionLimiting();

		double noteScale = (20.0 / select->width) * scalingSizeFight;
		select->show_width = select->width * noteScale;
		select->show_height = select->height * noteScale;
		// cout << select->y << endl;
		select->x = (15 + 120 * (selection % 2)) * scalingSizeFight;
		select->y = fightOptions->y + (5 + 26 * (selection / 2)) * scalingSizeFight;

		window->render(fightOptions);

		for (int x = 0; x < options.size(); x++) {
			int tempx = x % 2;
			int tempy = x / 2;
			window->drawScaledTextInBox(options[x], 255, 255, 255, 255, (25 + 120 * tempx) * scalingSizeFight, fightOptions->y + (6 + 27 * tempy) * scalingSizeFight, 100 * scalingSizeFight, 19 * scalingSizeFight, true);
		}
	}
	// cout << "selection: " << selection << endl;
	if (!options.empty()) {
		window->render(select);
	}
}

void BattleOptions::selectionLimiting() {
	if (selection < 0) {
		selection = 0;
	}
	if (selection >= options.size()) {
		selection = options.size() - 1;
	}
}

void boDecrement(vector<void*> passingArgument) {
	BattleOptions* bo = (BattleOptions*) (passingArgument[0]);
	bo->selection--;
}

void boIncrement(vector<void*> passingArgument) {
	BattleOptions* bo = (BattleOptions*) (passingArgument[0]);
	bo->selection++;
}

void boUp(vector<void*> passingArgument) {
	BattleOptions* bo = (BattleOptions*) (passingArgument[0]);
	if (bo->selection < 2) {
		bo->selection = 3 - bo->selection;
	}
	else {
		bo->selection -= 2;
	}
}

void boDown(vector<void*> passingArgument) {
	BattleOptions* bo = (BattleOptions*) (passingArgument[0]);
	if (bo->selection < 2) {
		bo->selection += 2;
	}
	else {
		bo->selection = 3 - bo->selection;
	}
}

void boSelect(vector<void*> passingArgument) {
	BattleOptions* bo = (BattleOptions*) (passingArgument[0]);
	bo->pm->moveEntered = bo->pm->moves.at(bo->selection);
	bo->options.clear();
}

void boMainOptionSelect(vector<void*> passingArgument) {
	BattleOptions* bo = (BattleOptions*) (passingArgument[0]);
	RenderWindow* window = (RenderWindow*) (passingArgument[1]);
	bo->options.clear();
	window->turnstate = CHOOSEMOVE;
	bo->selection = 0;
}