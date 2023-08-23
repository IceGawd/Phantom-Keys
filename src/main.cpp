#include "World.hpp"
#include "TextSequence.hpp"
#include "Enemy.hpp"
#include "BattleOptions.hpp"
#include "Selector.hpp"
#include "HealthBar.hpp"

#include <chrono>
#include <queue>

using namespace std;

map<char, Mix_Chunk*> getChunks(string s) {
	map<char, Mix_Chunk*> answer;
	string path = "res/Sounds/SFX/UI/Text/" + s + "/";
	char letter = 'a';
	for (int x = 0; x < 26; x++) {
		answer[letter] = Mix_LoadWAV((path + string(1, letter) + ".wav").c_str());
		letter += 1;
	}
	return answer;
}

void backout(vector<void*> passingArgument) {
	RenderWindow* window = (RenderWindow*) (passingArgument[0]);
	BattleOptions* bo = (BattleOptions*) (passingArgument[1]);
	Selector* selector = (Selector*) (passingArgument[2]);
	window->turnstate = (Turnstate) ((int) window->turnstate - 1);
	bo->options.clear();
	bo->prevEnter = true;
	selector->snap = true;
	selector->prevEnter = true;
	if (window->turnstate == CHOOSEMOVE) {
		bo->pm->moveEntered = nullptr;
	}
}

void forward(vector<void*> passingArgument) {
	RenderWindow* window = (RenderWindow*) (passingArgument[0]);
	BattleOptions* bo = (BattleOptions*) (passingArgument[1]);
	window->turnstate = (Turnstate) ((int) window->turnstate + 1);
	bo->options.clear();
}

