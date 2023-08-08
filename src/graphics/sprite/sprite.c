#include "sprite.h"

Sprite* Sprite_new(const SDL_FRect* spriteFrame, SDL_Texture* tex) {
    int width;
    int height;
    int querry_err = SDL_QueryTexture(tex, NULL, NULL, &width, &height);
    SDL_assert(!querry_err);

    Sprite* sprite = sprite = malloc(sizeof(Sprite));
    SDL_assert(sprite);

    sprite->_spriteFrame = *spriteFrame;
    SDL_Rect texFrame = { 0, 0, width, height };
    sprite->_textureFrame = texFrame;
    sprite->_texture = tex;
    return sprite;
}

SDL_bool Sprite_containsPoint(const Sprite* sprite, float x, float y) {
    return 
        sprite->_spriteFrame.x < x && x < sprite->_spriteFrame.x + sprite->_spriteFrame.w &&
        sprite->_spriteFrame.y < y && y < sprite->_spriteFrame.y + sprite->_spriteFrame.h;
}
