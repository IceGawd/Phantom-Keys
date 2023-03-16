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

// From 0 to 2pi
float angleFromCoords(float x, float y) {
	float angle;
	if (x == 0) {
		if (y >= 0) {
			angle = 3.0 * M_PI / 2.0;
		}
		else {
			angle = M_PI / 2.0;
		}
	}
	else if (x > 0) {
		angle = -atan(y / x);
		if (angle < 0) {
			angle += 2.0 * M_PI;
		}
	}
	else {
		angle = M_PI - atan(y / x);
	}
	return angle;
}

void addUnique(Vector2f vec, vector<float>& anglesToCheck) {
	if (vec.x != 0) {
		float angle = M_PI / 2 - atan(vec.y / vec.x);
		if (find(anglesToCheck.begin(), anglesToCheck.end(), angle) == anglesToCheck.end()) {
			anglesToCheck.push_back(angle);
		}		
	}
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

void Area::renderLayer(RenderWindow& window, const Layer::Ptr& layer, IntRect intrect) {
	auto area = map->getTileCount();
	auto tileSize = map->getTileSize();
	auto offset = layer->getOffset();

	const vector<Tileset>& tilesets = map->getTilesets();
	// cout << layer->getName() << endl;

	if (layer->getType() == Layer::Type::Tile) {
		// cout << "TILELAYER\n\n";
		TileLayer& tl = layer->getLayerAs<TileLayer>();

		auto tilevector = tl.getTiles();
		int x = 0;
		int y = 0;

		// cout << left << endl;

		for (auto tile : tilevector) {
			if (x >= intrect.left && (x - intrect.left) <= intrect.width && y >= intrect.top && (y - intrect.top) <= intrect.height) {
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

						tilesetEntities[index]->x = x * tileSize.x + offset.x;
						tilesetEntities[index]->y = y * tileSize.y + offset.y;
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
	else if (layer->getType() == Layer::Type::Object) {
		ObjectGroup& og = layer->getLayerAs<ObjectGroup>();

		auto objectvector = og.getObjects();

		for (auto object : objectvector) {
			if (object.getTileID() != 0) {
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
				// cout << "HAHAHA\n";
				// window.drawText(to_string(object.getFlipFlags()), 0, 0, 255, 50, tilesetEntities[index]->x - window.x, tilesetEntities[index]->y - window.y, tileSize.x, tileSize.y);
				tilesetEntities[index]->show_width = tileSize.x;
				tilesetEntities[index]->show_height = tileSize.y;
			}

		}
	}
}

void Area::subRender(const Layer::Ptr& layer, RenderWindow& window, IntRect rect) {
	if (layer->getVisible()) {
		if (layer->getType() == Layer::Type::Group) {
			LayerGroup& lg = layer->getLayerAs<LayerGroup>();
			const vector<Layer::Ptr>& layerception = lg.getLayers();
			for (const Layer::Ptr& interlayer : layerception) {
				renderLayer(window, interlayer, rect);
			}
		}
		else {
			renderLayer(window, layer, rect);
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
	auto tileSize = map->getTileSize();

	const vector<Layer::Ptr>& layers = map->getLayers();

	int left = window.x / int(tileSize.x);
	int top = window.y / int(tileSize.y);
	int width = RenderWindow::WIDTH / int(tileSize.x) / window.zoom + 1;
	int height = RenderWindow::HEIGHT / int(tileSize.y) / window.zoom + 1;
	IntRect irect = {left, top, width, height};
	// IntRect bottomrect = {left, top + height - (height / 2 + 1), width, height / 2 + 1};
	// IntRect toprect = {left, top, width, height - (height / 2 + 1)};

	vector<int> preRenderIndexes;
	SDL_Rect pobj = player->getRect();
	SDL_Rect actual = {0, 0, 0, 0};
	SDL_Rect* intersect = &actual;

	for (int x = 0; x < playerIndex; x++) {
		const Layer::Ptr& layer = layers[x];
		subRender(layer, window, irect);
	}
	for (int x = playerIndex + 1; x < layers.size() - 1; x++) {
		const Layer::Ptr& layer = layers[x];
		const Layer::Ptr& perhaps = layers[x + 1];
		if (perhaps->getName().find("BGFG") != string::npos) {
			// cout << "BTG9910\n";
			ObjectGroup& og = perhaps->getLayerAs<ObjectGroup>();
			auto objectvector = og.getObjects();
			for (auto object : objectvector) {
				if (object.getShape() == Object::Shape::Rectangle) {
					auto rect = object.getAABB();

					SDL_Rect oobj = {int(rect.left), int(rect.top), int(rect.width), int(rect.height)};

					if (SDL_IntersectRect(&pobj, &oobj, intersect) == SDL_TRUE) {
						// cout << "yo\n";
						subRender(layer, window, irect);
						preRenderIndexes.push_back(x);
						break;
					}
				}
			}
			x++;
		}
	}
	player->draw(&window, world, entities);
	for (int x = playerIndex + 1; x < layers.size(); x++) {
		if (find(preRenderIndexes.begin(), preRenderIndexes.end(), x) == preRenderIndexes.end()) {
			const Layer::Ptr& layer = layers[x];
			subRender(layer, window, irect);
		}
	}
	// */
}

void Area::placePlayer(Player* player) {
	const vector<Layer::Ptr>& layers = map->getLayers();

	for (int x = 0; x < layers.size(); x++) {
		const Layer::Ptr& layer = layers[x];
		if (layer->getName() == "Sprite") {
			playerIndex = x;
			auto offset = layer->getOffset();
			// cout << "nice\n";
			ObjectGroup& og = layer->getLayerAs<ObjectGroup>();

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
}

void Area::collision(RenderWindow& window, Player* player) {
	const vector<Layer::Ptr>& layers = map->getLayers();

	vector<Vector2f> mtvs; // Minimum Translation Vectors

	for (const Layer::Ptr& layer : layers) {
		if (layer->getName().find("Collision") != string::npos) {
			// cout << "caosl\n";
			ObjectGroup& og = layer->getLayerAs<ObjectGroup>();
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
						cout << minpercent << endl;
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
						cout << "polygon\n";
						for (int x = 0; x < polygonPoints.size(); x++) {
							cout << "x: " << polygonPoints[x].x << " y: " << polygonPoints[x].y << endl;
						}
						cout << "player\n";
						for (int x = 0; x < playerPoints.size(); x++) {
							cout << "x: " << playerPoints[x].x << " y: " << playerPoints[x].y << endl;
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
						cout << "angle : " << angle << " smallestAxis: " << smallestAxis << " smallestLength: " << smallestLength;
						float angleDiff = min(abs(angle - smallestAxis), float(2 * M_PI - abs(angle - smallestAxis)));
						smallestAxis = angleDiff < M_PI / 2 ? smallestAxis : smallestAxis + M_PI;
						cout << " next smallestAxis: " << smallestAxis << endl;
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
		return;
	}
	else {
		Vector2f min = mtvs[0];
		for (int x = 1; x < mtvs.size(); x++) {
			if (magnitude(min) < magnitude(mtvs[x])) {
				min = mtvs[x];
			}
		}
		player->x += min.x;
		player->y += min.y;

		player->xvel = player->x - player->prevx;
		player->yvel = player->y - player->prevy;
		// collision(window, player);
	}
}