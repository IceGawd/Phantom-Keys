#include "World.hpp"
#include "TextSequence.hpp"
#include "Enemy.hpp"
#include "BattleOptions.hpp"
#include "Selector.hpp"
#include "HealthBar.hpp"
#include "mingw.thread.h"

#include <chrono>
#include <queue>

using namespace std;

float atanLookup(vector<void*> vv) {
	RenderWindow* window = (RenderWindow*) vv[0];
	float x = *((float*) vv[1]);

	int index = 127;
	int size = 128;
	pair<float, float> prev;
	bool bigger = false;
	
	pair<float, float> check;

	while (size > 0) {
		prev = check;
		check = window->atanSheet[index];
		if (check.first == x) {
			return check.second;
		}

		size /= 2;
		if (check.first > x) {
			index += size;
			bigger = false;
		}
		else {
			index -= size;
			bigger = true;
		}
	}

	if (bigger) {
		swap(prev, check); // Ensures check is bigger
	}
	float percent = ((check.first - x) / (check.first - prev.first));
	return (1 - percent) * check.second + percent * prev.second;
}

inline pair<int, int> flippedIndex(int num, vector<pair<int, int>>& degree45, int subtract = 0) {
	int actualNum = num % degree45.size();
	int falseNum = (num - actualNum) / degree45.size();
	if (falseNum % 2) { // REVERSE
		actualNum = degree45.size() - actualNum - 1;
	}
	int first = degree45[actualNum].first - subtract;
	int second = degree45[actualNum].second;
	if (((falseNum + 1) / 2) % 2) { // SWAP
		swap(first, second);
	}
	first = (((falseNum + 2) / 4) % 2) ? -first : first; // FIRST NEGATIVE
	second = ((falseNum / 4) % 2) ? -second : second; // SECOND NEGATIVE
	return {first, second};
}

inline bool inRange(int n, int s, int l) {
	return n > s && n < s + l;
}

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
	return {a.first + b.first, a.second + b.second};
}

void spiral(int rstart, int rend, int texrecx, int texrecy, int width, int height, int transitionFrames, Uint32* pixels, Uint32* newPixels, int maxRadius, int PIXELGROUP) {
	pair<int, int> center = {width / 2 + texrecx, height / 2 + texrecy};
	/*
	int centerx = width / 2 + texrecx;
	int centery = height / 2 + texrecy;
	*/
	for (int r = rstart; r < rend; r += PIXELGROUP) {
		int xSquared = r * r;
		int makeCloser = (r - 1) * (r - 1);
		int change = 2 * r - 1;
		int x = r;
		int y = 0;
		vector<pair<int, int>> degree45;
		while (y <= x) {
			degree45.push_back({x, y});
			xSquared -= 2 * y + 1;
			if (xSquared <= makeCloser) {
				change -= 2;
				makeCloser -= change;
				x--;
				degree45.push_back({x, y});
			}
			y++;
		}
		int movement = 0.001 * r * transitionFrames * degree45.size();
		for (int z = 0; z < 8 * degree45.size(); z++) {
			for (int a = 0; a < PIXELGROUP; a++) {
				pair<int, int> start = flippedIndex(z, degree45, a) + center;
				pair<int, int> finish = flippedIndex(z + movement, degree45, a) + center;

				/*
				if (r == 4) {
					cout << flippedIndex(z, degree45).first << ", " << flippedIndex(z, degree45).second << endl;
				}
				*/

				if (inRange(start.first, texrecx, width) && inRange(start.second, texrecy, height) && inRange(finish.first, texrecx, width) && inRange(finish.second, texrecy, height)) {
					pixels[start.first + start.second * width] = newPixels[finish.first + finish.second * width];
				}
				/*
				for (int x1 = 0; x1 < PIXELGROUP; x1++) {
					for (int y1 = 0; y1 < PIXELGROUP; y1++) {
						if (inRange(start.first + x1, texrecx, width) && inRange(start.second + y1, texrecy, height) && inRange(finish.first + x1, texrecx, width) && inRange(finish.second + y1, texrecy, height)) {
							pixels[(start.first + x1) + (start.second + y1) * width] = newPixels[(finish.first + x1) + (finish.second + y1) * width];
						}
						else {
							break;
						}
					}
				}
				*/
			}
		}
	}
	// cout << rstart << endl;
}

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

template <typename T>
void sortComb(vector<T*>& vec, int (*foo)(T*)) {
	for (int x = 0; x < vec.size() - 1; x++) {
		if (foo(vec.at(x)) > foo(vec.at(x + 1))) {
			// cout << "SWAP!\n";
			iter_swap(vec.begin() + x, vec.begin() + x + 1);
		}
	}
}

int getValue(Fightable* f) {
	return f->battleY + f->show_height * f->sizeIncrease;
}

