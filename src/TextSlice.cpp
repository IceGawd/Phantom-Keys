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
	if (!done) {
		frames++;
		while (frames >= speed) {
			char c = text.at(surfaces.size());
			SDL_Surface* surf = TTF_RenderText_Solid(window.zephyrea, string(1, c).c_str(), color);
			
			/*
			SDL_LockSurface(surf);
			Uint32* pixels = (Uint32*) surf->pixels;
			pixels[x] = pixels[x + 1];

			/*
			for (int x = 0; x < surf->w * surf->h / 2; x++) {
				Uint8 r;
				Uint8 g;
				Uint8 b;				
				Uint8 a;
				// SDL_GetRGBA(x, surf->format, &r, &g, &b, &a);
				// cout << "pixels[x]: " << pixels[x] << " r: " << (int) r << " g: " << (int) g << " b: " << (int) b << " a: " << (int) a << endl;
				pixels[x] = pixels[x + 1];
			}
			// surf->pixels = pixels;
			SDL_UnlockSurface(surf);
			*/

			Entity* ent = new Entity(x, y, SDL_CreateTextureFromSurface(window.renderer, surf));
			char lookFor = tolower(c);
			// bool finished = Mix_ChannelFinished(7);
			sound++;
			// cout << finished << endl;
			if (sounds->find(lookFor) != sounds->end() && sound >= 4) {
				sound = 0;
				// cout << "works??\n";
				Mix_PlayChannel(7, sounds->at(lookFor), 0);
				// Mix_Chunk* temp = Mix_LoadWAV("res/Sounds/SFX/UI/Text/Text Reveal.wav");
				// Mix_PlayChannel(-1, temp, 0);
			}

			surfaces.push_back(surf);
			letters.push_back(ent);

			x += ent->width;
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

		if (shaky) {
			ent->x += (2 * MOVEMENTMOD * random()) - MOVEMENTMOD;
			ent->y += (2 * MOVEMENTMOD * random()) - MOVEMENTMOD;
		}
		if (wavey) {
			// cout << MOVEMENTMOD * sin(waveMod + x * WAVEDELTA) << endl;
			ent->y += MOVEMENTMOD * sin(waveMod + (ent->x - XMIN) * 2.0 * M_PI / XMAX);
		}

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
	}
}