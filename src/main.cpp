#include "World.hpp"
#include "TextSequence.hpp"
#include "Enemy.hpp"
#include "BattleOptions.hpp"
#include "Selector.hpp"
#include "HealthBar.hpp"
#include "RhythmNote.hpp"
#include "mingw.thread.h"

#include <queue>

using namespace std;

// Unused constant used for darkening the screen
const double DARKEDGE = 0.5;

/**
 * Unused function that executes an Inverse Tangent via table lookup using binary search. The table used to be stored in RenderWindow
 * @param {vv} Vector of RenderWindow in index 0 and float that you are looking for in index 1
 * @returns atan of vv[1]
 */
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

/**
 * I dont remember what this does, its something for spiral / darkness though
 */
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

ostream& operator<<(ostream& os, const KeyFrame& obj)
{
	os << "x: " << obj.x << ", y: " << obj.y << ", rf: " << obj.rf << ", frame: " << obj.frame;
    // write obj to stream
    return os;
}

void spiralPerPixel(Uint32* pixels, Uint32* newPixels, vector<pair<int, int>>& degree45, pair<int, int>& center, SDL_Rect& texture_rect, int z, int r, SDL_PixelFormat* format, int transitionFrames, double val) {
	pair<int, int> start = flippedIndex(z, degree45) + center;
	pair<int, int> finish = flippedIndex(z + val, degree45) + center;

	/*
	if (r == 4) {
		cout << flippedIndex(z, degree45).first << ", " << flippedIndex(z, degree45).second << endl;
	}
	*/

	// cout << "d <<<<<<< width: " << texture_rect.w << endl; 
	if (inRange(start.first, texture_rect.x, texture_rect.w) && inRange(start.second, texture_rect.y, texture_rect.h) && inRange(finish.first, texture_rect.x, texture_rect.w) && inRange(finish.second, texture_rect.y, texture_rect.h)) {
		pixels[start.first + start.second * texture_rect.w] = newPixels[finish.first + finish.second * texture_rect.w];
	}
	/*
	for (int x1 = 0; x1 < PIXELGROUP; x1++) {
		for (int y1 = 0; y1 < PIXELGROUP; y1++) {
			if (inRange(start.first + x1, texture_rect.x, texture_rect.w) && inRange(start.second + y1, texture_rect.y, texture_rect.h) && inRange(finish.first + x1, texture_rect.x, texture_rect.w) && inRange(finish.second + y1, texture_rect.y, texture_rect.h)) {
				pixels[(start.first + x1) + (start.second + y1) * texture_rect.w] = newPixels[(finish.first + x1) + (finish.second + y1) * texture_rect.w];
			}
			else {
				break;
			}
		}
	}
	*/
}

double movementCompute(int transitionFrames, vector<pair<int, int>>& degree45, int r, SDL_Rect& texture_rect) {
	return 0.001 * r * transitionFrames * degree45.size();
}

double blackCompute(int transitionFrames, vector<pair<int, int>>& degree45, int r, SDL_Rect& texture_rect) {
	return transitionFrames * r / (texture_rect.w + texture_rect.h);
}

