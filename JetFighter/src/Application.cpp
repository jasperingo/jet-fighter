#include "../include/Application.h"

jet::Application::Application() {
	window = NULL;

	renderer = NULL;
}

bool jet::Application::init() {
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize: %s\n", SDL_GetError());
		success = false;
	} else {
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL) {
			printf("Window could not be created: %s\n", SDL_GetError());
			success = false;
		} else {
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			if (renderer == NULL) {
				printf("Renderer could not be created: %s\n", SDL_GetError());
				success = false;
			} else {
				int imageFlags = IMG_INIT_PNG;

				if (!(IMG_Init(imageFlags) & imageFlags)) {
					printf("SDL image could not be initialized: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

void jet::Application::close() {
	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Renderer* jet::Application::getRenderer() {
	return renderer;
}

void jet::Application::clearScreen(SDL_Color* color) {
	setRendererColor(color);
	SDL_RenderClear(renderer);
}

void jet::Application::renderScreen() {
	SDL_RenderPresent(renderer);
}

void jet::Application::renderOnScreen(SDL_Texture* texture, SDL_Rect* destinationRect) {
	SDL_RenderCopy(renderer, texture, NULL, destinationRect);
}

void jet::Application::setRendererColor(SDL_Color* color) {
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
}

void jet::Application::drawLine(int startX, int startY, int endX, int endY, SDL_Color* color) {
	setRendererColor(color);
	SDL_RenderDrawLine(renderer, startX, startY, endX, endY);
}

void jet::Application::drawFillRectangle(SDL_Rect* rect, SDL_Color* color) {
	setRendererColor(color);
	SDL_RenderFillRect(renderer, rect);
}

void jet::Application::drawOutlinedRectangle(SDL_Rect* rect, SDL_Color* color) {
	setRendererColor(color);
	SDL_RenderDrawRect(renderer, rect);
}
