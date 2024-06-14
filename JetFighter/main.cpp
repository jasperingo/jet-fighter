#include "include/Application.h"

int main(int argc, char* args[]) {
	jet::Application application;

	SDL_Texture* texture = NULL;

	if (application.init()) {
		texture = application.loadTexture("resources/jet.png");

		SDL_Event event;

		bool quit = false;

		while (!quit) {
			while (SDL_PollEvent(&event) != 0) {
				if (event.type == SDL_QUIT) {
					quit = true;
				}
			}

			application.clearScreen();

			application.renderOnScreen(texture);

			application.renderScreen();
		}
	}

	SDL_DestroyTexture(texture);

	texture = NULL;

	application.close();

	return 0;
}
