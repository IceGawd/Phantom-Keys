#include "TextSlice.hpp"

TextSlice::TextSlice(RenderWindow& window, string t) : text(t) {
}

TextSlice::TextSlice(RenderWindow& window, string t, SDL_Color c) : text(t), color(c) {
}

TextSlice::TextSlice(RenderWindow& window, string t, SDL_Color c, vector<TextEffect> e) : text(t), color(c) {
	setEffects(e);
}

bool TextSlice::draw(RenderWindow& window) {
	// cout << "tts\n";
	bool done = (surfaces.size() == text.length());

	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;

	if (!done) {
		frames++;
		while (frames >= speed) {
			int ss = surfaces.size();
			char c = text.at(ss);
			SDL_Surface* surf = TTF_RenderText_Blended(window.zephyrea, string(1, c).c_str(), color);
			Entity* ent = new Entity(x, y, SDL_CreateTextureFromSurface(window.renderer, surf));

			char lookFor = tolower(c);
			// bool finished = Mix_ChannelFinished(7);
			sound++;
			// cout << finished << endl;
			if (sounds->find(lookFor) != sounds->end() && ((sound >= 3.25) || (ss == 0 || text.at(ss - 1) == ' '))) {
				// cout << c << endl;
				sound -= 3.25;
				if (sound <= 0) {
					sound = 0;
				}
				// cout << "works??\n";
				Mix_PlayChannel(7, sounds->at(lookFor), 0);
				// Mix_Chunk* temp = Mix_LoadWAV("res/Sounds/SFX/UI/Text/Text Reveal.wav");
				// Mix_PlayChannel(-1, temp, 0);
			}

			surfaces.push_back(surf);
			letters.push_back(ent);

			x += ent->width;
			// cout << ent->width << endl;
			if (x > XMAX && ((surfaces.size() == text.length()) || (text.at(surfaces.size())) != ' ')) {
				y += ent->height;
				x = XMIN;
			}
			frames -= speed;
		}
	}

	waveMod += WAVEDELTA;
	if (waveMod > 2 * M_PI) {
		waveMod -= 2 * M_PI;
	}
	// cout << waveMod << endl;

	for (int x = 0; x < letters.size(); x++) {
		Entity* ent = letters[x];
		float prevx = ent->x;
		float prevy = ent->y;
		SDL_Surface* surf = surfaces[x];
		Uint32* pixels = (Uint32*) surf->pixels;

		if (shaky) {
			ent->x += (2 * MOVEMENTMOD * random()) - MOVEMENTMOD;
			ent->y += (2 * MOVEMENTMOD * random()) - MOVEMENTMOD;
		}
		if (wavey) {
			// cout << MOVEMENTMOD * sin(waveMod + x * WAVEDELTA) << endl;
			ent->y += MOVEMENTMOD * sin(waveMod + (ent->x - XMIN) * 2.0 * M_PI / XMAX);
		}
		if (ghost) {
			for (int index = 0; index < surf->w * surf->h; index++) {
				SDL_GetRGBA(pixels[index], surf->format, &r, &g, &b, &a);
				if (a > 0) {
					pixels[index] = SDL_MapRGBA(surf->format, r, g, b, (Uint8) (255 * (GHOSTWAVE * sin(waveMod) + 50 / 2) / 100));
				}
			}
		}
		if (rainbow) {
			for (int index = 0; index < surf->w * surf->h; index++) {
				SDL_GetRGBA(pixels[index], surf->format, &r, &g, &b, &a);
				r = (Uint8) (127.5 * sin(waveMod) + 127.5);
				g = (Uint8) (127.5 * sin(waveMod + 2 * M_PI / 3) + 127.5);
				b = (Uint8) (127.5 * sin(waveMod + 4 * M_PI / 3) + 127.5);
				pixels[index] = SDL_MapRGBA(surf->format, r, g, b, a);
			}
		}
		if (diagonal_rainbow) {
			float entDist = ent->x + ent->y;
			for (int y = 0; y < surf->h; y++) {
				for (int x = 0; x < surf->w; x++) {
					int index = y * surf->w + x;
					float mod = waveMod + (entDist + y + x) * M_PI / 180;
					SDL_GetRGBA(pixels[index], surf->format, &r, &g, &b, &a);
					r = (Uint8) (127.5 * sin(mod) + 127.5);
					g = (Uint8) (127.5 * sin(mod + 2 * M_PI / 3) + 127.5);
					b = (Uint8) (127.5 * sin(mod + 4 * M_PI / 3) + 127.5);
					pixels[index] = SDL_MapRGBA(surf->format, r, g, b, a);
				}
			}
		}
		SDL_UpdateTexture(ent->texture.get(), NULL, pixels, surf->pitch);

		window.render(ent, true);

		ent->x = prevx;
		ent->y = prevy;
	}
	return done;
}

void TextSlice::setEffects(vector<TextEffect> e) {
	for (TextEffect& te : e) {
		if (te == SHAKY) {
			cout << "shak\n";
			shaky = true;
		}
		if (te == WAVEY) {
			cout << "wav\n";
			wavey = true;
		}
		if (te == GHOST) {
			cout << "gosos\n";
			ghost = true;
		}
		if (te == RAINBOW) {
			cout << "rainbo\n";
			rainbow = true;
		}
		if (te == DIAGONAL_RAINBOW) {
			cout << "diga\n";
			diagonal_rainbow = true;
		}
	}
}