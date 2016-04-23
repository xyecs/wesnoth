/*
 * fpscounter.h
 *
 *  Created on: 29/03/2016
 *      Author: andreas
 */

#ifndef FPSCOUNTER_HPP_INCLUDED_
#define FPSCOUNTER_HPP_INCLUDED_

#include "events.hpp"

class fps_counter : events::sdl_handler
{
public:
	const static int sample_freq_ = 10;
	fps_counter();
	virtual ~fps_counter();
	virtual void handle_event(const SDL_Event &event);
	virtual void handle_window_event(const SDL_Event& ) {}
	int get_fps() { return fps_; }
	int get_sample_freq() { return sample_freq_; }
	int get_frames_sampled() { return frames_; }
private:
 	void update_fps();

	int last_sampled_;
	int frames_;
	int fps_;
};

#endif /* FPSCOUNTER_HPP_INCLUDED_ */
