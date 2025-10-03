#include "Area.hpp"

Vector2u getTilesetCoords(int columns, int id) {
	Vector2u answer;

	answer.x = id % columns;
	answer.y = id / columns;

	return answer;
}

float angleBetween(Vector2f vec1, Vector2f vec2) {
	return acos(dotProduct(vec1, vec2) / (magnitude(vec1) * magnitude(vec2)));
}

float magnitude(Vector2f vec) {
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

float dotProduct(Vector2f vec1, Vector2f vec2) {
	return vec1.x * vec2.x + vec1.y * vec2.y;	
}

Vector2f vectorFromAngle(float angle) {
	Vector2f vec;
	vec.x = cos(angle);
	vec.y = -sin(angle);
	return vec;	
}

/**
 * Gets the minimum and maximum dot products of vec to every point in points
 * @param {vec} A vector that you are finding the min/max of
 * @param {points} The points that we are getting the dot products of
 * @return A datatype that holds the min and max dotproducts
 */
MinMax getMinMax(Vector2f vec, const vector<Vector2f>& points) {
	// vec.y *= -1;
	MinMax answer;
	float point = dotProduct(vec, points[0]);
	answer.min = point;
	answer.max = point;
	for (int x = 1; x < points.size(); x++) {
		point = dotProduct(vec, points[x]);
		answer.min = min(answer.min, point);
		answer.max = max(answer.max, point);
	}
	return answer;
}

/**
 * Modifies anglesToCheck to add the angle associated with vec IF the angle doesnt already exist in anglesToCheck
 * @param {vec} The vector we might add to anglesToCheck
 * @param {points} A list of angles that will be modified
 */
void addUnique(Vector2f vec, vector<float>& anglesToCheck) {
	if (vec.x != 0) {
		float angle = M_PI / 2 - atan(vec.y / vec.x);
		if (find(anglesToCheck.begin(), anglesToCheck.end(), angle) == anglesToCheck.end()) {
			anglesToCheck.push_back(angle);
		}
	}
}

void Area::layerInit(RenderWindow& window, vector<EnemyType*> enemyTypes, map<string, map<char, Mix_Chunk*>>& textNoise, const Layer* layer) {
	if (layer->getVisible()) {
		diagonalTileFinder(window, layer);
	}

	if (layer->getName().find("Spawn") != string::npos) {
		// cout << "spawn\n";
		vector<EnemyType*> types;
		for (EnemyType* et : enemyTypes) {
			if (layer->getName().find(et->name) != string::npos) {
				// cout << et->name << "\n";
				types.push_back(et);
			}
		}
		const ObjectGroup& og = layer->getLayerAs<ObjectGroup>();
		auto objectvector = og.getObjects();

		for (auto object : objectvector) {
			if (object.getShape() == Object::Shape::Rectangle) {
				auto rect = object.getAABB();
				SDL_Rect oobj = {int(rect.left), int(rect.top), int(rect.width), int(rect.height)};
				spawnzones.push_back(SpawnZone(oobj, types));					
			}
		}
	}
	
	// ADD INTERACTABLES
	if (layer->getName().find("Collision") != string::npos) {
		if (layer->getType() != Layer::Type::Group) {
			const ObjectGroup& og = layer->getLayerAs<ObjectGroup>();
			auto objectvector = og.getObjects();

			for (auto object : objectvector) {
				// TODO: Implemnent for all shapes and sizes ;)
				if (object.getShape() == Object::Shape::Rectangle) {
					auto rect = object.getAABB();

					string text = "";
					string noise = "";

					const vector<Property>& properties = object.getProperties();
					for (const Property& property : properties) {
						if (property.getName() == "InspectText") {
							text = property.getStringValue();
						}
						if (property.getName() == "InspectNoise") {
							noise = property.getStringValue();
						}
					}

					if (text != "" && noise != "") {
						// cout << "text: " << text << ", noise: " << noise << endl;
						Interactable* i = new Interactable((SDL_Rect) {int(rect.left), int(rect.top), int(rect.width), int(rect.height)}, new TextSequence({TextBox(window, {TextSlice(window, text, {255, 255, 255, 255}, {})})}, &textNoise[noise]));
						// cout << "made i\n";
						interactables.push_back(i);
						// cout << "pushback i\n";
					}
				}
			}
		}
	}

	const vector<Property>& properties = layer->getProperties();
	for (const Property& property : properties) {
		if (property.getName() == "height") {
			heightLayers.emplace_back(layer, property.getIntValue());
			maxHeight = max(maxHeight, property.getIntValue());
		}
	}
}

vector<Layer*> flattenLayers(const vector<Layer::Ptr>& layers) {
	vector<Layer*> result;

	for (const auto& layer : layers) {
		if (!layer) continue;

		if (layer->getType() == Layer::Type::Group) {
			const auto& inner = layer->getLayerAs<LayerGroup>().getLayers();
			auto flat = flattenLayers(inner);
			result.insert(result.end(), flat.begin(), flat.end());
		} else {
			result.push_back(layer.get()); // just borrow the pointer
		}
	}

	return result;
}

Area::Area(RenderWindow& window, string path, vector<EnemyType*> enemyTypes, string bg, map<string, map<char, Mix_Chunk*>>& textNoise) {
	battleBackground = new Entity(0, 0, window.loadTexture(bg.c_str()));
	battleBackground->show_width = RenderWindow::WIDTH;
	battleBackground->show_height = RenderWindow::HEIGHT;

	tmxmap = new Map();
	tmxmap->load(path);

	auto tileSize = tmxmap->getTileSize();

	const vector<Tileset>& tilesets = tmxmap->getTilesets();

	for (int x = 0; x < tilesets.size(); x++) {
		const Tileset& ts = tilesets[x];
		// cout << ts.getImagePath() << endl;

		auto tilevector = ts.getTiles();

		Entity* temp = new Entity();
		temp->setTexture(window.loadTexture(ts.getImagePath().c_str()));
		temp->width = tileSize.x;
		temp->height = tileSize.y;
		temp->show_width = tileSize.x;
		temp->show_height = tileSize.y;
		// cout << "tileSize.x " << tileSize.x << " tileSize.y " << tileSize.y << endl;
		temp->setRect();
		tilesetEntities.push_back(temp);

		/*
		// cout << "FIRST: " << ts.getFirstGID() << " LAST: " << ts.getLastGID() << endl;
		for (auto tile : tilevector) {
			// cout << tile.ID << " ";
		}
		// cout << "\n";
		*/
	}
	// cout << endl;

	// /*
	layers = flattenLayers(tmxmap->getLayers());

	maxHeight = 0;
	for (const Layer* layer : layers) {
		layerInit(window, enemyTypes, textNoise, layer);
	}
	// */
}

Area::~Area() {
	delete battleBackground;
	for (Entity* e : tilesetEntities) {
		delete e;
	}
	for (Interactable* i : interactables) {
		delete i;
	}
	delete tmxmap;
}

/**
 * Tiles in Tiled can be diagonally flipped, which cannot be done with simple flips and rotations. This function finds which tiles get diagonally flipped and creates a new texutre that is the diagonally flipped version of it.
 * @param {window} A renderwindow is used to create the diagonally flipped textures
 * @param {layer} The layer with tiles
 */
void Area::diagonalTileFinder(RenderWindow& window, const Layer* layer) {
	auto area = tmxmap->getTileCount();
	auto tileSize = tmxmap->getTileSize();

	const vector<Tileset>& tilesets = tmxmap->getTilesets();

	if (layer->getType() == Layer::Type::Tile) {
		const TileLayer& tl = layer->getLayerAs<TileLayer>();
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

					// cout << "tileSize.x " << tileSize.x << " tileSize.y " << tileSize.y << endl;

					SDL_Texture* diagonalTexture = window.getAreaTexture(imgPartRect, tilesetEntities[index]->texture.get());
					SDL_Texture* trueDiagonalTexture = SDL_CreateTexture(window.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, tileSize.x, tileSize.y);

					// /*

					Uint32* pixels;
					int pitch;
					SDL_SetRenderTarget(window.renderer, diagonalTexture);
					SDL_LockTexture( trueDiagonalTexture, NULL, reinterpret_cast<void**>(&pixels), &pitch );
					SDL_RenderReadPixels(window.renderer, NULL, SDL_PIXELFORMAT_RGBA8888, pixels, pitch);
					SDL_SetRenderTarget(window.renderer, NULL);

					SDL_DestroyTexture(diagonalTexture);

					// /*
					// cout << pixels << endl;
					// cout << pitch << endl;

					int rowlength = pitch / sizeof(unsigned int);

					/*
					for (int xTemp = 0; xTemp < tileSize.x * tileSize.y; xTemp++) {
						// cout << pixels[xTemp] << " ";
					}
					// cout << endl;

					// cout << "hlelo\n";
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
	const vector<Tileset>& tilesets = tmxmap->getTilesets();

	for (int x = 0; x < tilesets.size() - 1; x++) {
		if (ID < tilesets[x + 1].getFirstGID()) {
			ID -= tilesets[x].getFirstGID();
			return x;
		}
	}
	ID -= tilesets[tilesets.size() - 1].getFirstGID();
	return tilesets.size() - 1;
}

void Area::renderObject(RenderWindow& window, const Layer* layer, const Object& object) {
	if (object.getTileID() != 0) {
		const Vector2u& tileSize = tmxmap->getTileSize();
		const Vector2i& offset = layer->getOffset();

		const vector<Tileset>& tilesets = tmxmap->getTilesets();

		int ID = object.getTileID();
		int index = getIndexForID(ID);

		int cols = tilesets[index].getColumnCount();
		Vector2u coords = getTilesetCoords(cols, ID);

		const FloatRect& rect = object.getAABB();

		float angle = tilesetEntities[index]->angle = object.getRotation() * M_PI / 180;

		tilesetEntities[index]->x = rect.left + offset.x;
		tilesetEntities[index]->y = rect.top - rect.height + offset.y;
		tilesetEntities[index]->show_width = rect.width;
		tilesetEntities[index]->show_height = rect.height;
		tilesetEntities[index]->column = coords.x;
		tilesetEntities[index]->row = coords.y;
		tilesetEntities[index]->flip = object.getFlipFlags();
		tilesetEntities[index]->angle = angle;
		tilesetEntities[index]->setRect();

		window.render(tilesetEntities[index], false, 0, rect.height);
		// window.drawText(to_string(object.getFlipFlags()), 0, 0, 255, 50, tilesetEntities[index]->x - window.x, tilesetEntities[index]->y - window.y, tileSize.x, tileSize.y);
		tilesetEntities[index]->show_width = tileSize.x;
		tilesetEntities[index]->show_height = tileSize.y;
	}
}

void Area::renderTile(RenderWindow& window, const Layer* layer, IntRect& intrect, const TileLayer::Tile& tile, int x, int y) {
	if (tile.ID != 0) {
		const Vector2u& tileSize = tmxmap->getTileSize();
		const Vector2i& offset = layer->getOffset();

		const vector<Tileset>& tilesets = tmxmap->getTilesets();

		int ID = tile.ID;
		int index = getIndexForID(ID);

		int cols = tilesets[index].getColumnCount();
		Vector2u coords = getTilesetCoords(cols, ID);
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
			tilesetEntities[index]->x = x * tileSize.x + offset.x;
			tilesetEntities[index]->y = y * tileSize.y + offset.y;
			tilesetEntities[index]->column = coords.x;
			tilesetEntities[index]->row = coords.y;
			tilesetEntities[index]->flip = tile.flipFlags;
			tilesetEntities[index]->setRect();

			window.render(tilesetEntities[index]);
		}
	}
}

/**
 * Tiled tmxmaps have layers, this function renders a layer. 
 */
void Area::renderLayer(RenderWindow& window, const Layer* layer, IntRect& intrect) {
	if (layer->getVisible()) {
		const Vector2u& area = tmxmap->getTileCount();

		if (layer->getType() == Layer::Type::Tile) {
			const TileLayer& tl = layer->getLayerAs<TileLayer>();

			auto tilevector = tl.getTiles();
			int x = 0;
			int y = 0;

			// cout << left << endl;

			for (const TileLayer::Tile& tile : tilevector) {
				if (x >= intrect.left && (x - intrect.left) <= intrect.width && y >= intrect.top && (y - intrect.top) <= intrect.height) {
					renderTile(window, layer, intrect, tile, x, y);
				}
				x++;
				if (x == area.x) {
					x = 0;
					y++;
				}
			}
		}
		else if (layer->getType() == Layer::Type::Object) {
			const ObjectGroup& og = layer->getLayerAs<ObjectGroup>();

			const vector<Object>& objectvector = og.getObjects();

			for (const Object& object : objectvector) {
				renderObject(window, layer, object);
			}
		}
	}
}

void Area::render(RenderWindow& window, Player* player, World* world, vector<GameObject*>& entities) {
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

	// cout << "Player: " << player << endl;

	// /*
	for (SpawnZone& sz : spawnzones) {
		sz.spawnEnemies(&window, player, entities);
	}
	// */

	player->act(&window, world, entities);

	// cout << "Spawnzone\n";

	const Vector2u& area = tmxmap->getTileCount();
	const Vector2u& tileSize = tmxmap->getTileSize();

	int left = window.x / int(tileSize.x);
	int top = window.y / int(tileSize.y);
	int width = RenderWindow::WIDTH / int(tileSize.x) / window.zoom + 1;
	int height = RenderWindow::HEIGHT / int(tileSize.y) / window.zoom + 1;
	IntRect irect = {left, top, width, height};
	// IntRect bottomrect = {left, top + height - (height / 2 + 1), width, height / 2 + 1};
	// IntRect toprect = {left, top, width, height - (height / 2 + 1)};

	SDL_Rect actual = {0, 0, 0, 0};
	SDL_Rect* intersect = &actual;

	// cout << "Pre sub render\n";

	int hl = 0;

	for (int x = 0; x < playerIndex; x++) {
		const Layer* layer = layers[x];
		if (!(hl < heightLayers.size() && heightLayers[hl].first == layer)) {
			renderLayer(window, layer, irect);
		}
		else {
			hl++;
		}
	}

	GameObject* toBattle = nullptr;

	sort(entities.begin(), entities.end(), [](const GameObject* a, const GameObject* b) {
		return a->y + a->show_height < b->y + b->show_height;
	});

	int goIndex = 0;

	int x = 0;
	int y = 0;

	while (y < area.y + maxHeight) {
		for (pair<const Layer*, int> layer_height : heightLayers) {
			int mY = y - layer_height.second;
			if (mY >= 0 && mY < area.y) {
				const TileLayer::Tile& tile = layer_height.first->getLayerAs<TileLayer>().getTiles().at(mY * area.x + x);
				if (x >= irect.left && (x - irect.left) <= irect.width && mY >= irect.top && (mY - irect.top) <= irect.height) {
					renderTile(window, layer_height.first, irect, tile, x, mY);
				}
			}
		}

		x++;
		if (x == area.x) {
			x = 0;
			y++;

			while (goIndex < entities.size() && entities[goIndex]->y + entities[goIndex]->show_height < y * tileSize.y) {
				if (entities[goIndex]->draw(&window, world, entities)) {
					toBattle = entities[goIndex];
				}
				goIndex++;
			}
		}
	}

	for (int x = playerIndex + 1; x < layers.size(); x++) {
		const Layer* layer = layers[x];
		if (!(hl < heightLayers.size() && heightLayers[hl].first == layer)) {
			renderLayer(window, layer, irect);
		}
		else {
			hl++;
		}
	}
	// */

	// cout << "Post another subrender???\n";

	// /* BATTLETRANSITION
	if (toBattle != nullptr && window.gamestate == BATTLETRANSITION) {
		window.turnstate = CHOOSEOPTION; // If check turnstate exists, this (and other places where this is used) is wrong
		window.savedX = window.x;
		window.savedY = window.y;
		window.savedZoom = window.zoom;
		window.x = 0;
		window.y = 0;
		window.zoom = 1.0;
		player->changeSpriteSheet("battleidle");

		Enemy* battling = (Enemy*) toBattle;
		int enemies = 1;
		while (enemies != 3 && random() > 0.5) {
			enemies++;
		}
		// enemies = 3;
		// window.enemyTeam.clear();

		while (!window.turnOrder.empty()) {
			window.turnOrder.pop();
		}

		// Select Enemies
		if (enemies >= battling->zone->dudes.size()) {
			window.enemyTeam = battling->zone->dudes;
			// cout << "copy???\n";
		}
		else {
			window.enemyTeam.push_back(battling);
			// cout << "added " << battling << endl;
			enemies--;

			while (enemies != 0) {
				Enemy* toAdd = nullptr;
				for (Enemy* d : battling->zone->dudes) {
					if ((find(window.enemyTeam.begin(), window.enemyTeam.end(), d) == window.enemyTeam.end()) && ((toAdd == nullptr) || (player->distance(toAdd) > player->distance(d)))) {
						toAdd = d;
					}
				}
				// cout << "added " << toAdd << endl;
				window.enemyTeam.push_back(toAdd);
				enemies--;
			}
		}
		// Turn Order
		int total = 0;
		vector<Fightable*> tempOrder;
		for (int index = 0; index < window.enemyTeam.size(); index++) {
			Fightable* f = window.enemyTeam.at(index);

			tempOrder.push_back(f);
			total += f->stats.agility;
			f->battleOriginX = (index == 0 && window.enemyTeam.size() != 2) ? 800 : 925;
			f->battleOriginY = (window.enemyTeam.size() == 2) ? 115 + index * 230 : ((1.5 * index - 2.5) * index + 2) * 115;
			f->battleX = f->battleOriginX;
			f->battleY = f->battleOriginY;
			// cout << "index: " << index << endl;
			// cout << "window.enemyTeam.size(): " << window.enemyTeam.size() << endl;
			// cout << "f->battleX: " << f->battleX << endl;
			// cout << "f->battleY: " << f->battleY << endl;
			f->flip = 0;
		}
		for (int index = 0; index < window.playerTeam.size(); index++) {
			Fightable* f = window.playerTeam.at(index);

			tempOrder.push_back(f);
			total += f->stats.agility;
			f->battleInit(window, index);
		}

		while (tempOrder.size() > 0) {
			int val = random() * total;
			Fightable* toAdd;
			int x = -1;
			while (val >= 0) {
				x++;
				toAdd = tempOrder[x];
				val -= toAdd->stats.agility;
			}
			tempOrder.erase(tempOrder.begin() + x);
			total -= toAdd->stats.agility;
			window.turnOrder.push(toAdd);
		}
	}

	// cout << "Area render ender bender fender commender bend her lend mer-men bear end <<<<<<<<<<<<<<<\n";
	// */
}

void Area::placePlayer(Player* player) {
	placePlayer(player, layers);
}


void Area::placePlayer(Player* player, const vector<Layer*>& layers) {
	// cout << "placePlayer start\n";
	for (int x = 0; x < layers.size(); x++) {
		const Layer* layer = layers[x];
		if (layer->getName() == "Sprite") {
			playerIndex = x;
			auto offset = layer->getOffset();
			// cout << "nice\n";
			const ObjectGroup& og = layer->getLayerAs<ObjectGroup>();

			auto objectvector = og.getObjects();

			int x = objectvector[0].getAABB().left;
			int y = objectvector[0].getAABB().top - objectvector[0].getAABB().height;
			for (auto object : objectvector) {
				if (x > object.getAABB().left) {
					x = object.getAABB().left;
				}
				if (y > object.getAABB().top - object.getAABB().height) {
					y = object.getAABB().top - object.getAABB().height;
				}
			}
			player->x = x + offset.x;
			player->y = y + offset.y;
		}
	}
	// cout << "placePlayer end\n";
}

void Area::collision(RenderWindow& window, Collideable* player) {
	collision(window, player, layers);
}

void Area::collision(RenderWindow& window, Collideable* player, const vector<Layer*>& layers) {
	// cout << "start collide: " << player << endl;
	int iters = 1;

	for (int i = 0; i < iters; i++) {
		vector<Vector2f> mtvs; // Minimum Translation Vectors

		for (const Layer* layer : layers) {
			if (layer->getName().find("Collision") != string::npos) {
				// cout << "caosl\n";
				const ObjectGroup& og = layer->getLayerAs<ObjectGroup>();
				auto objectvector = og.getObjects();

				for (auto object : objectvector) {
					if (object.getShape() == Object::Shape::Rectangle) {
						SDL_Rect actual = {0, 0, 0, 0};
						SDL_Rect* intersect = &actual;

						auto rect = object.getAABB();

						SDL_Rect pobj = player->getHitbox();
						SDL_Rect oobj = {int(rect.left), int(rect.top), int(rect.width), int(rect.height)};

						SDL_Rect* pstar = &pobj;
						SDL_Rect* ostar = &oobj;

						if (SDL_IntersectRect(pstar, ostar, intersect) == SDL_TRUE) {
							// cout << "itnerasd\n";
							/*
							float xpercent = abs(1.0 * actual.w / player->xvel);
							float ypercent = abs(1.0 * actual.h / player->yvel);
							float minpercent = min(xpercent, ypercent);
							if (minpercent > 1) {
								minpercent = 1;
							}
							// cout << minpercent << endl;
							player->x -= player->xvel * minpercent;
							player->y -= player->yvel * minpercent;
							*/

							// cout << "x: " << player->x << " y: " << player->y << " prevx: " << player->prevx << " prevy: " << player->prevy << " xvel: " << player->xvel << " yvel: " << player->yvel << endl;

							// /*
							Vector2f mtv;
							if (actual.w < actual.h) {
								if (actual.x > pobj.x) {
									mtv.x = -actual.w;
								}
								else {
									mtv.x = actual.w;
								}
							}
							else {
								if (actual.y > pobj.y) {
									mtv.y = -actual.h;
								}
								else {
									mtv.y = actual.h;
								}
							}
							mtvs.push_back(mtv);
							// player->xvel = player->x - player->prevx;
							// player->yvel = player->y - player->prevy;
							// */
						}
					}
					else if (object.getShape() == Object::Shape::Polygon) {
						const vector<Vector2f>& points = object.getPoints();
						vector<Vector2f> polygonPoints;
						vector<Vector2f> playerPoints = player->getPoints();
						Vector2f velocityVector = {player->xvel, player->yvel};

						vector<float> anglesToCheck;
						anglesToCheck.push_back(M_PI / 2);
						anglesToCheck.push_back(M_PI);

						for (int x = 0; x < points.size() - 1; x++) {
							addUnique(points[x] - points[x + 1], anglesToCheck);
						}
						addUnique(points[0] - points[points.size() - 1], anglesToCheck);

						bool allPointsOut = true;
						for (int x = 0; x < points.size(); x++) {
							polygonPoints.push_back(points[x] + object.getPosition());
							if (window.x < polygonPoints[x].x && window.x + RenderWindow::WIDTH > polygonPoints[x].x && window.y < polygonPoints[x].y && window.y + RenderWindow::HEIGHT > polygonPoints[x].y) {
								allPointsOut = false;
							}
							// cout << "x: " << polygonPoints[x].x << " y: " << polygonPoints[x].y << endl;
						}
						if (allPointsOut) {
							continue;
						}
						// cout << "start\n";

						bool seperated = false;
						float smallestAxis;
						float smallestLength;
						bool first = true;
						for (int y = 0; y < anglesToCheck.size(); y++) {
							float angle = anglesToCheck[y];
							// cout << "angle: " << angle << " cos " << cos(angle) << " sin " << sin(angle) << endl;
							Vector2f vec = vectorFromAngle(angle);

							MinMax polygonMM = getMinMax(vec, polygonPoints);
							MinMax playerMM = getMinMax(vec, playerPoints);

							float length = min(polygonMM.max - playerMM.min, playerMM.max - polygonMM.min);
							// cout << "mms: " << polygonMM.min << " " << polygonMM.max << " " << playerMM.min << " " << playerMM.max;
							// cout << " length: " << length << endl;
							if (length < 0) {
								seperated = true;
								break;
							}
							else if (first || length < smallestLength) {
								smallestAxis = angle;
								smallestLength = length;
								first = false;
							}
						}
						if (!seperated) {
							Vector2f mtv;
							/*
							// cout << "polygon\n";
							for (int x = 0; x < polygonPoints.size(); x++) {
								// cout << "x: " << polygonPoints[x].x << " y: " << polygonPoints[x].y << endl;
							}
							// cout << "player\n";
							for (int x = 0; x < playerPoints.size(); x++) {
								// cout << "x: " << playerPoints[x].x << " y: " << playerPoints[x].y << endl;
							}
							*/
							/*
							window.setColor(255, 0, 0, 255);
							for (int x = 0; x < polygonPoints.size() - 1; x++) {
								window.drawLine(polygonPoints[x].x, polygonPoints[x].y, polygonPoints[x + 1].x, polygonPoints[x + 1].y, false);
							}
							window.drawLine(polygonPoints[0].x, polygonPoints[0].y, polygonPoints[polygonPoints.size() - 1].x, polygonPoints[polygonPoints.size() - 1].y, false);
							
							window.setColor(0, 0, 255, 255);
							for (int x = 0; x < playerPoints.size() - 1; x++) {
								window.drawLine(playerPoints[x].x, playerPoints[x].y, playerPoints[x + 1].x, playerPoints[x + 1].y, false);
							}
							window.drawLine(playerPoints[0].x, playerPoints[0].y, playerPoints[playerPoints.size() - 1].x, playerPoints[playerPoints.size() - 1].y, false);
							*/
							// cout << "do smth\n";
							// /*
							// smallestLength += 1;
							float angle = angleFromCoords(player->xvel, player->yvel);
							// cout << "angle : " << angle << " smallestAxis: " << smallestAxis << " smallestLength: " << smallestLength;
							float angleDiff = min(abs(angle - smallestAxis), float(2 * M_PI - abs(angle - smallestAxis)));
							smallestAxis = angleDiff < M_PI / 2 ? smallestAxis : smallestAxis + M_PI;
							// cout << " next smallestAxis: " << smallestAxis << endl;
							mtv.x = -smallestLength * cos(smallestAxis);
							mtv.y = smallestLength * sin(smallestAxis);
							mtvs.push_back(mtv);
							// player->xvel = player->x - player->prevx;
							// player->yvel = player->y - player->prevy;
							// */
						}
					}
				}
			}
		}

		if (mtvs.size() == 0) {
			// cout << "end empty collide: " << player << endl;
			return;
		}
		else {
			// cout << "iteration: " << i << endl;
			Vector2f min = mtvs[0];
			// cout << "MTV #0: " << min.x << " " << min.y << endl;
			for (int x = 1; x < mtvs.size(); x++) {
				// cout << "MTV #" << x << ": " << mtvs[x].x << " " << mtvs[x].y << endl;
				if (abs(min.x) < abs(mtvs[x].x)) {
					min.x = mtvs[x].x;
				}
				if (abs(min.y) < abs(mtvs[x].y)) {
					min.y = mtvs[x].y;
				}
			}

			// cout << "min.x: " << min.x << "min.y" << min.y << endl;
			player->x += min.x;
			player->y += min.y;

			player->xvel = player->x - player->prevx;
			player->yvel = player->y - player->prevy;
			// collision(window, player);

			iters = mtvs.size() + 1;
		}
	}
	// cout << "end collision 2: " << player << endl;
}