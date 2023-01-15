#include "Area.hpp"

#include <chrono>

using namespace std;

int main(int argc, char *argv[]) {
	const int FPS = 60;
	SDL_Event event;
	bool gameRunning = true;

	if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0) {
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
	}
	if (!IMG_Init(IMG_INIT_PNG)) {
		cout << "IMG PNG Failure: " << SDL_GetError() << "\n";
	}
	if(TTF_Init() == -1) {
	    cout << "TTF_Init: " << TTF_GetError() << endl;
	}

	RenderWindow window("Phantom Keys");

	Player* player = new Player(&window);
	vector<GameObject*> entities;
	entities.push_back(player);

	Area* ruins = new Area(window, "./res/Ruins/Ruins.tmx");

	ruins->placePlayer(player);

	while (gameRunning) {
		auto start = chrono::steady_clock().now();

		// cout << "frame\n";
		window.clear();
		ruins->render(window);

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
				if (kc == SDLK_w) {
					cout << "up\n";
					window.y -= 100;
				}
				if (kc == SDLK_s) {
					cout << "down\n";
					window.y += 100;
				}
				if (kc == SDLK_a) {
					cout << "left\n";
					window.x -= 100;
				}
				if (kc == SDLK_d) {
					cout << "right\n";
					window.x += 100;
				}
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

		for (GameObject* go : entities) {
			go->draw(&window, entities);
		}

		// cout << "player->x: " << player->x << " player->y: " << player->y << endl; 

		// CAMERA
		window.x = (window.x + player->x - RenderWindow::WIDTH / 2) / 2;
		window.y = (window.y + player->y - RenderWindow::HEIGHT / 2) / 2;

		window.display();

		auto end = chrono::steady_clock().now();
		chrono::duration<double> frameDone = end - start;

		double delay = 1000 * ((1.0 / FPS) - frameDone.count());
		if (delay > 0) {
			SDL_Delay(delay);
		}
	}

	return 0;
}