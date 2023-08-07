#include "Timer.h"
#include <SDL.h>

Timer* Timer_new(size_t time) {
    Timer* timer = malloc(sizeof(Timer));
    SDL_assert_paranoid(timer);

    timer->_time = time;
    timer->_startTime = SDL_GetTicks64();

    return timer;
}

void Timer_start(Timer* timer) {
    timer->_startTime = SDL_GetTicks64();
}

void Timer_reset(Timer* timer) {
    timer->_startTime = SDL_GetTicks64();
}

int Timer_isEnd(Timer* timer) {
    return SDL_GetTicks64() > Timer_endTime(timer);
}
