#include "RenderWindow.hpp"

using namespace std;

RenderWindow::RenderWindow(const char* title) : window(NULL), renderer(NULL) {
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	if (window == NULL) {
		cout << "Window failed to Init: " << SDL_GetError() << "\n"; 
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	zephyrea = TTF_OpenFont("res/gfx/zephyrea.ttf", 36);

	keyboard = SDL_GetKeyboardState(NULL);
	resizeWindow();
}

void RenderWindow::resizeWindow() {
	SDL_GetWindowSize(window, &actualWidth, &actualHeight);
	double wScale = 1.0 * actualWidth / WIDTH;
	double hScale = 1.0 * actualHeight / HEIGHT;

	cout << "actualWidth: " << actualWidth << " actualHeight: " << actualHeight << endl;
	// cout << "wScale: " << wScale << " hScale: " << hScale << endl;

	scaleMultiplier = min(wScale, hScale);
	// cout << "scaleMultiplier: " << scaleMultiplier << endl;
	xOrigin = (actualWidth - (WIDTH * scaleMultiplier)) / 2;
	yOrigin = (actualHeight - (HEIGHT * scaleMultiplier)) / 2;

	// cout << "xOrigin: " << xOrigin << " yOrigin: " << yOrigin << endl;
}

void RenderWindow::cleanUp() {
	SDL_DestroyWindow(window);
}

SDL_Texture* RenderWindow::loadTexture(const char* filePath) {
	SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);

	if (texture == NULL) {
		cout << "Failed to load a texture " << SDL_GetError() << "\n";
	}

	return texture;
}

void RenderWindow::clear() {
	SDL_RenderClear(renderer);
}

