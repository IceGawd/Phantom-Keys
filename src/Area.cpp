#include "Area.hpp"

Vector2u getTilesetCoords(int columns, int id) {
	Vector2u answer;

	answer.x = id % columns;
	answer.y = id / columns;

	return answer;
}

float angleBetween(Vector2f vec1, Vector2f vec2) {
	Vector2f vec = vec1 - vec2;
	if (vec.x == 0) {
		if (vec.y >= 0) {
			return M_PI / -2.0;
		}
		else {
			return M_PI / 2.0;			
		}
	}
	else if (vec.x > 0) {
		return -atan(vec.y / vec.x);
	}
	else {
		return M_PI - atan(vec.y / vec.x);
	}
}

float magnitude(Vector2f vec) {
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

MinMax getMinMax(Vector2f vec, const vector<Vector2f>& points) {
	MinMax answer;
	float point = vec.x * points[0].x + vec.y * points[0].y;
	answer.min = point;
	answer.max = point;
	for (int x = 1; x < points.size(); x++) {
		point = vec.x * points[x].x + vec.y * points[x].y;
		answer.min = min(answer.min, point);
		answer.max = max(answer.max, point);
	}
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
	auto offset = layer->getOffset();

	const vector<Tileset>& tilesets = map->getTilesets();
	// cout << layer->getName() << endl;

	if (layer->getType() == Layer::Type::Tile) {
		// cout << "TILELAYER\n\n";
		TileLayer& tl = layer->getLayerAs<TileLayer>();

		IntRect renderBox;
		int left = window.x / int(tileSize.x);
		int top = window.y / int(tileSize.y);
		int width = RenderWindow::WIDTH / int(tileSize.x) / window.zoom + 1;
		int height = RenderWindow::HEIGHT / int(tileSize.y) / window.zoom + 1;

		auto tilevector = tl.getTiles();
		int x = 0;
		int y = 0;

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

				tilesetEntities[index]->x = rect.left + offset.x;
				tilesetEntities[index]->y = rect.top - rect.height + offset.y;
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

void Area::placePlayer(Player* player) {

	const vector<Layer::Ptr>& layers = map->getLayers();

	for (const Layer::Ptr& layer : layers) {
		if (layer->getName() == "Sprite") {
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
	int iterations = int(log2(10 * (player->xvel * player->xvel + player->yvel * player->yvel))) + 1;

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

						if (actual.w < actual.h) {
							if (actual.x > pobj.x) {
								player->x -= actual.w;
							}
							else {
								player->x += actual.w;
							}
						}
						else {
							if (actual.y > pobj.y) {
								player->y -= actual.h;
							}
							else {
								player->y += actual.h;
							}
						}
					}
				}
				else if (object.getShape() == Object::Shape::Polygon) {
					const vector<Vector2f>& points = object.getPoints();
					vector<Vector2f> polygonPoints;
					vector<Vector2f> playerPoints = player->getPoints();
					Vector2f velocityVector = {player->xvel, player->yvel};

					vector<float> anglesToCheck;
					anglesToCheck.push_back(0);
					anglesToCheck.push_back(M_PI / 2);

					for (int x = 0; x < points.size() - 1; x++) {
						Vector2f vec = points[x] - points[x + 1];
						if (vec.x != 0) {
							float angle = atan(vec.y / vec.x);
							if (find(anglesToCheck.begin(), anglesToCheck.end(), angle) == anglesToCheck.end()) {
								anglesToCheck.push_back(angle);
							}
						}
					}
					for (int x = 0; x < points.size(); x++) {
						polygonPoints.push_back(points[x] + object.getPosition());
					}

					float behind = 1;
					float parts = 0.5;
					for (int x = 0; x < iterations; x++) {
						bool seperated = false;
						vector<MinMax> precalculatedPolygonMM;
						for (int y = 0; y < anglesToCheck.size(); y++) {
							float angle = anglesToCheck[y];
							Vector2f vec;
							vec.x = cos(angle);
							vec.y = sin(angle);

							MinMax polygonMM;
							if (precalculatedPolygonMM.size() > y) {
								polygonMM = precalculatedPolygonMM[y];
							}
							else {
								polygonMM = getMinMax(vec, polygonPoints);
								precalculatedPolygonMM.push_back(polygonMM);
							}
							MinMax playerMM = getMinMax(vec, playerPoints);

							if ((polygonMM.max < playerMM.min) || (polygonMM.min > playerMM.max)) {
								seperated = true;
								break;
							}
						}

						behind = seperated ? behind + parts : behind - parts;
						if (behind > 1) {
							break;
						}
						Vector2f edit = velocityVector * parts;
						for (Vector2f& vec : playerPoints) {
							vec = seperated ? vec + edit : vec - edit;
						}
						parts /= 2;
					}
					/*
					if (behind < 1) {
						player->x -= player->xvel * (1 - behind);
						player->y -= player->yvel * (1 - behind);
						player->xvel *= behind;
						player->yvel *= behind;
					}
					*/
				}
			}
		}
	}
}