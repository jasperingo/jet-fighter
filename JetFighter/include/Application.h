#pragma once

#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

namespace jet {
	class Application {
	public:
		const int SCREEN_WIDTH = 600;

		const int SCREEN_HEIGHT = 600;

		Application();

		bool init();

		void close();

		void clearScreen();

		void renderScreen();

		void renderOnScreen(SDL_Texture* texture);

		SDL_Texture* loadTexture(std::string path);

	private:
		SDL_Window* window;

		SDL_Renderer* renderer;
	};
}
