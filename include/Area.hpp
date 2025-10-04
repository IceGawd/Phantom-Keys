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
	vector<Layer*> layers;
	vector<pair<const Layer*, int>> heightLayers; // Super minor optimization: ints over Layers so we can for loop till next index
	vector<pair<pair<const Layer*, const Object*>, int>> heightObjects;
	vector<pair<pair<const Layer*, const Object*>, int>> heightObjectsSorted;
	int obj_index;
	int maxHeight;
	Map* tmxmap;
	int playerIndex = -1; // CAN ONLY NOT BE -1 IF PLACE PLAYER IS CALLED

	Area(RenderWindow& window, string path, vector<EnemyType*> enemyTypes, string bg, map<string, map<char, Mix_Chunk*>>& textNoise);
	~Area();

	void render(RenderWindow& window, Player* player, World* world, vector<GameObject*>& entities);
	void renderObject(RenderWindow& window, const Layer* layer, const Object& object); // Medium optimization: stop rendering objects out of range
	void renderTile(RenderWindow& window, const Layer* layer, IntRect& intrect, const TileLayer::Tile& tile, int x, int y);
	void renderLayer(RenderWindow& window, const Layer* layer, IntRect& intrect);
	void layerInit(RenderWindow& window, vector<EnemyType*> enemyTypes, map<string, map<char, Mix_Chunk*>>& textNoise, const Layer* layer);
	void diagonalTileFinder(RenderWindow& window, const Layer* layer);
	int getIndexForID(int& ID);
	void placePlayer(Player* player);
	void placePlayer(Player* player, const vector<Layer*>& layers);
	void collision(RenderWindow& window, Collideable* player);
	void collision(RenderWindow& window, Collideable* player, const vector<Layer*>& layers);
};

Vector2u getTilesetCoords(int columns, int id);
float angleBetween(Vector2f vec1, Vector2f vec2);
float magnitude(Vector2f vec);
float dotProduct(Vector2f vec1, Vector2f vec2);
MinMax getMinMax(Vector2f vec, const vector<Vector2f>& points);
void addUnique(Vector2f vec, vector<float>& anglesToCheck);