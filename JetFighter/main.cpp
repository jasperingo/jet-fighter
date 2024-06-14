#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* args[]) {
	SDL_Window* window = NULL;

	SDL_Surface* screenSurface = NULL;

	SDL_Surface* loadedSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not be initialized: %s\n", SDL_GetError());
	} else {
		window = SDL_CreateWindow("Jet Fighter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL) {
			printf("SDL could create window: %s\n", SDL_GetError());
		}
		else {
			int imageFlags = IMG_INIT_PNG;

			if (!(IMG_Init(imageFlags) & imageFlags)) {
				printf("SDL image could not be initialized: %s\n", IMG_GetError());
			} else {
				screenSurface = SDL_GetWindowSurface(window);

				SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xAB, 0x00, 0xFF));

				loadedSurface = IMG_Load("resources/jet.png");

				if (loadedSurface == NULL) {
					printf("SDL image could not load image: %s\n", IMG_GetError());
				} else {
					SDL_Rect imageRect = { 0, 0, 500, 500 };

					SDL_BlitSurface(loadedSurface, &imageRect, screenSurface, NULL);
				}

				SDL_UpdateWindowSurface(window);

				SDL_Event event;

				bool quit = false;

				while (!quit) {
					while (SDL_PollEvent(&event)) {
						if (event.type == SDL_QUIT) {
							quit = true;
						}
					}
				}
			}
			
		}
	}

	SDL_FreeSurface(loadedSurface);

	loadedSurface = NULL;

	SDL_DestroyWindow(window);

	window = NULL;

	IMG_Quit();

	SDL_Quit();

	return 0;
}
