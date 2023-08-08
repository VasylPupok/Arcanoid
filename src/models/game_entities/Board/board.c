#include "board.h"

Board* Board_new(const Sprite* boardSprite) {
	Board* board = malloc(sizeof(Board));
	SDL_assert_paranoid(board);

	board->_boardSprite = boardSprite;
	board->_direction = BOARD_NONE;
	return board;
}

void Board_delete(Board* target) {
	Sprite_delete(target->_boardSprite);
	free(target);
}

void Board_move(Board* target, float delta_x, float delta_y) {
	target->_boardSprite->_spriteFrame.x += delta_x;
	target->_boardSprite->_spriteFrame.y += delta_y;
}

void Board_move_to(Board* target, float x, float y) {
	target->_boardSprite->_spriteFrame.x = x;
	target->_boardSprite->_spriteFrame.y = y;
}