int main(int argc, char *argv[]) {
	const int FPS = 60;
	int fastForward = 1;
	SDL_Event event;
	bool gameRunning = true;

	srand((unsigned) time(NULL));
	if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0) {
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
	}
	if (!IMG_Init(IMG_INIT_PNG)) {
		cout << "IMG PNG Failure: " << SDL_GetError() << "\n";
	}
	if(TTF_Init() == -1) {
	    cout << "TTF_Init: " << TTF_GetError() << endl;
	}
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 8, 2048) < 0) {
		cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << "\n";
	}

	RenderWindow window("Phantom Keys");

	map<string, map<char, Mix_Chunk*>> textNoise = {
		{"Flute", getChunks("Flute")}, 
		{"Trumpet", getChunks("Trumpet")}, 
	};

	map<string, Move*> moves = {
		{"Scratch", new Move("Scratch", 10, 0, true, true, 1, {SLASHING})}, 
		{"Ram", new Move("Ram", 30, 0, true, false, 2, {BLUDGEONING, FORWARD})}, 
		{"16th Notes", new Move("16th Notes", 10, 25, false, false, 2, {FORCE, FORWARD}, true, 4)}, 
		{"Vibrato", new Move("Vibrato", 20, 10, false, true, 1, {VIBRATING})}
	};

	// /*
	map<string, EnemyType*> enemyTypes = {
		{"Tuba Snail", new EnemyType(
			"Tuba Snail", 
			Stats(1, 2, 2, 1, 2, 2), 
			{moves.find("Scratch")->second, moves.find("Ram")->second, moves.find("16th Notes")->second, moves.find("Vibrato")->second}, 
			3, 2, 0.1, 0.01, ACCELERATING, 200, 500, true, 
			"res/gfx/Enemies/TubaSnail.png", 7, 1)
		}
	};
	// */

	vector<EnemyType*> etVec;
	for (auto it = enemyTypes.begin(); it != enemyTypes.end(); ++it) {
		etVec.push_back(it->second);
	}

	Player* player = new Player(&window, {moves.find("Scratch")->second, moves.find("Ram")->second, moves.find("16th Notes")->second, moves.find("Vibrato")->second});
	vector<GameObject*> overworldEntities;
	vector<GameObject*> battleEntities;

	overworldEntities.push_back(player); // PLAYER WAS DRAWN IN AREA RENDER (NOW EVERYTHING IS DRAWN THERE)
	window.playerTeam.push_back(player);

	World* world = new World(window, player, etVec);
	TextSequence* ts = nullptr;
	BattleOptions* bo = new BattleOptions(window);
	HealthBar* hb = new HealthBar(&window, 46 * bo->scalingSizeMain, bo->mainMenu->y + 5 * bo->scalingSizeMain, 390 * bo->scalingSizeMain, 45 * bo->scalingSizeMain);
	Selector* selector = new Selector(window);
	/*
	TextSequence* ts = new TextSequence({
		TextBox(window, {
			TextSlice(window, "Suck it samurai game Calder plays. ", {125, 125, 125, 255}, {DIAGONAL_RAINBOW}), 
			TextSlice(window, "That game can  suck my nuts. ", {255, 0, 255, 255}, {DIAGONAL_RAINBOW, WAVEY}), 
			TextSlice(window, "JK JK Its really cool. "), 
		}), 
		TextBox(window, {
			TextSlice(window, "Anyways, in between my bouts of ", {255, 255, 255, 255}), 			
			TextSlice(window, "college stress ", {255, 0, 0, 255}, {SHAKY}), 			
			TextSlice(window, "as my ", {255, 255, 255, 255}), 
			TextSlice(window, "acceptances ", {0, 255, 0, 255}), 
			TextSlice(window, "started rolling in, I programmed   ", {255, 255, 255, 255}), 
			TextSlice(window, "text stuff.", {255, 255, 255, 255}, {WAVEY}), 
		}), 
		TextBox(window, {
			TextSlice(window, "abcdefghijklmnopqrstuvwxyz", {125, 125, 125, 255}, {DIAGONAL_RAINBOW}), 
		}), 
		TextBox(window, {
			TextSlice(window, "perfect pitch people perfect pitch people perfect  pitch people perfect pitch people ", {125, 125, 125, 255}, {WAVEY}), 
		}), 
		TextBox(window, {
			TextSlice(window, "It was ", {255, 255, 255, 255}), 
			TextSlice(window, "really cool", {125, 125, 125, 255}, {DIAGONAL_RAINBOW, WAVEY}), 
			TextSlice(window, ".", {125, 125, 125, 255}), 
		}), 
		TextBox(window, {
			TextSlice(window, "Ghost moment", {125, 125, 125, 255}, {GHOST}), 
		}), 
		TextBox(window, {
			TextSlice(window, "Gay ghost moment", {125, 125, 125, 255}, {RAINBOW}), 
		}), 
		TextBox(window, {
			TextSlice(window, "Scary ghost moment", {125, 125, 125, 255}, {GHOST, SHAKY}), 
		}), 
		TextBox(window, {
			TextSlice(window, "Ghost Ghost Ghost Ghost Ghost", {125, 125, 125, 255}, {GHOST}), 
		}), 
		TextBox(window, {
			TextSlice(window, "The One PIEEEEEEEEEEEECE", {0, 0, 255, 255}, {SHAKY}), 
		}), 
		TextBox(window, {
			TextSlice(window, "THE ONE PIECE IS ", {255, 255, 255, 255}, {WAVEY}), 
			TextSlice(window, "REEEEEEEEEEEEAL", {255, 255, 255, 255}, {DIAGONAL_RAINBOW, WAVEY}), 
		})
	}, &textNoise["Trumpet"]);

	/*
	TextSequence* ts = new TextSequence({
		TextBox(window, {
			TextSlice(window, "ooooohh.....      ooooooohhhhhhhh... OOOOOHHH! ", {125, 125, 125, 255}, {DIAGONAL_RAINBOW, GHOST}), 
			TextSlice(window, "MWEE HEE HEE HEE YOU FOOL", {255, 0, 255, 255}, {DIAGONAL_RAINBOW, SHAKY})
		}), TextBox(window, {
			TextSlice(window, "EAT A SANDWICH SKINNY. MWEE HEE HEE!!!", {255, 0, 255, 255}, {DIAGONAL_RAINBOW, WAVEY})
		}), TextBox(window, {
			TextSlice(window, "By the way im gay :) ", {255, 255, 255, 255}, {RAINBOW}), 
			TextSlice(window, "Or bi but find out ;)", {255, 255, 255, 255}, {DIAGONAL_RAINBOW}), 
		})
	}, &textNoise["Trumpet"]);
	*/
	// TextSequence* ts = new TextSequence({TextBox(window, {TextSlice(window, "Hello every person type or thing, I need to make a long text to test out the scrolling features. ", {255, 255, 255, 255}, {WAVEY}), TextSlice(window, "Its ice god here", {0, 120, 200, 255}, {SHAKY})})}, &textNoise["Trumpet"]);

	bool prevBack = true;

	while (gameRunning) {
		auto start = chrono::steady_clock().now();

		for (int framesDone = 0; framesDone < fastForward; framesDone++) {
			// cout << "frame\n";
			window.clear();

			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {
					gameRunning = false;
				}
				SDL_Keycode kc = event.key.keysym.sym;
				if (event.type == SDL_KEYDOWN) {
					/*
					if (kc == SDLK_w) {
						player->input.up = true;
					}
					if (kc == SDLK_s) {
						player->input.down = true;
					}
					if (kc == SDLK_a) {
						player->input.left = true;
					}
					if (kc == SDLK_d) {
						player->input.right = true;
					}
					/*
					if (kc == SDLK_o) {
						cout << "zoomout\n";
						window.zoom /= 2;
					}
					if (kc == SDLK_p) {
						cout << "zoomin\n";
						window.zoom *= 2;
					}
					if (kc == SDLK_q) {
						cout << "temp\n";
						window.temp = !window.temp;
					}
					*/
				}
				if (event.type == SDL_KEYUP) {
					/*
					if (kc == SDLK_w) {
						player->input.up = false;
					}
					if (kc == SDLK_s) {
						player->input.down = false;
					}
					if (kc == SDLK_a) {
						player->input.left = false;
					}
					if (kc == SDLK_d) {
						player->input.right = false;
					}
					*/
					if (kc == SDLK_BACKQUOTE) {
						if (fastForward != 1) {
							fastForward = 1;
						}
						else {
							fastForward = 3;
						}
					}
				}
				if ((event.type == SDL_WINDOWEVENT) && (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)) {
					window.resizeWindow();
				}
			}

			if (window.gamestate == OVERWORLD) {
				// CAMERA
				window.x = player->x - (RenderWindow::WIDTH - player->show_width) / 2;
				window.y = player->y - (RenderWindow::HEIGHT - player->show_height) / 2;

				world->current->render(window, player, world, overworldEntities);

				if (window.gamestate == BATTLE) {
					while (!battleEntities.empty()) {
						delete battleEntities.at(0);
					}
				}
			}
			else if (window.gamestate == BATTLE) {
				window.render(world->current->battleBackground);
				for (GameObject* go : battleEntities) {
					go->draw(&window, world, battleEntities);
					battleEntities.erase(battleEntities.begin());
				}
				Fightable* myTurn = window.turnOrder.front();

				bool playerTurn = false;
				// cout << "a\n";
				for (Enemy* go : window.enemyTeam) {
					go->battle(&window, myTurn);
					// cout << "b\n";
				}
				// cout << "c\n";
				for (Fightable* go : window.playerTeam) {
					go->battle(&window, myTurn);
					playerTurn = playerTurn || (go == myTurn);
					// cout << "d\n";
				}
				// cout << "e\n";

				if (playerTurn) {
					// cout << "f\n";
					if ((int) window.turnstate <= 3 && (int) window.turnstate > 0) {
						arrowChange(&window, window.cc.back, &prevBack, &backout, {&window, bo, selector});
					}
					if (window.turnstate == HEALTHCHECK) {
						if (!bo->options.empty()) {
							bo->options.clear();
						}
						bo->customDraw(&window);
						selector->render(&window);
						hb->represent(&window, selector->getSelected(&window));
						arrowChange(&window, window.cc.back, &prevBack, &forward, {&window, bo});
					}
					else if (window.turnstate == CHOOSEOPTION) {
						if (bo->options.empty()) {
							bo->selection = 0;
							bo->options.push_back("Fight");
							bo->options.push_back("Item");
							bo->options.push_back("Action");
						}
						bo->pm = (PartyMember*) (window.turnOrder.front());
						bo->customDraw(&window);
						hb->represent(&window, window.turnOrder.front());
					}
					else if (window.turnstate == CHOOSEMOVE) {
						if (bo->options.empty()) {
							for (Move* m : bo->pm->moves) {
								bo->options.push_back(m->name);
							}
						}
						bo->customDraw(&window);
					}
					else if (window.turnstate == SELECTENEMY) {
						selector->render(&window);
					}
				}
				if (window.turnstate == ENDTURN) {
					// cout << "g\n";
					selector->snap = true;
					bool fighterLoss = true;
					bool fighterWin = true;
					for (Fightable* f : window.playerTeam) {
						cout << "Fighter hp: " << f->stats.hp << endl;
						fighterLoss = fighterLoss && (f->stats.hp <= 0);
					}
					for (Enemy* e : window.enemyTeam) {
						cout << "Enemy hp: " << e->stats.hp << endl;						
						fighterWin = fighterWin && (e->stats.hp <= 0);
					}
					if (fighterLoss) {
						cout << "YOU LOSE!\n";
						gameRunning = false;
					}
					else if (fighterWin) {
						cout << "YOU WIN!\n";
						window.gamestate = OVERWORLD;
						window.x = window.savedX;
						window.y = window.savedY;
						window.zoom = window.savedZoom;
						player->changeSpriteSheet("overworld");
						while (!window.enemyTeam.empty()) {
							// cout << "again" << endl;
							Enemy* e = window.enemyTeam.at(0);
							// cout << "deleting " << e << endl;
							overworldEntities.erase(remove(overworldEntities.begin(), overworldEntities.end(), e));
							e->zone->dudes.erase(remove(e->zone->dudes.begin(), e->zone->dudes.end(), e));
							e->zone->spawned--;
							// cout << "pre delete call\n";
							delete e;
							// cout << "post delete call\n";
							window.enemyTeam.erase(window.enemyTeam.begin());
							// cout << "erase enemies\n";
						}
						// window.enemyTeam.clear();
						// cout << "gone" << endl;
					}
					else {
						window.turnstate = CHOOSEOPTION;
						if (playerTurn) {
							bo->options.clear();
						}
						do {
							window.turnOrder.pop();
							window.turnOrder.push(myTurn);
						} while (window.turnOrder.front()->stats.hp <= 0);
					}
				}
				else {
					// /*
					for (int x = 0; x < window.enemyTeam.size(); x++) {
						Enemy* e = window.enemyTeam.at(x);
						if (e->stats.hp <= 0) {
							// cout << "deleted " << e << endl;
							overworldEntities.erase(remove(overworldEntities.begin(), overworldEntities.end(), e));
							e->zone->dudes.erase(remove(e->zone->dudes.begin(), e->zone->dudes.end(), e));
							e->zone->spawned--;
							window.enemyTeam.erase(remove(window.enemyTeam.begin(), window.enemyTeam.end(), e));
							delete e;
							x--;
						}
					}
					// */
				}
			}

			if (ts != nullptr) {
				// cout << "elc\n";
				window.playerInput = ts->draw(window);
				if (window.playerInput) {
					ts = nullptr;
				}
			}

			// cout << "player->x: " << player->x << " player->y: " << player->y << endl; 
		}

		window.display();

		// /*
		auto end = chrono::steady_clock().now();
		chrono::duration<double> frameDone = end - start;

		double delay = 1000 * ((1.0 / FPS) - frameDone.count());
		// cout << "delay: " << delay << endl;
		if (delay > 0) {
			SDL_Delay(delay);
		}
		// */
	}

	return 0;
}