#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>

namespace jet {
	class Texture {
	public:
		//Initializes variables
		Texture();

		//Deallocates memory
		~Texture();

		//Loads image at specified path
		bool loadFromFile(SDL_Renderer* renderer, std::string path, SDL_Color* colorKeyPixel = NULL);

		//Deallocates texture
		void free();

		//Renders texture at given point
		void render(SDL_Renderer* renderer, int x, int y);

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* texture;

		//Image dimensions
		int width;
		int height;
	};
}
