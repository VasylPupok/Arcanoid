#include <SDL.h>
#include <SDL_image.h>

#include <app/RenderingContext/RenderingContext.h>
#include <graphics/texture/texture.h>
#include <models/game_entities/board.h>
#include <app/Timer/Timer.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define FPS 60

int main(int argc, char** argv) {
	SDL_InitSubSystem(SDL_INIT_VIDEO);
	RenderingContext* app = RenderingContext_new(WINDOW_WIDTH, WINDOW_HEIGHT, "Arcanoid");

	SDL_Rect boardFrame = { 150, 105, WINDOW_WIDTH / 10, WINDOW_HEIGHT / 40 };
	Board* board = Board_new(Sprite_new(&boardFrame, loadTexture(app, "res/textures/51-Breakout-Tiles.png")));


	SDL_bool gameIsRunning = SDL_TRUE;
	SDL_Event event;

	Timer* renderTimer = Timer_new(1000 / FPS);
	Timer* updateTimer = Timer_new(1000 / FPS);


	Timer_start(renderTimer);
	Timer_start(updateTimer);
	while (gameIsRunning) {
		// update here
		if (Timer_endTime(updateTimer)) {
			Timer_reset(updateTimer);
			// update here
		}

		// render
		if (Timer_isEnd(renderTimer)) {
			Timer_reset(renderTimer);

			// render here
			RenderingContext_clearScreen(app);

			RenderingContext_renderSprite(app, board->_boardSprite);
			
			RenderingContext_display(app);
		}

		// handling user input
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				gameIsRunning = 0;
			default:
				break;
			}
		}
	}

	return 0;
}