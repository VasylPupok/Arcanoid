#pragma once

#include <SDL_image.h>

typedef struct {
	SDL_FRect _spriteFrame;
	SDL_Rect _textureFrame;
	SDL_Texture* _texture;
} Sprite;

Sprite* Sprite_new(const SDL_FRect* spriteFrame, SDL_Texture* tex);

inline void Sprite_delete(Sprite* target) {
	free(target);
}

SDL_bool Sprite_containsPoint(const Sprite* sprite, float x, float y);
