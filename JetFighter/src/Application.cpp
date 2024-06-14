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

void jet::Application::clearScreen(SDL_Color* color) {
	setRendererColor(color);
	SDL_RenderClear(renderer);
}

void jet::Application::renderScreen() {
	SDL_RenderPresent(renderer);
}

void jet::Application::renderOnScreen(SDL_Texture* texture) {
	renderOnScreen(texture, NULL);
}

void jet::Application::renderOnScreen(SDL_Texture* texture, SDL_Rect* destinationRect) {
	SDL_RenderCopy(renderer, texture, NULL, destinationRect);
}

SDL_Texture* jet::Application::loadTexture(std::string path) {
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	} else {
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL) {
			printf("Unable to create texture from %s! Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
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
