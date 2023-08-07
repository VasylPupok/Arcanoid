#pragma once

typedef struct {
	size_t _time;
	size_t _startTime;
} Timer;

Timer* Timer_new(size_t time);

void Timer_start(Timer* timer);

void Timer_reset(Timer* timer);

int Timer_isEnd(Timer* timer);

inline size_t Timer_endTime(Timer* timer) {
	return timer->_startTime + timer->_time;
}
