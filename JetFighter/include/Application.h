#pragma once

#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

namespace jet {
	class Application {
	public:
		const static int SCREEN_WIDTH = 600;

		const static int SCREEN_HEIGHT = 600;

		Application();

		bool init();

		void close();

		SDL_Renderer* getRenderer();

		void renderScreen();

		void clearScreen(SDL_Color* color);

		void renderOnScreen(SDL_Texture* texture, SDL_Rect* destinationRect = NULL);

		void drawFillRectangle(SDL_Rect* rectangle, SDL_Color* color);

		void drawOutlinedRectangle(SDL_Rect* rectangle, SDL_Color* color);

		void drawLine(int startX, int startY, int endX, int endY, SDL_Color* color);

	private:
		SDL_Window* window;

		SDL_Renderer* renderer;

		void setRendererColor(SDL_Color* color);
	};
}
