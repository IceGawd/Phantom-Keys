#pragma once

#include "tmxlite/Map.hpp"
#include "tmxlite/TileLayer.hpp"
#include "tmxlite/LayerGroup.hpp"
#include "tmxlite/ObjectGroup.hpp"

#include "Player.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

using namespace std;
using namespace tmx;

Vector2u getTilesetCoords(int columns, int id);

struct DiagonalTile {
	int index;
	Vector2u coords;
	Entity* entity;
};

struct Area {
	vector<Entity*> tilesetEntities;
	vector<DiagonalTile> diagonalTileEntities;
	Map* map;

	Area(RenderWindow& window, string path);

	void render(RenderWindow& window);
	void renderLayer(RenderWindow& window, const Layer::Ptr& layer);
	void diagonalTileFinder(RenderWindow& window, const Layer::Ptr& layer);
	int getIndexForID(int& ID);
	void placePlayer(Player* player);
	void collision(RenderWindow& window, Player* player);
};