void blackPerPixel(Uint32* pixels, Uint32* newPixels, vector<pair<int, int>>& degree45, pair<int, int>& center, SDL_Rect& texture_rect, int z, int r, SDL_PixelFormat* format, int transitionFrames, double mult) {
	int shift = (int) mult;

	pair<int, int> start = flippedIndex(z, degree45) + center;

	if (inRange(start.first, texture_rect.x, texture_rect.w) && inRange(start.second, texture_rect.y, texture_rect.h)) {
		// /*
		Uint8 red;
		Uint8 green;
		Uint8 blue;
		Uint8 alpha;

		// SDL_GetRGBA(newPixels[start.first + start.second * texture_rect.w], format, &red, &green, &blue, &alpha);
		
		/*
		if (z == 10 && r == 100) {
			// /*

			cout << "z: " << z << " r: " << r << " red: " << (int) red << " green: " << (int) green << " blue: " << (int) blue << " alpha: " << (int) alpha << endl;

			Uint32 pixel = newPixels[start.first + start.second * texture_rect.w];

			cout << "pixel: " << (int) pixel << endl;
			cout << "z: " << z << " r: " << r << " red: " << (int) red << " green: " << (int) green << " blue: " << (int) blue << " alpha: " << (int) alpha << endl;
		}

		// */

		Uint32 pixel = newPixels[start.first + start.second * texture_rect.w];

		red = (pixel >> 24) & 0xFF;
		green = (pixel >> 16) & 0xFF;
		blue = (pixel >> 8) & 0xFF;
		alpha = pixel & 0xFF;

		/*
		if (z == 10 && r == 100) {
			// cout << "pixel: " << (int) pixel << endl;
		}
		*/
		
		red >>= shift;
		green >>= shift;
		blue >>= shift;
		// */
		pixel = (((((red << 8) + green) << 8) + blue) << 8) + alpha;
		// cout << "pixel: " << (int) pixel << endl;

		pixels[start.first + start.second * texture_rect.w] = pixel;

		// pixels[start.first + start.second * texture_rect.w] = SDL_MapRGBA(format, red, green, blue, alpha);
		// */
		// pixels[start.first + start.second * texture_rect.w] = newPixels[start.first + start.second * texture_rect.w];
	}
}