void RenderWindow::setColor(int r, int g, int b, int a) {
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void RenderWindow::drawLine(int x1, int y1, int x2, int y2, bool stationary) {
	if (stationary) {
		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	}
	else {
		SDL_RenderDrawLine(renderer, x1 - x, y1 - y, x2 - x, y2 - y);		
	}
}

SDL_Rect RenderWindow::getDestRect(Entity* entity, bool stationary) {
	SDL_Rect dest;
	if (stationary) {
		dest = entity->getRect();
	}
	else {
		double actualZoom = zoom;
		// cout << "actualZoom: " << actualZoom << endl;
		dest.x = (int) ceil((entity->x - x) * zoom);
		dest.y = (int) ceil((entity->y - y) * zoom);
		dest.w = (int) ceil(entity->show_width * zoom);
		dest.h = (int) ceil(entity->show_height * zoom);
	}
	scaleDestRect(dest);
	return dest;
}

void RenderWindow::scaleDestRect(SDL_Rect& dest) {
	dest.x = (int) ceil(dest.x * scaleMultiplier + xOrigin);
	dest.y = (int) ceil(dest.y * scaleMultiplier + yOrigin);
	dest.w = (int) ceil(dest.w * scaleMultiplier);
	dest.h = (int) ceil(dest.h * scaleMultiplier);
}

void RenderWindow::render(Entity* entity, bool stationary, int centerx, int centery) {
	if (entity->textureDraw) {
//		cout << "X: " << entity->x << "Y: " << entity->y << endl;

		SDL_Rect dest = getDestRect(entity, stationary);
		SDL_Rect src = entity->currentFrame;

		//	cout << "x2: " << entity->getsize().x << endl;
		//	cout << "y2: " << entity->getsize().y << endl;
		// SDL_RenderCopy(renderer, entity->texture.get(), &src, &dest);
		
		/*
		setColor(255, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &dest);
		setColor(0, 0, 0, 255);
		// */
		/*
		float c = cos(entity->angle);
		float s = sin(entity->angle);
		int w = dest.w;
		int h = dest.h;
		dest.w = c * w + s * h;
		dest.h = c * h + s * w;
		*/

		SDL_Point center = SDL_Point();
		center.x = (centerx == -1) ? src.w / 2 : centerx;
		center.y = (centery == -1) ? src.h / 2 : centery;
		if (!stationary) {
			center.x *= zoom;
			center.y *= zoom;
		}
		center.x *= scaleMultiplier;
		center.y *= scaleMultiplier;

		// cout << "angle: " << 180 * entity->angle / M_PI << endl;
		SDL_RendererFlip flip = SDL_FLIP_NONE;
		int entityflip = entity->flip;

		if (entityflip != 0) {
			// cout << entityflip << endl;
		}

		entityflip /= 4;
		if (entityflip % 2 == 1) {
			// cout << "vertical\n";
			flip = static_cast<SDL_RendererFlip>(flip | SDL_FLIP_VERTICAL);
		}
		entityflip /= 2;
		if (entityflip % 2 == 1) {
			// cout << "horizontal\n";
			flip = static_cast<SDL_RendererFlip>(flip | SDL_FLIP_HORIZONTAL);
		}

		SDL_RenderCopyEx(renderer, entity->texture.get(), &src, &dest, 180 * entity->angle / M_PI, &center, flip);

		if (temp == true && entity->flip != 0) {
			drawText(to_string(entity->flip), 0, 0, 255, 200, dest.x, dest.y, dest.w, dest.h);
		}
	}
	entity->customDraw(this);
}

void RenderWindow::display() {
	// /*
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	int w;
	int h;
	int r1x;
	int r1y;
	if (xOrigin == 0) { // TOP AND BOTTOM
		w = actualWidth;
		h = yOrigin;
		r1x = 0;
		r1y = actualHeight - h;
	}
	else { // LEFT AND RIGHT
		w = xOrigin;
		h = actualHeight;
		r1x = actualWidth - w;
		r1y = 0;
	}
	// cout << "w: " << w << " h: " << h << " r1x: " << r1x << " r1y: " << r1y << endl;
	SDL_Rect r1 = {0, 0, w, h};
	SDL_RenderFillRect(renderer, &r1);
	r1 = {r1x, r1y, w, h};
	SDL_RenderFillRect(renderer, &r1);
	// */
	SDL_RenderPresent(renderer);
}

void RenderWindow::drawCircle(int x, int y, int radius) {
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	for (int w = 0; w < radius * 2; w++) {
		for (int h = 0; h < radius * 2; h++) {
			int dx = radius - w; // horizontal offset
			int dy = radius - h; // vertical offset
			if ((dx * dx + dy * dy) <= (radius * radius)) {
				SDL_RenderDrawPoint(renderer, x + dx, y + dy);
			}
		}
	}
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
}

SDL_Surface* RenderWindow::getTextSurface(string text, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
	// as TTF_RenderText_Solid could only be used on
	// SDL_Surface then you have to create the surface first
//	cout << 1 << endl;
	SDL_Color color = {r, g, b, a};
//	cout << 1.5 << endl;
//	cout << SDL_GetError() << endl;
//	cout << TTF_GetError() << endl;
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(zephyrea, text.c_str(), color); 
//	cout << 2 << endl;
	return surfaceMessage;
}

void RenderWindow::drawScaledTextInBox(string text, unsigned char r, unsigned char g, unsigned char b, unsigned char a, int x, int y, int w, int h) {
	SDL_Surface* surfaceMessage = getTextSurface(text, r, g, b, a);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	double wScale = 1.0 * w / surfaceMessage->w;
	double hScale = 1.0 * h / surfaceMessage->h;
	double scalingSize = min(wScale, hScale);
	// cout << "scaleMultiplier: " << scaleMultiplier << endl;
	double hactual = surfaceMessage->h * scalingSize;
	// cout << "w: " << w << " h: " << h << endl;
	// cout << "hactual: " << hactual << endl;
	SDL_Rect Message_rect = {x, (int) (y + (h - hactual) / 2), (int) (surfaceMessage->w * scalingSize), (int) (hactual)};
	textRect(surfaceMessage, Message, Message_rect);
}


void RenderWindow::textRect(SDL_Surface* surfaceMessage, SDL_Texture* Message, SDL_Rect Message_rect) {
	scaleDestRect(Message_rect);
	// (0,0) is on the top left of the window/screen,
	// think a rect as the text's box,
	// that way it would be very simple to understand

	// Now since it's a texture, you have to put RenderCopy
	// in your game loop area, the area where the whole code executes

	// you put the renderer's name first, the Message,
	// the crop size (you can ignore this if you don't want
	// to dabble with cropping), and the rect which is the size
	// and coordinate of your texture
	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

	// Don't forget to free your surface and texture
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}

void RenderWindow::drawText(string text, unsigned char r, unsigned char g, unsigned char b, unsigned char a, int x, int y, int w, int h) {
	SDL_Surface* surfaceMessage = getTextSurface(text, r, g, b, a);
	// now you can convert it into a texture
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
//	cout << 3 << endl;

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = x;  //controls the rect's x coordinate 
	Message_rect.y = y; // controls the rect's y coordinte
	Message_rect.w = w; // controls the width of the rect
	Message_rect.h = h; // controls the height of the rect
	textRect(surfaceMessage, Message, Message_rect);
}

SDL_Texture* RenderWindow::getAreaTexture(SDL_Rect& rect, SDL_Texture* source) {
	SDL_Texture* result = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
	SDL_SetRenderTarget(renderer, result);
	SDL_RenderCopy(renderer, source, &rect, NULL);
	// the folowing line should reset the target to default(the screen)
	SDL_SetRenderTarget(renderer, NULL);
	// I also removed the RenderPresent funcion as it is not needed here			
	return result;
}
