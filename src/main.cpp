#include "World.hpp"
#include "TextSequence.hpp"
#include "Enemy.hpp"

#include <chrono>

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

int main(int argc, char *argv[]) {
	const int FPS = 60;
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

	Player* player = new Player(&window);
	vector<GameObject*> overworldEntities;
	vector<GameObject*> battleEntities;

	vector<Fightable*> playerTeam;
	vector<Fightable*> enemyTeam;
	// overworldEntities.push_back(player); // PLAYER IS DRAWN IN AREA RENDER

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

	/*
	map<string, EnemyType*> enemyTypes = {
		{"Tuba Snail", new EnemyType("Tuba Snail", Stats(2, 3, 2, 1, 1), {moves.find("Legato")})}
	};
	// */


	World* world = new World(window, player);
	TextSequence* ts = nullptr;
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

	while (gameRunning) {
		auto start = chrono::steady_clock().now();

		// cout << "frame\n";
		window.clear();

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				gameRunning = false;
			}
			SDL_Keycode kc = event.key.keysym.sym;
			if (event.type == SDL_KEYDOWN) {
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
			}
		}

		if (window.gamestate == OVERWORLD) {
			world->current->render(window, player, world, overworldEntities);
			for (GameObject* go : overworldEntities) {
				go->draw(&window, world, overworldEntities);
			}

			// CAMERA
			window.x = (window.x + player->x - RenderWindow::WIDTH / 2) / 2;
			window.y = (window.y + player->y - RenderWindow::HEIGHT / 2) / 2;
		}
		else if (window.gamestate == CUTSCENE) {
			for (GameObject* go : battleEntities) {
				go->draw(&window, world, battleEntities);
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

		window.display();

		auto end = chrono::steady_clock().now();
		chrono::duration<double> frameDone = end - start;

		double delay = 1000 * ((1.0 / FPS) - frameDone.count());
		// cout << "delay: " << delay << endl;
		if (delay > 0) {
			SDL_Delay(delay);
		}
	}

	return 0;
}