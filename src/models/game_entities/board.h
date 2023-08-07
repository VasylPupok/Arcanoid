#pragma once

#include <graphics/sprite/sprite.h>

typedef enum {
	BOARD_NONE,
	BOARD_LEFT,
	BOARD_RIGHT
} BoardMoveDirection;

typedef struct {
	Sprite* _boardSprite;
	BoardMoveDirection _direction;
} Board;

Board* Board_new(const Sprite* boardSprite);

void Board_delete(Board* target);

void Board_move(Board* target, int delta_x, int delta_y);
void Board_move_to(Board* target, int x, int y);
