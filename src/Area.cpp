#include "Area.hpp"

Vector2u getTilesetCoords(int columns, int id) {
	Vector2u answer;

	answer.x = id % columns;
	answer.y = id / columns;

	return answer;
}

Area::Area(RenderWindow& window, string path) {
	map = new Map();
	map->load(path);

	auto tileSize = map->getTileSize();

	const vector<Tileset>& tilesets = map->getTilesets();

	for (int x = 0; x < tilesets.size(); x++) {
		const Tileset& ts = tilesets[x];
		cout << ts.getImagePath() << endl;

		auto tilevector = ts.getTiles();
		
		Entity* temp = new Entity();
		temp->setTexture(window.loadTexture(ts.getImagePath().c_str()));
		temp->width = tileSize.x;
		temp->height = tileSize.y;
		temp->show_width = tileSize.x;
		temp->show_height = tileSize.y;
		cout << "tileSize.x " << tileSize.x << " tileSize.y " << tileSize.y << endl;
		temp->setRect();
		tilesetEntities.push_back(temp);

		cout << "FIRST: " << ts.getFirstGID() << " LAST: " << ts.getLastGID() << endl;
		for (auto tile : tilevector) {
			cout << tile.ID << " ";
		}
		cout << "\n";
	}
	cout << endl;

	// /*
	const vector<Layer::Ptr>& layers = map->getLayers();

	for (const Layer::Ptr& layer : layers) {
		if (layer->getVisible()) {
			if (layer->getType() == Layer::Type::Group) {
				LayerGroup& lg = layer->getLayerAs<LayerGroup>();
				const vector<Layer::Ptr>& layerception = lg.getLayers();
				for (const Layer::Ptr& interlayer : layerception) {
					diagonalTileFinder(window, interlayer);
				}
			}
			else {
				diagonalTileFinder(window, layer);
			}
		}
	}
	// */
}

void Area::diagonalTileFinder(RenderWindow& window, const Layer::Ptr& layer) {
	auto area = map->getTileCount();
	auto tileSize = map->getTileSize();

	const vector<Tileset>& tilesets = map->getTilesets();

	if (layer->getType() == Layer::Type::Tile) {
		TileLayer& tl = layer->getLayerAs<TileLayer>();
		auto tilevector = tl.getTiles();

		int x = 0;
		int y = 0;

		for (auto tile : tilevector) {
			if (tile.flipFlags % 4 == 2) {
				int ID = tile.ID;
				int index = getIndexForID(ID);
				int cols = tilesets[index].getColumnCount();
				Vector2u coords = getTilesetCoords(cols, ID);

				bool notIn = true;
				for (DiagonalTile& dt : diagonalTileEntities) {
					if (dt.index == index && dt.coords.x == coords.x && dt.coords.y == coords.y) {
						notIn = false;
						break;
					}
				}
				if (notIn) {
					SDL_Rect imgPartRect;

					imgPartRect.x = coords.x * tileSize.x;
					imgPartRect.y = coords.y * tileSize.y;
					imgPartRect.w = tileSize.x;
					imgPartRect.h = tileSize.y;

					cout << "tileSize.x " << tileSize.x << " tileSize.y " << tileSize.y << endl;

					SDL_Texture* diagonalTexture = window.getAreaTexture(imgPartRect, tilesetEntities[index]->texture.get());					
					SDL_Texture* trueDiagonalTexture = SDL_CreateTexture(window.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, tileSize.x, tileSize.y);
					
					// /*

					Uint32* pixels;
					int pitch;
					SDL_SetRenderTarget(window.renderer, diagonalTexture);
					SDL_LockTexture( trueDiagonalTexture, NULL, reinterpret_cast<void**>(&pixels), &pitch );
					SDL_RenderReadPixels(window.renderer, NULL, SDL_PIXELFORMAT_RGBA8888, pixels, pitch);
					SDL_SetRenderTarget(window.renderer, NULL);

					// /*
					cout << pixels << endl;
					cout << pitch << endl;

					int rowlength = pitch / sizeof(unsigned int);

					/*
					for (int xTemp = 0; xTemp < tileSize.x * tileSize.y; xTemp++) {
						cout << pixels[xTemp] << " "; 
					}
					cout << endl;

					cout << "hlelo\n";
					*/

					for (int yTemp = 1; yTemp < rowlength; yTemp++) {
						for (int xTemp = 0; xTemp < yTemp; xTemp++) {
							// cout << pixels[yTemp * rowlength + xTemp] << " " << pixels[xTemp * rowlength + yTemp] << endl;
							swap(pixels[yTemp * rowlength + xTemp], pixels[xTemp * rowlength + yTemp]);
							// cout << pixels[yTemp * rowlength + xTemp] << " " << pixels[xTemp * rowlength + yTemp] << endl << endl;
						}
					}

					// Also don't forget to unlock your texture once you're done.
					SDL_UnlockTexture( trueDiagonalTexture );
					// */
					Entity* temp = new Entity();
					temp->setTexture(trueDiagonalTexture);
					temp->fullPicSize();
					temp->setRect();

					DiagonalTile dt;
					dt.index = index;
					dt.coords = coords;
					dt.entity = temp;
					diagonalTileEntities.push_back(dt);
				}
			}
			x++;
			if (x == area.x) {
				x = 0;
				y++;
			}
		}
	}
}

