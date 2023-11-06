#pragma once

#include <graphics/sprite/sprite.h>

typedef struct {
	SDL_Rect _bounds;
} Map;

typedef struct {
	Map* _parent;
	Sprite* _sprite;
} Actor;
