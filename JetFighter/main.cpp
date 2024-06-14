#include "include/Application.h"
#include "include/Texture.h"

int main(int argc, char* args[]) {
	jet::Application application;

	jet::Texture jetTexture;

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

	jet::Texture stickTexture;
	jet::Texture backgroundTexture;

	SDL_Color colorKey = { 0, 0xFF, 0xFF, 0 };

	if (application.init()) {
		bool stickLoaded = stickTexture.loadFromFile(application.getRenderer(), "resources/stick.png", &colorKey);
		bool bgLoaded = backgroundTexture.loadFromFile(application.getRenderer(), "resources/background.png");

		SDL_Event event;

		bool quit = false;

		while (!quit) {
			while (SDL_PollEvent(&event) != 0) {
				if (event.type == SDL_QUIT) {
					quit = true;
				}
			}

			application.clearScreen(&clearColor);

			if (stickLoaded && bgLoaded) {
				backgroundTexture.render(application.getRenderer(), 0, 0);

				stickTexture.render(application.getRenderer(), 240, 190);
			} else {
				application.drawFillRectangle(&filledBox, &filledBoxColor);

				application.drawOutlinedRectangle(&outlinedBox, &outlinedBoxColor);

				application.drawLine(0, 
					jet::Application::SCREEN_HEIGHT / 2, 
					jet::Application::SCREEN_WIDTH, 
					jet::Application::SCREEN_HEIGHT / 2, 
					&lineColor
				);
			}

			application.renderScreen();
		}
	}

	stickTexture.free();
	backgroundTexture.free();
	jetTexture.free();

	application.close();

	return 0;
}