int Area::getIndexForID(int& ID) {
	const vector<Tileset>& tilesets = map->getTilesets();

	for (int x = 0; x < tilesets.size() - 1; x++) {
		if (ID < tilesets[x + 1].getFirstGID()) {
			ID -= tilesets[x].getFirstGID();
			return x;
		}
	}
	ID -= tilesets[tilesets.size() - 1].getFirstGID();
	return tilesets.size() - 1;
}

void Area::renderLayer(RenderWindow& window, const Layer::Ptr& layer) {
	auto area = map->getTileCount();
	auto tileSize = map->getTileSize();

	const vector<Tileset>& tilesets = map->getTilesets();
	// cout << layer->getName() << endl;
	if (layer->getType() == Layer::Type::Tile) {
		// cout << "TILELAYER\n\n";
		TileLayer& tl = layer->getLayerAs<TileLayer>();

		auto tilevector = tl.getTiles();
		int x = 0;
		int y = 0;

		IntRect renderBox;
		int left = window.x / static_cast<int>(tileSize.x);
		int top = window.y / static_cast<int>(tileSize.y);
		int width = RenderWindow::WIDTH / static_cast<int>(tileSize.x) / window.zoom;
		int height = RenderWindow::HEIGHT / static_cast<int>(tileSize.y) / window.zoom;

		// cout << left << endl;

		for (auto tile : tilevector) {
			if (x >= left && (x - left) <= width && y >= top && (y - top) <= height) {
				// cout << tile.ID << " ";
				if (tile.ID != 0) {
					int ID = tile.ID;
					int index = getIndexForID(ID);

					int cols = tilesets[index].getColumnCount();
					// cout << "cols: " << cols << endl;
					Vector2u coords = getTilesetCoords(cols, ID);
// /*
					if (tile.flipFlags % 4 == 2) {
						for (DiagonalTile& dt : diagonalTileEntities) {
							if (dt.index == index && dt.coords.x == coords.x && dt.coords.y == coords.y) {
								dt.entity->x = x * tileSize.x;
								dt.entity->y = y * tileSize.y;
								dt.entity->flip = tile.flipFlags;

								window.render(dt.entity);
							}
						}
					}
					else {
// */
						// cout << "coords.x " << coords.x << " coords.y " << coords.y << endl;

						tilesetEntities[index]->x = x * tileSize.x;
						tilesetEntities[index]->y = y * tileSize.y;
						tilesetEntities[index]->column = coords.x;
						tilesetEntities[index]->row = coords.y;
						tilesetEntities[index]->flip = tile.flipFlags;
						tilesetEntities[index]->setRect();

						window.render(tilesetEntities[index]);
						// cout << "rendered" << endl;
					}
				}
			}
			x++;
			if (x == area.x) {
				x = 0;
				y++;
			}
		}
		// cout << "\n";
	}
	if (layer->getType() == Layer::Type::Object) {
		ObjectGroup& og = layer->getLayerAs<ObjectGroup>();

		auto objectvector = og.getObjects();

		for (auto object : objectvector) {
			if (object.getTileID() != 0) {
				int ID = object.getTileID();
				int index = getIndexForID(ID);

				int cols = tilesets[index].getColumnCount();
				Vector2u coords = getTilesetCoords(cols, ID);

				const FloatRect& rect = object.getAABB();

				tilesetEntities[index]->x = rect.left;
				tilesetEntities[index]->y = rect.top - rect.height;
				tilesetEntities[index]->show_width = rect.width;
				tilesetEntities[index]->show_height = rect.height;
				tilesetEntities[index]->column = coords.x;
				tilesetEntities[index]->row = coords.y;
				tilesetEntities[index]->flip = object.getFlipFlags();
				tilesetEntities[index]->setRect();

				window.render(tilesetEntities[index]);
				tilesetEntities[index]->show_width = tileSize.x;
				tilesetEntities[index]->show_height = tileSize.y;
			}

		}
	}
}

void Area::render(RenderWindow& window) {
	/*
	// cout << diagonalTileEntities[0].entity->width << " " << diagonalTileEntities[0].entity->height << endl;
	int x = 0;
	for (auto dt : diagonalTileEntities) {
		dt.entity->x = x;
		window.render(dt.entity);
		x += dt.entity->width;
	}
	*/
	// /*
	const vector<Layer::Ptr>& layers = map->getLayers();

	for (const Layer::Ptr& layer : layers) {
		if (layer->getVisible()) {
			if (layer->getType() == Layer::Type::Group) {
				LayerGroup& lg = layer->getLayerAs<LayerGroup>();
				const vector<Layer::Ptr>& layerception = lg.getLayers();
				for (const Layer::Ptr& interlayer : layerception) {
					renderLayer(window, interlayer);
				}
			}
			else {
				renderLayer(window, layer);
			}
		}
	}
	// */
}