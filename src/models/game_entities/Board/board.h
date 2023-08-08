#pragma once

#include <graphics/sprite/sprite.h>

typedef enum {
	BOARD_NONE = 0,
	BOARD_LEFT = 0b1,
	BOARD_RIGHT = 0b10,
	BOARD_LEFT_RIGHT_STALL = (BOARD_LEFT | BOARD_RIGHT)
} BoardMoveDirection;

typedef struct {
	Sprite* _boardSprite;
	BoardMoveDirection _direction;
} Board;

Board* Board_new(const Sprite* boardSprite);

void Board_delete(Board* target);

inline void Board_moveLeft(Board* target) {
	target->_direction |= BOARD_LEFT;
};
inline void Board_stopMovingLeft(Board* target) {
	target->_direction ^= BOARD_LEFT;
};
inline void Board_moveRight(Board* target) {
	target->_direction |= BOARD_RIGHT;
};
inline void Board_stopMovingRight(Board* target) {
	target->_direction ^= BOARD_RIGHT;
};


void Board_move(Board* target, float delta_x, float delta_y);
void Board_move_to(Board* target, float x, float y);
