#include <iostream>
#include <main.hpp>
#include <timer.hpp>


void Timer::init( float refresh_rate )
{
    fps = ( refresh_rate != TARGET_FPS ) ? TARGET_FPS : refresh_rate;
    tick_delay = to_seconds / static_cast<int>( fps );
}

void Timer::calc_DeltaTime()
{
    // Add guard when incase tick falls below zero
    Uint64 current_tick = GetTicks64();
    if ( last_frame_tick > 0 ) 
    {
        double elapsed = static_cast<double>( current_tick - last_frame_tick );
        delta_time = elapsed / to_seconds;
    }
    last_frame_tick = current_tick;
}

double Timer::deltaTime()
{
    return delta_time;
}

void Timer::frameLimiter()
{
    if ( last_frame_tick > 0 ) 
    {
        Uint64 timeleft = tick_delay - ( GetTicks64() - last_frame_tick );
        if ( timeleft <= tick_delay && timeleft > 0 ) {
            SDL_DelayPrecise( timeleft );
        }
    }
}