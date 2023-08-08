#include "RenderingContext.h"

RenderingContext* RenderingContext_new(int width, int height, const char* title) {
	RenderingContext* context = malloc(sizeof(RenderingContext));
	SDL_assert_paranoid(context);

	context->_window = NULL;
	context->_renderer = NULL;

	SDL_CreateWindowAndRenderer(
		width, height,
		SDL_WINDOW_SHOWN,
		&context->_window,
		&context->_renderer
	);

	SDL_assert(context->_window);
	SDL_assert(context->_renderer);

	SDL_SetWindowTitle(context->_window, title);

	return context;
}

void RenderingContext_delete(RenderingContext* target) {
	SDL_DestroyWindow(target->_window);
	SDL_DestroyRenderer(target->_renderer);
	free(target);
}

void RenderingContext_renderSprite(RenderingContext* target, Sprite* sprite) {
	int err = SDL_RenderCopyF(
		target->_renderer,
		sprite->_texture,
		&sprite->_textureFrame,
		&sprite->_spriteFrame
	);
	SDL_assert(!err);
}

int RenderingContext_windowWidth(RenderingContext* target) {
	int* width = malloc(sizeof(int));
	SDL_assert_paranoid(width);

	SDL_GetWindowSize(target->_window, width, NULL);
	return *width;
}

int RenderingContext_windowHeight(RenderingContext* target) {
	int* height = malloc(sizeof(int));
	SDL_assert_paranoid(height);

	SDL_GetWindowSize(target->_window, NULL, height);
	return *height;
}
