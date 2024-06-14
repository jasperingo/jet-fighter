#include "include/Application.h"

int main(int argc, char* args[]) {
	jet::Application application;

	SDL_Texture* texture = NULL;

	SDL_Rect textureBox = {
		jet::Application::SCREEN_WIDTH / 3,
		jet::Application::SCREEN_HEIGHT / 3,
		jet::Application::SCREEN_WIDTH / 4,
		jet::Application::SCREEN_HEIGHT / 4
	};

	SDL_Color clearColor = { 0xFF, 0xFF, 0xFF, 0xFF };

	SDL_Rect filledBox = { 
		jet::Application::SCREEN_WIDTH / 4, 
		jet::Application::SCREEN_HEIGHT / 4, 
		jet::Application::SCREEN_WIDTH / 2, 
		jet::Application::SCREEN_HEIGHT / 2 
	};

	SDL_Color filledBoxColor = { 0xFF, 0x00, 0x00, 0xFF };

	SDL_Rect outlinedBox = {
		jet::Application::SCREEN_WIDTH / 6,
		jet::Application::SCREEN_HEIGHT / 6,
		jet::Application::SCREEN_WIDTH * 2 / 3,
		jet::Application::SCREEN_HEIGHT * 2 / 3
	};

	SDL_Color outlinedBoxColor = { 0x00, 0xFF, 0xFA, 0xFF };

	SDL_Color lineColor = { 0x11, 0xBF, 0xFF, 0xFF };

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

			application.clearScreen(&clearColor);

			application.drawFillRectangle(&filledBox, &filledBoxColor);

			application.drawOutlinedRectangle(&outlinedBox, &outlinedBoxColor);

			application.drawLine(0, jet::Application::SCREEN_HEIGHT / 2, jet::Application::SCREEN_WIDTH, jet::Application::SCREEN_HEIGHT / 2, &lineColor);

			if (texture != NULL) {
				application.renderOnScreen(texture, &textureBox);
			}

			application.renderScreen();
		}
	}

	SDL_DestroyTexture(texture);

	texture = NULL;

	application.close();

	return 0;
}