int getValue(Enemy* f) {
	return getValue((Fightable*) f);
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
		{"Scratch", new Move("Scratch", 10, 0, true, true, 1, {SLASHING}, 
			{
				KeyFrame(45, "overworld", 1, -100, 0, INFRONTENEMY, LINEAR, false), 
				KeyFrame(10, "overworld", 1, 0, 0, INFRONTENEMY, LOGARITHMIC, false), 
				KeyFrame(15, "swords", 0, 0, 0, INFRONTENEMY, LINEAR, true), 
				KeyFrame(35, "overworld", 3, 0, 0, STARTINGCOORDS, LINEAR, false)
			}
		)}, 
		{"Ram", new Move("Ram", 30, 0, true, false, 2, {BLUDGEONING, FORWARD}, 
			{

			}
		)}, 
		{"16th Notes", new Move("16th Notes", 10, 25, false, false, 2, {FORCE, FORWARD}, 
			{

			}
		, true, 4)}, 
		{"Vibrato", new Move("Vibrato", 20, 10, false, true, 1, {VIBRATING}, 
			{

			}
		)}
	};

	for (auto it = moves.begin(); it != moves.end(); ++it) {
		it->second->animation.insert(it->second->animation.begin(), KeyFrame(20, "battleidle", 0, 0, 0, STARTINGCOORDS, LINEAR, false));
	}

	// /*
	map<string, EnemyType*> enemyTypes = { // UNUSED WASTE OF TIME FIX THIS SHIT
		{"Tuba Snail", new EnemyType(
			"Tuba Snail", 
			Stats(1, 2, 2, 1, 2, 2), 
			{moves.find("Ram")->second, moves.find("Vibrato")->second}, 
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
	int transitionFrames = 0;
	SDL_Texture* window_texture = nullptr;
	SDL_Surface* window_surface = nullptr;
	Uint32* newPixels = nullptr;
	const int THREADS = 16;
	int PIXELGROUP = 1;

	double delay = 0;
	double normalDelay = 0;

	while (gameRunning) {
		auto start = chrono::steady_clock().now();

		for (int framesDone = 0; framesDone < fastForward; framesDone++) {
			// cout << "frame\n";
			if (window.gamestate == BATTLETRANSITION) {
				int width = (int) (window.WIDTH * window.scaleMultiplier);
				int height = (int) (window.HEIGHT * window.scaleMultiplier);
				SDL_Rect texture_rect = {0, 0, width, height};
				Uint32* pixels;
				int pitch;

				if (window_texture == nullptr) {
					window_surface = SDL_GetWindowSurface(window.window);
					window_texture = SDL_CreateTextureFromSurface(window.renderer, window_surface);
					texture_rect = {window.xOrigin, window.yOrigin, width, height};
				}
				SDL_Texture* trueDiagonalTexture = SDL_CreateTexture(window.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);
				SDL_LockTexture(trueDiagonalTexture, NULL, reinterpret_cast<void**>(&pixels), &pitch);

				if (newPixels == nullptr) { // DOES NOT WORK WITH WINDOW RESIZE
					SDL_SetRenderTarget(window.renderer, window_texture);
					SDL_RenderReadPixels(window.renderer, &texture_rect, SDL_PIXELFORMAT_RGBA8888, pixels, pitch);
					SDL_SetRenderTarget(window.renderer, NULL);
					newPixels = new Uint32[width * height];
					for (int x = 0; x < width * height; x++) {
						newPixels[x] = pixels[x];
					}
				}
				// /*
				auto start1 = chrono::steady_clock().now();

				thread threads[THREADS];
				int rstart = 1;
				int maxRadius = distanceFrom(width / 2, height / 2);
				double mod = (maxRadius * (transitionFrames > 30 ? (60.0 - transitionFrames) / 30.0 : 1) + 1) / sqrt(THREADS);
				for (int x = 0; x < THREADS; x++) {
					int rend = PIXELGROUP * ceil(mod * sqrt(x + 1) / PIXELGROUP) + 1;
					threads[x] = thread(spiral, rstart, rend, texture_rect.x, texture_rect.y, width, height, transitionFrames, pixels, newPixels, maxRadius, PIXELGROUP);
					// cout << "xstart: " << xstart << " xend: " << xend << endl;
					rstart = rend;
				}

				auto end1 = chrono::steady_clock().now();
				chrono::duration<double> frameDone = end1 - start1;
				// cout << "step1: " << 1000 * frameDone.count() << endl;

				for (int x = 0; x < THREADS; x++) {
					threads[x].join();
				}

				end1 = chrono::steady_clock().now();
				frameDone = end1 - start1;
				double millis = 1000 * frameDone.count();
				cout << "threads: " << millis << endl;
				/*
				PIXELGROUP = int(ceil(PIXELGROUP * millis / (1000.0 / FPS - normalDelay)));
				if (PIXELGROUP > 100) {
					PIXELGROUP = 100;
				}
				cout << "PIXELGROUP: " << PIXELGROUP << endl; 
				// */
				/*
				start1 = chrono::steady_clock().now();

				for (int x = 0; x < THREADS; x++) {
					for (int y = 0; y < allSwaps[x]->size(); y++) {
						pixels[allSwaps[x]->at(y).first] = newPixels[allSwaps[x]->at(y).second];
					}
					delete allSwaps[x];
				}


				end1 = chrono::steady_clock().now();
				frameDone = end1 - start1;
				cout << "swaps: " << 1000 * frameDone.count() << endl;
				*/

				// */
				SDL_UnlockTexture(trueDiagonalTexture);

				window.clear();
				SDL_RenderCopy(window.renderer, trueDiagonalTexture, NULL, &texture_rect);

				SDL_DestroyTexture(window_texture);
				window_texture = trueDiagonalTexture;

				transitionFrames += max(int(frameDone.count() * FPS), 1);
				// transitionFrames += 1;
				if (transitionFrames >= 60) {
					SDL_DestroyTexture(window_texture);
					window_texture = nullptr;
					SDL_FreeSurface(window_surface);
					window_surface = nullptr;
					delete newPixels;
					newPixels = nullptr;
					window.gamestate = BATTLE;
					transitionFrames = 0;
				}
				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT) {
						gameRunning = false;
					}
				}

				continue; // MIGHT HELLA CAUSE ISSUES
			}
			else {
				window.clear();
				normalDelay = (normalDelay + delay) / 2;
			}

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
					if (kc == SDLK_RALT) {
						auto flag = SDL_GetWindowFlags(window.window);
						auto is_fullscreen  = flag&SDL_WINDOW_FULLSCREEN;
						SDL_SetWindowFullscreen(window.window, is_fullscreen != SDL_WINDOW_FULLSCREEN);
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

				if (window.gamestate == BATTLETRANSITION) {
					while (!battleEntities.empty()) {
						delete battleEntities.at(0);
					}
				}
			}
			else if (window.gamestate == BATTLE) {
				window.render(world->current->battleBackground);
				Fightable* myTurn = window.turnOrder.front();

				bool playerTurn = false;
				// cout << "a\n";

				sortComb(window.enemyTeam, getValue);
				sortComb(window.playerTeam, getValue);

				for (Enemy* go : window.enemyTeam) {
					go->battle(&window, myTurn, battleEntities);
					// cout << "b\n";
				}
				// cout << "c\n";
				for (Fightable* go : window.playerTeam) {
					go->battle(&window, myTurn, battleEntities);
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
						selector->render(&window, battleEntities);
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
						selector->render(&window, battleEntities);
					}
				}

				for (int x = 0; x < battleEntities.size(); x++) {
					// cout << "battleEntities\n";
					if (battleEntities.at(x)->draw(&window, world, battleEntities)) {
						delete battleEntities.at(x);
						battleEntities.erase(battleEntities.begin() + x);
						x--;
					}
				}
				// cout << "out of loop\n";

				if (window.turnstate == ENDTURN) {
					cout << "g\n";
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
							// cout << "post delete call\n";
							window.enemyTeam.erase(window.enemyTeam.begin());
							delete e;
							// cout << "erase enemies\n";
						}
						// window.enemyTeam.clear();
						// cout << "gone" << endl;

						while (!battleEntities.empty()) {
							GameObject* go = battleEntities.at(0);
							delete go;
							battleEntities.erase(battleEntities.begin());
						}
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

						// /*
						for (int x = 0; x < window.enemyTeam.size(); x++) {
							/*
							cout << "x: " << x << endl;
							for (Enemy* e : window.enemyTeam) {
								cout << e << endl;
							}
							*/
							// cout << "window.enemyTeam.size(): " << window.enemyTeam.size() << endl;
							Enemy* e = window.enemyTeam.at(x);
							if (e->stats.hp <= 0) {
								// cout << "deleted " << e << endl;
								overworldEntities.erase(remove(overworldEntities.begin(), overworldEntities.end(), e));
								// cout << "a\n";
								e->zone->dudes.erase(remove(e->zone->dudes.begin(), e->zone->dudes.end(), e));
								// cout << "b\n";
								e->zone->spawned--;
								// cout << "c\n";
								window.enemyTeam.erase(remove(window.enemyTeam.begin(), window.enemyTeam.end(), e));
								// cout << "d\n";
								delete e;
								// cout << "e\n";
								x--;
								// cout << "window.enemyTeam.size(): " << window.enemyTeam.size() << endl;
							}
						}
						// */
					}
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

		// cout << 1000 * frameDone.count() << endl;
		delay = 1000 * ((1.0 / FPS) - frameDone.count());
		if (delay > 0) {
			SDL_Delay(delay);
			delay = 0;
		}
		// cout << "delay: " << delay << endl;
		// */
	}

	return 0;
}