void circularScreenEdit(int rstart, int rend, SDL_Rect texture_rect, int transitionFrames, Uint32* pixels, Uint32* newPixels, int maxRadius, SDL_PixelFormat* format, void (*perPixel)(Uint32*,Uint32*,vector<pair<int, int>>&,pair<int, int>&,SDL_Rect&,int,int,SDL_PixelFormat*,int,double), double (*compute)(int, vector<pair<int, int>>&, int r, SDL_Rect&)) {
	pair<int, int> center = {texture_rect.w / 2 + texture_rect.x, texture_rect.h / 2 + texture_rect.y};
	/*
	int centerx = texture_rect.w / 2 + texture_rect.x;
	int centery = texture_rect.h / 2 + texture_rect.y;
	*/
	for (int r = rstart; r < rend; r += 1) {
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
		double computedValue = compute(transitionFrames, degree45, r, texture_rect);
		// cout << "c <<<<<<< width: " << texture_rect.w << endl; 
		for (int z = 0; z < 8 * degree45.size(); z++) {
			perPixel(pixels, newPixels, degree45, center, texture_rect, z, r, format, transitionFrames, computedValue);
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

// /*
void rhythmPress(vector<RhythmNote*>* notes, float* howGoodYouDoIt, float maxGoodness, NoteType nt) {
	// lol check if correct button pressed
	// cout << "maxGoodness: " << maxGoodness << endl;
	// cout << "howGoodYouDoIt: " << *howGoodYouDoIt << endl;

	for (int x = 0; x < notes->size(); x++) {
		RhythmNote* rn = notes->at(x);
		if (rn->nt == nt) {
			float ratio = 1 - (1.0 * abs(rn->x - RhythmNote::NOTEX) / RhythmNote::KEYSIZE);
			cout << ratio << endl;
			// if (abs(notes->at(x)->x - RhythmNote::NOTEX) < RhythmNote::KEYSIZE) {
			if (ratio > 0) {
				*howGoodYouDoIt += sqrt(ratio) * maxGoodness;
				delete notes->at(x);
				notes->erase(notes->begin() + x);
				return;
			}
		}
	}
	*howGoodYouDoIt -= maxGoodness / 3;
}

void rhythmPressUp(vector<void*> passingArgument) {
	rhythmPress((vector<RhythmNote*>*) passingArgument[0], (float*) passingArgument[1], *((float*) passingArgument[2]), UP);
}
void rhythmPressLeft(vector<void*> passingArgument) {
	rhythmPress((vector<RhythmNote*>*) passingArgument[0], (float*) passingArgument[1], *((float*) passingArgument[2]), LEFT);
}
void rhythmPressRight(vector<void*> passingArgument) {
	rhythmPress((vector<RhythmNote*>*) passingArgument[0], (float*) passingArgument[1], *((float*) passingArgument[2]), RIGHT);
}
void rhythmPressDown(vector<void*> passingArgument) {
	rhythmPress((vector<RhythmNote*>*) passingArgument[0], (float*) passingArgument[1], *((float*) passingArgument[2]), DOWN);
}
// */

inline SDL_Texture* threadCircularApplication(RenderWindow& window, Uint32*& newPixels, SDL_Texture*& window_texture, SDL_Surface*& window_surface, int& transitionFrames, SDL_Rect& texture_rect, const int& THREADS, int start, double mod, void (*perPixel)(Uint32*,Uint32*,vector<pair<int, int>>&,pair<int, int>&,SDL_Rect&,int,int,SDL_PixelFormat*,int,double), double (*compute)(int, vector<pair<int, int>>&, int r, SDL_Rect&)) {
	Uint32* pixels;
	int pitch;

	if (window_texture == nullptr) {
		SDL_Surface* temp_window_surface = SDL_GetWindowSurface(window.window);
		window_surface = SDL_ConvertSurfaceFormat(temp_window_surface, SDL_PIXELFORMAT_RGBA8888, 0);
		SDL_FreeSurface(temp_window_surface);

		window_texture = SDL_CreateTextureFromSurface(window.renderer, window_surface);
		texture_rect = {window.xOrigin, window.yOrigin, texture_rect.w, texture_rect.h};
	}
	SDL_Texture* trueDiagonalTexture = SDL_CreateTexture(window.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, texture_rect.w, texture_rect.h);
	SDL_LockTexture(trueDiagonalTexture, NULL, reinterpret_cast<void**>(&pixels), &pitch);

	if (newPixels == nullptr) { // DOES NOT WORK WITH WINDOW RESIZE
		SDL_SetRenderTarget(window.renderer, window_texture);
		SDL_RenderReadPixels(window.renderer, &texture_rect, SDL_PIXELFORMAT_RGBA8888, pixels, pitch);
		SDL_SetRenderTarget(window.renderer, NULL);
		newPixels = new Uint32[texture_rect.w * texture_rect.h];
		for (int x = 0; x < texture_rect.w * texture_rect.h; x++) {
			newPixels[x] = pixels[x];
		}
	}
	// /*

	thread threads[THREADS];
	int maxRadius = distanceFrom(texture_rect.w / 2, texture_rect.h / 2);
	mod = (maxRadius * mod + 1) / sqrt(THREADS);
	int rstart = start;
	for (int x = 0; x < THREADS; x++) {
		// cout << "b <<<<<<< width: " << texture_rect.w << endl; 
		int rend = ceil(mod * sqrt(x + 1)) + start;
		// circularScreenEdit(rstart, rend, texture_rect, transitionFrames, pixels, newPixels, maxRadius, window_surface->format, perPixel);
		threads[x] = thread(circularScreenEdit, rstart, rend, texture_rect, transitionFrames, pixels, newPixels, maxRadius, window_surface->format, perPixel, compute);
		// threads[x] = thread(test, rstart, rend, texture_rect);
		// cout << "xstart: " << xstart << " xend: " << xend << endl;
		rstart = rend;
	}

	// /*
	for (int x = 0; x < THREADS; x++) {
		threads[x].join();
	}
	// */

	SDL_UnlockTexture(trueDiagonalTexture);
	return trueDiagonalTexture;
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

	map<string, Mix_Chunk*> stingers = {
		{"16th Notes", Mix_LoadWAV("res/Sounds/SFX/STINGERS/LuckCrescendo.wav")}, 
		{"Vibrato", Mix_LoadWAV("res/Sounds/SFX/STINGERS/JazzLick.wav")}, 
	};


	map<string, Move*> moves = {
		{"Scratch", new Move("Scratch", 10, 0, true, true, 1, {SLASHING}, 
			{
				KeyFrame(45, "overworld", 1, -200, 0, INFRONTENEMY, LINEAR), 
				KeyFrame(20, "battleidle", 0, -200, 0, INFRONTENEMY, LINEAR), 
				KeyFrame(10, "overworld", 1, -100, 0, INFRONTENEMY, LOGARITHMIC), 
				KeyFrame(12, "swords", 0, -100, 0, INFRONTENEMY, LINEAR, true, 9), 
				KeyFrame(20, "battleidle", 0, -100, 0, INFRONTENEMY, LINEAR), 
				KeyFrame(35, "overworld", 3, 0, 0, STARTINGCOORDS, LINEAR)
			}, 
			{}
		)}, 
		{"Ram", new Move("Ram", 30, 0, true, false, 2, {BLUDGEONING, FORWARD}, 
			{
				KeyFrame(45, "overworld", 1, -200, 0, INFRONTENEMY, LINEAR), 
				KeyFrame(20, "battleidle", 0, -200, 0, INFRONTENEMY, LINEAR), 
				KeyFrame(10, "overworld", 1, -100, 0, INFRONTENEMY, LOGARITHMIC), 
				KeyFrame(12, "swords", 0, -100, 0, INFRONTENEMY, LINEAR, true, 9), 
				KeyFrame(20, "battleidle", 0, -100, 0, INFRONTENEMY, LINEAR), 
				KeyFrame(35, "overworld", 3, 0, 0, STARTINGCOORDS, LINEAR)
			}, 
			{}
		)}, 
		{"16th Notes", new Move("16th Notes", 10, 25, false, false, 2, {FORCE, FORWARD}, 
			{
				KeyFrame(45, "overworld", 1, -200, 0, INFRONTENEMY, LINEAR), 
				KeyFrame(20, "battleidle", 0, -200, 0, INFRONTENEMY, LINEAR), 
				KeyFrame(10, "overworld", 1, -100, 0, INFRONTENEMY, LOGARITHMIC), 
				KeyFrame(12, "swords", 0, -100, 0, INFRONTENEMY, LINEAR, true, 9), 
				KeyFrame(20, "battleidle", 0, -100, 0, INFRONTENEMY, LINEAR), 
				KeyFrame(35, "overworld", 3, 0, 0, STARTINGCOORDS, LINEAR)
			}, 
			{
				{0, LEFT}, 
				{22, LEFT}, 
				{42, DOWN}, 
				{62, DOWN}, 
				{84, UP}, 
				{98, RIGHT}, 
				{112, DOWN}, 
			}
		, true, 4)}, 
		{"Vibrato", new Move("Vibrato", 20, 10, false, true, 1, {VIBRATING}, 
			{
				KeyFrame(45, "overworld", 1, -200, 0, INFRONTENEMY, LINEAR), 
				KeyFrame(20, "battleidle", 0, -200, 0, INFRONTENEMY, LINEAR), 
				KeyFrame(10, "overworld", 1, -100, 0, INFRONTENEMY, LOGARITHMIC), 
				KeyFrame(12, "swords", 0, -100, 0, INFRONTENEMY, LINEAR, true, 9), 
				KeyFrame(20, "battleidle", 0, -100, 0, INFRONTENEMY, LINEAR), 
				KeyFrame(35, "overworld", 3, 0, 0, STARTINGCOORDS, LINEAR)
			}, 
			{
				{0, UP}, 
				{10, LEFT}, 
				{20, DOWN}, 
				{30, RIGHT}, 
				{60, RIGHT}, 
				{70, DOWN}, 
				{80, LEFT}, 
				{90, UP}, 
			}
		)}
	};

	/*
		{0, UP}, 
		{5, UP}, 
		{10, UP}, 
		{15, UP}, 
		{20, DOWN}, 
		{25, DOWN}, 
		{30, DOWN}, 
		{35, DOWN}, 
		{40, LEFT}, 
		{45, RIGHT}, 
		{50, LEFT}, 
		{55, RIGHT}, 
		{60, UP}, 
		{65, LEFT}, 
		{70, DOWN}, 
		{75, RIGHT}, 
	*/

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
	vector<Entity*> emptyKeys;
	vector<RhythmNote*> notes;

	emptyKeys.push_back(new Entity(RhythmNote::NOTEX, RenderWindow::HEIGHT - RhythmNote::KEYSIZE - RhythmNote::NOTEY, window.loadTexture("res/gfx/Battle/RhythmUI/downhole.png"), RhythmNote::KEYSIZE, RhythmNote::KEYSIZE));
	emptyKeys.push_back(new Entity(RhythmNote::NOTEX, RenderWindow::HEIGHT - 2 * RhythmNote::KEYSIZE - RhythmNote::NOTEY, window.loadTexture("res/gfx/Battle/RhythmUI/lefthole.png"), RhythmNote::KEYSIZE, RhythmNote::KEYSIZE));
	emptyKeys.push_back(new Entity(RhythmNote::NOTEX, RenderWindow::HEIGHT - 3 * RhythmNote::KEYSIZE - RhythmNote::NOTEY, window.loadTexture("res/gfx/Battle/RhythmUI/righthole.png"), RhythmNote::KEYSIZE, RhythmNote::KEYSIZE));
	emptyKeys.push_back(new Entity(RhythmNote::NOTEX, RenderWindow::HEIGHT - 4 * RhythmNote::KEYSIZE - RhythmNote::NOTEY, window.loadTexture("res/gfx/Battle/RhythmUI/uphole.png"), RhythmNote::KEYSIZE, RhythmNote::KEYSIZE));

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
			TextSlice(window, "That game can suck my nuts. ", {255, 0, 255, 255}, {DIAGONAL_RAINBOW, WAVEY}), 
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
	int transitionFrames = 0; // USED FOR BOTH BATTLE TRANSITION AND ATTACK ANIMATION 
	SDL_Texture* window_texture = nullptr;
	SDL_Surface* window_surface = nullptr;
	Uint32* newPixels = nullptr;
	const int THREADS = 50;

	double delay = 0;
	double normalDelay = 0;

	bool hitting = false;
	bool crit = true;

	int sideScreenDarken = 0;

	float howGoodYouDoIt = 0;
	float maxGoodness = 0;
	bool stingerStart = false;

	chrono::steady_clock::time_point rhythmStart;

	while (gameRunning) {
		auto start = chrono::steady_clock().now();

		for (int framesDone = 0; framesDone < fastForward; framesDone++) {
			// cout << "frame\n";
			if (window.gamestate == BATTLETRANSITION) {
				int width = (int) (window.WIDTH * window.scaleMultiplier);
				int height = (int) (window.HEIGHT * window.scaleMultiplier);
				SDL_Rect texture_rect = {0, 0, width, height};

				auto start1 = chrono::steady_clock().now();

				// cout << "a <<<<<<< width: " << width << endl; 

				SDL_Texture* trueDiagonalTexture = threadCircularApplication(window, newPixels, window_texture, window_surface, transitionFrames, texture_rect, THREADS, 1, (transitionFrames > 30 ? (60.0 - transitionFrames) / 30.0 : 1), spiralPerPixel, movementCompute);
				// SDL_Texture* trueDiagonalTexture = threadCircularApplication(window, newPixels, window_texture, window_surface, transitionFrames, texture_rect, THREADS);

				auto end1 = chrono::steady_clock().now();
				chrono::duration<double> frameDone = end1 - start1;
				// cout << "step1: " << 1000 * frameDone.count() << endl;
				double millis = 1000 * frameDone.count();
				// cout << "threads: " << millis << endl;


				// cout << "prerender\n";
				window.clear();
				SDL_RenderCopy(window.renderer, trueDiagonalTexture, NULL, &texture_rect);
				// cout << "postrender\n";

				SDL_DestroyTexture(window_texture);
				window_texture = trueDiagonalTexture;
				// cout << "postdestroy\n";

				transitionFrames += max(int(frameDone.count() * FPS), 1);
				// transitionFrames += 1;
				// cout << "posttransframes\n";
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
					// cout << "f" << window.turnstate << "\n";
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

				if (window.turnstate == ANIMATION) {
					if (!playerTurn) {
						howGoodYouDoIt = 0.8;
					}
					if (transitionFrames == 0) {
						hitting = myTurn->moveEntered->getHitting(myTurn, myTurn->target);
						crit = myTurn->moveEntered->getCrit(myTurn);
					}
					transitionFrames++;
					int curFrames = transitionFrames;
					// cout << myTurn << endl;
					// cout << myTurn->moveEntered << endl;
					for (int x = 1; x < myTurn->moveEntered->animation.size(); x++) {
						// cout << "a\n";
						KeyFrame& kf = myTurn->moveEntered->animation.at(x);
						curFrames -= kf.frame;
						if (curFrames <= 0) {
							KeyFrame& prev = myTurn->moveEntered->animation.at(x - 1);
							// cout << "b\n";
							curFrames += kf.frame;
							kf.applyKeyframe(myTurn, prev, curFrames, myTurn->target, !playerTurn);

							// cout << "curKey: " << kf << endl;
							// cout << "prevKey: " << myTurn->moveEntered->animation.at(x - 1) << endl;
							// cout << "curFrames: " << curFrames << endl;

							if (kf.damage) {
								// cout << "NOW crit: " << crit << endl;
								if (curFrames == kf.framedelay) {
									// cout << "DAMAGE\n";
									myTurn->moveEntered->dealDamage(&window, myTurn, myTurn->target, battleEntities, hitting, crit, howGoodYouDoIt);
								}
								if (crit) {
									// cout << "CRIT kf.framedelay: " << kf.framedelay << endl;
									if (curFrames < kf.framedelay) {
										// cout << "CRITHIT\n";
										/*
										window.x -= (myTurn->battleX - (RenderWindow::WIDTH - myTurn->show_width * myTurn->sizeIncrease) / 2 - window.x) / 2.0;
										window.y -= (myTurn->battleY - (RenderWindow::HEIGHT - myTurn->show_height * myTurn->sizeIncrease) / 2 - window.y) / 2.0;
										window.zoom += (2.0 - window.zoom) / 2.0;
										// */
										// /*
										window.x = myTurn->battleX - (RenderWindow::WIDTH - myTurn->show_width * myTurn->sizeIncrease) / 2;
										window.y = myTurn->battleY - (RenderWindow::HEIGHT - myTurn->show_height * myTurn->sizeIncrease) / 2;
										window.zoom = 1.5;
										sideScreenDarken++;
										// */
									}
									else {
										// /*
										window.x = window.x / 2.0;
										window.y = window.y / 2.0;
										window.zoom += (1.0 - window.zoom) / 2.0;
										sideScreenDarken = sideScreenDarken / 2;
										// */
									}
								}
							}
							if (prev.damage && crit) {
								// /*
								window.x -= window.x / (kf.frame - curFrames + 1);
								window.y -= window.y / (kf.frame - curFrames + 1);
								window.zoom += (1.0 - window.zoom) / (kf.frame - curFrames + 1);
								sideScreenDarken = 0;
								// */
							}
							curFrames -= kf.frame;
							break;
						}
					}
					// cout << "myTurn->column: " << myTurn->column << endl;
					// cout << "d\n";
					if (curFrames > 0) {
						cout << "joever\n";
						window.turnstate = ENDTURN;
						myTurn->moveEntered = nullptr;
						myTurn->target = nullptr;
						myTurn->changeSpriteSheet("battleidle");
						myTurn->row = 0;
						transitionFrames = 0;
					}
				}

				// TODO: Maybe poll for keys in seperate thread for higher responsiveness in laggy environments?
				// TODO: Rhythm Game Text (miss, hit, etc.)
				if (window.turnstate == RHYTHM) {
					for (Entity* e : emptyKeys) {
						window.render(e);
					}

					if (notes.empty()) {
						if (maxGoodness == 0) {
							rhythmStart = chrono::steady_clock().now();
							for (pair<int, NoteType> pint : myTurn->moveEntered->stingerNotes) {
								// cout << "NOTE MADE\n";
								notes.push_back(new RhythmNote(&window, pint, &rhythmStart));
							}
							maxGoodness = 1.0 / notes.size();
						}
						else {
							cout << "SCORE: " << howGoodYouDoIt << endl;
							window.turnstate = ANIMATION;
							maxGoodness = 0;
							stingerStart = false;
						}
					}
					else if (!stingerStart && round(((chrono::duration<double>) (chrono::steady_clock().now() - rhythmStart)).count() * FPS) > RhythmNote::FRAMESADVANCE) {
						cout << "started\n";
						stingerStart = true;
						Mix_PlayChannel(-1, stingers[myTurn->moveEntered->name], 0);
					}

					// cout << "FRAMES ESSTITMESR: " << round(((chrono::duration<double>) (chrono::steady_clock().now() - rhythmStart)).count() * FPS) << endl;

					// cout << "maxGoodness: " << maxGoodness << endl;

					// /*
					arrowChange(&window, window.cc.up, &player->input.up, rhythmPressUp, {&notes, &howGoodYouDoIt, &maxGoodness});
					arrowChange(&window, window.cc.left, &player->input.left, rhythmPressLeft, {&notes, &howGoodYouDoIt, &maxGoodness});
					arrowChange(&window, window.cc.right, &player->input.right, rhythmPressRight, {&notes, &howGoodYouDoIt, &maxGoodness});
					arrowChange(&window, window.cc.down, &player->input.down, rhythmPressDown, {&notes, &howGoodYouDoIt, &maxGoodness});
					// */

					/*
					arrowChange(&window, window.cc.up, &player->input.up, rhythmPressUp, {&notes});
					arrowChange(&window, window.cc.left, &player->input.left, rhythmPressLeft, {&notes});
					arrowChange(&window, window.cc.right, &player->input.right, rhythmPressRight, {&notes});
					arrowChange(&window, window.cc.down, &player->input.down, rhythmPressDown, {&notes});
					*/

					for (int x = 0; x < notes.size(); x++) {
						RhythmNote* rn = notes.at(x);
						rn->draw(&window, world, battleEntities);
						if (rn->x + RhythmNote::KEYSIZE < 0) {
							howGoodYouDoIt -= maxGoodness / 2;

							delete notes.at(x);
							notes.erase(notes.begin() + x);
							x--;
						}
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
					sideScreenDarken = 0;
					selector->snap = true;
					bool fighterLoss = true;
					bool fighterWin = true;
					// /*
					for (Fightable* f : window.playerTeam) {
						// cout << "Fighter hp: " << f->stats.hp << endl;
						fighterLoss = fighterLoss && (f->stats.hp <= 0);
					}
					for (Enemy* e : window.enemyTeam) {
						// cout << "Enemy hp: " << e->stats.hp << endl;						
						fighterWin = fighterWin && (e->stats.hp <= 0);
					}
					// */
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
						cout << "turnover, CHOOSEOPTION\n";
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

		// TODO: FIX DARKNESS LAG (LOOK AT HOW RENDERWINDOW DRAWCIRCLE WORKS TO FIX)
		if (sideScreenDarken != 0) {
			auto start1 = chrono::steady_clock().now();

			int width = (int) (window.WIDTH * window.scaleMultiplier);
			int height = (int) (window.HEIGHT * window.scaleMultiplier);
			SDL_Rect texture_rect = {0, 0, width, height};
			Uint32* pixelsTemp = nullptr;

			SDL_Surface* temp_surface = nullptr;
			SDL_Texture* temp_texture = nullptr;
			SDL_Texture* trueDiagonalTexture = threadCircularApplication(window, pixelsTemp, temp_texture, temp_surface, sideScreenDarken, texture_rect, THREADS, 1, 1, blackPerPixel, blackCompute);

			window.clear();
			SDL_RenderCopy(window.renderer, trueDiagonalTexture, NULL, &texture_rect);

			SDL_DestroyTexture(temp_texture);
			SDL_DestroyTexture(trueDiagonalTexture);
			SDL_FreeSurface(temp_surface);
			delete pixelsTemp;
			pixelsTemp = nullptr;

			auto end1 = chrono::steady_clock().now();
			chrono::duration<double> frameDone = end1 - start1;
			double millis = 1000 * frameDone.count();
			// cout << "darkness: " << millis << endl;
		}

		// cout << "predisplay\n";
		window.display();
		// cout << "postdisplay\n";

		// /*
		auto end = chrono::steady_clock().now();
		chrono::duration<double> frameDone = end - start;

		// cout << 1000 * frameDone.count() << endl;
		delay = 1000 * ((1.0 / FPS) - frameDone.count());
		if (delay > 0) {
			SDL_Delay(delay);
			delay = 0;
		}
		// cout << "THIS FRAME TOOK: " << round(((chrono::duration<double>) (chrono::steady_clock().now() - start)).count() * 1000) << endl;

		// cout << "delay: " << delay << endl;
		// */
	}

	return 0;
}