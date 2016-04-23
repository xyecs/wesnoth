/*
 * fpscounter.cpp
 *
 *  Created on: 29/03/2016
 *      Author: andreas
 */

#include "fpscounter.hpp"

#include "SDL_timer.h"

fps_counter::fps_counter() : events::sdl_handler(false), last_sampled_(0),frames_(0),fps_(0)
{
	join_global();
}

fps_counter::~fps_counter() { }

void fps_counter::handle_event(const SDL_Event &event)
{
	if (event.type == DRAW_EVENT || event.type == DRAW_ALL_EVENT) {
		update_fps();
	}
}

void fps_counter::update_fps()
{
	++frames_;
	if (frames_ == sample_freq_) {
		int now = SDL_GetTicks();
		fps_ = (frames_ * 1000) / (now - last_sampled_);
		last_sampled_ = now;
		frames_ = 0;
	}
}
