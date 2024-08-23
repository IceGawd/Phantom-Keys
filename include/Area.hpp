#pragma once

#include "tmxlite/Map.hpp"
#include "tmxlite/TileLayer.hpp"
#include "tmxlite/LayerGroup.hpp"
#include "tmxlite/ObjectGroup.hpp"

#include "Player.hpp"
#include "SpawnZone.hpp"
#include "Interactable.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
using namespace tmx;

struct MinMax {
	float min;
	float max;
};

struct DiagonalTile {
	int index;
	Vector2u coords;
	Entity* entity;
};

struct Area {
	Entity* battleBackground;
	vector<SpawnZone> spawnzones;
	vector<Entity*> tilesetEntities;
	vector<DiagonalTile> diagonalTileEntities;
	vector<Interactable*> interactables;
	Map* tmxmap;
	int playerIndex = -1; // CAN ONLY NOT BE -1 IF PLACE PLAYER IS CALLED

	Area(RenderWindow& window, string path, vector<EnemyType*> enemyTypes, string bg, map<string, map<char, Mix_Chunk*>>& textNoise);

	void subRender(const Layer::Ptr& layer, RenderWindow& window, IntRect rect);
	void render(RenderWindow& window, Player* player, World* world, vector<GameObject*>& entities);
	void renderLayer(RenderWindow& window, const Layer::Ptr& layer, IntRect intrect);
	void diagonalTileFinder(RenderWindow& window, const Layer::Ptr& layer);
	int getIndexForID(int& ID);
	void placePlayer(Player* player);
	void collision(RenderWindow& window, Collideable* player);
};

Vector2u getTilesetCoords(int columns, int id);
float angleBetween(Vector2f vec1, Vector2f vec2);
float magnitude(Vector2f vec);
float dotProduct(Vector2f vec1, Vector2f vec2);
MinMax getMinMax(Vector2f vec, const vector<Vector2f>& points);
void addUnique(Vector2f vec, vector<float>& anglesToCheck);