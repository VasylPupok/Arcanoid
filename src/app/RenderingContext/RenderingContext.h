#pragma once

#include <SDL.h>
#include <graphics/sprite/sprite.h>

typedef struct {
	SDL_Window* _window;
	SDL_Renderer* _renderer;
} RenderingContext;

RenderingContext* RenderingContext_new(int windowWidth, int windowHeight, const char* title);

void RenderingContext_delete(RenderingContext* target);

void RenderingContext_renderSprite(RenderingContext* target, Sprite* sprite);

inline void RenderingContext_display(RenderingContext* target) {
	SDL_RenderPresent(target->_renderer);
}

inline void RenderingContext_clearScreen(RenderingContext* target) {
	SDL_RenderClear(target->_renderer);
};

int RenderingContext_windowWidth(RenderingContext* target);

int RenderingContext_windowHeight(RenderingContext* target);

inline void RenderingContext_getWindowSize(RenderingContext* target, int* width, int* height) {
	SDL_GetWindowSize(target->_window, width, height);
}
