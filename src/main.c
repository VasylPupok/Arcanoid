#include <SDL.h>
#include <SDL_image.h>

#include <app/RenderingContext/RenderingContext.h>
#include <graphics/texture/texture.h>
#include <models/game_entities/Board/board.h>
#include <app/time/time.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define FPS 60

int main(int argc, char** argv) {
	SDL_InitSubSystem(SDL_INIT_VIDEO);
	RenderingContext* app = RenderingContext_new(WINDOW_WIDTH, WINDOW_HEIGHT, "Arcanoid");

	SDL_FRect boardFrame = { WINDOW_WIDTH / 2.0 - WINDOW_WIDTH / 20, WINDOW_HEIGHT * 37.0 / 40, WINDOW_WIDTH / 10.0, WINDOW_HEIGHT / 40 };
	Board* board = Board_new(Sprite_new(&boardFrame, loadTexture(app, "res/textures/51-Breakout-Tiles.png")));


	SDL_bool gameIsRunning = SDL_TRUE;
	SDL_Event event;

	Timer* renderTimer = Timer_new(Time_SECOND / FPS * 2);
	Timer* updateTimer = Timer_new(Time_SECOND / FPS);

	float board_speed = (WINDOW_WIDTH * updateTimer->_time / (Time_SECOND * 1.0f));

	Timer_start(renderTimer);
	Timer_start(updateTimer);
	while (gameIsRunning) {

		// user input
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				gameIsRunning = 0;
			case SDL_KEYDOWN:
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT) {
					Board_moveLeft(board);
				} else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
					Board_moveRight(board);
				}
				break;
			case SDL_KEYUP:
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT) {
					Board_stopMovingLeft(board);
				} else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
					Board_stopMovingRight(board);
				}
			default:
				break;
			}
		}
		
		if (Timer_isEnd(updateTimer)) {
			Timer_reset(updateTimer);

			// update here
			if (board->_boardSprite->_spriteFrame.x > 0 && board->_direction == BOARD_LEFT) {
				Board_move(board, -board_speed, 0);
			} else if (board->_boardSprite->_spriteFrame.x < WINDOW_WIDTH * 9.0f / 10 && board->_direction == BOARD_RIGHT) {
				Board_move(board, board_speed, 0);
			}

			// update here
		}

		// render
		if (Timer_isEnd(renderTimer)) { // Timer_isEnd(renderTimer)
			Timer_reset(renderTimer);

			// render here
			RenderingContext_clearScreen(app);

			RenderingContext_renderSprite(app, board->_boardSprite);
			
			RenderingContext_display(app);
		}

	}

	return 0;
}